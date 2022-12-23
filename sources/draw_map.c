/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfanucch <dfanucch@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 11:44:32 by dfanucch          #+#    #+#             */
/*   Updated: 2022/12/22 11:44:33 by dfanucch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void	del_columns(void *columns)
{
	ft_lstclear((t_list **)columns, free);
}

static void	mlx_destroy_cartesian_map(t_cartesian_map *map)
{
	if (!map)
		return ;
	ft_lstclear(map->rows, del_columns);
	free(map);
}

static t_cartesian_map	*get_cartesian_map(char *map_name)
{
	t_map_array	*map_array;
	int			scale;
	int			cols_square;
	int			rows_square;

	map_array = get_map_array(map_name);
	if (!map_array)
		return (NULL);
	cols_square = pow(map_array->cols, 2);
	rows_square = pow(map_array->rows, 2);
	scale = WIN_HEIGHT / sqrt(cols_square + rows_square);
	return (new_cartesian_map(map_array->map, scale));
}

static void	mlx_draw_columns(t_data *data, t_list *column, t_list *down_column)
{
	t_point	*p1;
	t_point	*p2;

	while (column)
	{
		p1 = (t_point *)column->content;
		if (column->next)
		{
			p2 = (t_point *)(column->next->content);
			mlx_draw_line(data, *p1, *p2);
		}
		if (down_column)
		{
			p2 = (t_point *)(down_column->content);
			mlx_draw_line(data, *p1, *p2);
			down_column = down_column->next;
		}
		column = column->next;
	}
}

int	mlx_draw_map(t_data *data)
{
	t_cartesian_map	*map;
	t_list			*row;
	t_list			*col;
	t_list			*down_col;

	map = get_cartesian_map(data->map_name);
	if (!map)
		return (1);
	row = *map->rows;
	col = NULL;
	down_col = NULL;
	while (row)
	{
		col = *((t_list **)row->content);
		if (row->next)
			down_col = *((t_list **)row->next->content);
		mlx_draw_columns(data, col, down_col);
		row = row->next;
	}
	mlx_destroy_cartesian_map(map);
	return (0);
}
