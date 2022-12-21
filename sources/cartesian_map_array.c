/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cartesian_map_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfanucch <dfanucch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:36:25 by dfanucch          #+#    #+#             */
/*   Updated: 2022/12/21 14:33:51 by dfanucch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void	update_dimension_value(t_point *point, t_cartesian_map *cartesian)
{
	if (point->x > cartesian->x_max)
		cartesian->x_max = point->x;
	if (point->x < cartesian->x_min)
		cartesian->x_min = point->x;
	if (point->y > cartesian->y_max)
		cartesian->y_max = point->y;
	if (point->y < cartesian->y_min)
		cartesian->y_min = point->y;
	cartesian->width = cartesian->x_max - cartesian->x_min;
	cartesian->height = cartesian->y_max - cartesian->y_min;
}

static t_list	**get_cartesian_cols(t_list *col, t_cartesian_map *map, int y)
{
	t_list		**cartesian_cols;
	t_map_item	*item;
	int			x;
	t_point		*point;
	int			color;

	color = 0x0FFFFFF;
	x = 0;
	cartesian_cols = ft_newlist();
	while (col)
	{
		item = (t_map_item *)col->content;
		if (item->color)
			color = ft_atohex(item->color);
		point = new_point(x, y, color);
		point->x *= map->scale;
		point->y *= map->scale;
		isometric_projection(point, item->height);
		update_dimension_value(point, map);
		ft_lstadd_back(cartesian_cols, ft_lstnew(point));
		col = col->next;
		x++;
	}
	return (cartesian_cols);
}

static t_list	**get_cartesian_rows(t_list *row, t_cartesian_map *map)
{
	t_list	**cartesian_rows;
	t_list	**cartesian_columns;
	t_list	*column;
	int		y;

	cartesian_rows = ft_newlist();
	y = 0;
	while (row)
	{
		column = *((t_list **)row->content);
		cartesian_columns = get_cartesian_cols(column, map, y);
		ft_lstadd_back(cartesian_rows, ft_lstnew(cartesian_columns));
		row = row->next;
		y++;
	}
	return (cartesian_rows);
}

static void	move_map_to_center(t_cartesian_map *map)
{
	int		mx;
	int		my;
	t_list	*row;
	t_list	*column;
	t_point	*point;

	mx = WIN_WIDTH / 2 - (map->x_max - map->width / 2);
	my = WIN_HEIGHT / 2 - (map->y_max - map->height / 2);
	row = *map->rows;
	while (row)
	{
		column = *((t_list **)row->content);
		while (column)
		{
			point = column->content;
			point->x += mx;
			point->y += my;
			column = column->next;
		}
		row = row->next;
	}
}

t_cartesian_map	*new_cartesian_map(t_list *row, int scale)
{
	t_cartesian_map	*cartesian_map;

	cartesian_map = malloc(sizeof(t_cartesian_map));
	if (!cartesian_map)
		return (NULL);
	cartesian_map->x_min = 0;
	cartesian_map->x_max = 0;
	cartesian_map->y_min = 0;
	cartesian_map->y_max = 0;
	cartesian_map->scale = scale;
	cartesian_map->rows = get_cartesian_rows(row, cartesian_map);
	move_map_to_center(cartesian_map);
	return (cartesian_map);
}
