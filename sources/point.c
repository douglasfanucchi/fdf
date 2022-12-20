/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfanucch <dfanucch@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 23:20:22 by dfanucch          #+#    #+#             */
/*   Updated: 2022/12/19 23:20:23 by dfanucch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_point	*new_point(int x, int y, int color)
{
	t_point	*point;

	point = malloc(sizeof(t_point));
	if (!point)
		return (NULL);
	point->x = x;
	point->y = y;
	point->color = color;
	return (point);
}

void	del_point(t_point *point)
{
	free(point);
}
