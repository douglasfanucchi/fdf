/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfanucch <dfanucch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:59:56 by dfanucch          #+#    #+#             */
/*   Updated: 2022/12/21 17:06:16 by dfanucch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	mlx_close_window(void *my_data)
{
	t_data		*data;
	t_map_array	*map_array;

	data = my_data;
	map_array = get_map_array(data->map_name);
	if (map_array)
		mlx_destroy_map_array(map_array->map);
	mlx_destroy_window(data->mlx, data->window);
	mlx_loop_end(data->mlx);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free(map_array);
	exit(0);
}

int	mlx_handle_key_press(int keycode, void *my_data)
{
	if (keycode == ESC_KEYCODE)
		mlx_close_window(my_data);
	return (1);
}

int	mlx_render_frame(void *my_data)
{
	t_data	*data;
	int		error;

	data = my_data;
	data->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	error = mlx_draw_map(data);
	if (error)
	{
		ft_printf("Error: %s\n", strerror(errno));
		mlx_destroy_image(data->mlx, data->img);
		mlx_close_window(data);
		return (1);
	}
	mlx_put_image_to_window(data->mlx, data->window, data->img, 0, 0);
	mlx_destroy_image(data->mlx, data->img);
	return (0);
}

void	register_hooks(t_data *data)
{
	mlx_key_hook(data->window, mlx_handle_key_press, data);
	mlx_loop_hook(data->mlx, mlx_render_frame, data);
	mlx_hook(data->window, 17, 0, mlx_close_window, data);
}
