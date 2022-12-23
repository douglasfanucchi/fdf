/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfanucch <dfanucch@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 22:52:29 by dfanucch          #+#    #+#             */
/*   Updated: 2022/12/19 22:52:29 by dfanucch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	rotate_about_x(double angle, t_point *p, int z)
{
	p->y = cos(angle) * p->y - sin(angle) * z;
}

void	rotate_about_y(double angle, t_point *p, int z)
{
	p->x = cos(angle) * p->x + sin(angle) * z;
}

void	rotate_about_z(double angle, t_point *p)
{
	int	tmp_x;

	tmp_x = cos(angle) * p->x - sin(angle) * p->y;
	p->y = sin(angle) * p->x + cos(angle) * p->y;
	p->x = tmp_x;
}

void	isometric_projection(t_point *point, int height)
{
	rotate_about_z(M_PI_4, point);
	rotate_about_x(atan(M_SQRT2), point, height);
}
