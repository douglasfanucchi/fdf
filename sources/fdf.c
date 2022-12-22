/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfanucch <dfanucch@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 11:46:36 by dfanucch          #+#    #+#             */
/*   Updated: 2022/12/22 11:46:36 by dfanucch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_printf("Error: Invalid parameters.\n");
		return (1);
	}
	data.mlx = mlx_init();
	data.window = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "FDF");
	data.map_name = argv[1];
	register_hooks(&data);
	mlx_loop(data.mlx);
	return (0);
}
