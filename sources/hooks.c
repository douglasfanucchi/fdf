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

int mlx_close_window(void *my_data)
{
    t_data  *data;

    data = my_data;
    mlx_destroy_window(data->mlx, data->window);
    return (1);
}

int mlx_handle_key_press(int keycode, void *my_data)
{
    if (keycode == ESC_KEYCODE)
        mlx_close_window(my_data);
    return (1);
}

void	register_hooks(t_data *data)
{
	mlx_key_hook(data->window, mlx_handle_key_press, data);
	mlx_loop_hook(data->mlx, mlx_render_map, data);
	mlx_hook(data->window, 17, 0, mlx_close_window, data);
}
