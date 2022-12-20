/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfanucch <dfanucch@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 22:52:56 by dfanucch          #+#    #+#             */
/*   Updated: 2022/12/19 22:52:57 by dfanucch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	mlx_draw_line_low(t_img_data *data, t_point p1, t_point p2, int color)
{
	int	dy;
	int	dx;
	int	step;
	int	e;

	dy = p2.y - p1.y;
	dx = p2.x - p1.x;
	step = 1;
	e = 0;
	if (dy < 0)
	{
		step = -1;
		dy *= -1;
	}
	while (p1.x <= p2.x)
	{
		mlx_put_pixel_img(data, p1.x++, p1.y, color);
		e += 2 * dy;
		if (e >= 2 * dx)
		{
			p1.y += step;
			e -= 2 * dx;
		}
	}
}

void	mlx_draw_line_high(t_img_data *data, t_point p1, t_point p2, int color)
{
	int	dx;
	int	dy;
	int	step;
	int	e;

	dy = p2.y - p1.y;
	dx = p2.x - p1.x;
	step = 1;
	e = 0;
	if (dy < 0)
	{
		step = -1;
		dy *= -1;
	}
	while (p1.y != p2.y)
	{
		mlx_put_pixel_img(data, p1.x, p1.y, color);
		p1.y += step;
		e += 2 * dx;
		if (e >= 2 * dy)
		{
			p1.x++;
			e -= 2 * dy;
		}
	}
}

void	mlx_draw_line(t_img_data *data, t_point p1, t_point p2, int color)
{
	int		dy;
	int		dx;
	t_point	tmp;

	if (p1.x > p2.x)
	{
		tmp = p1;
		p1 = p2;
		p2 = tmp;
	}
	dy = p2.y - p1.y;
	dx = p2.x - p1.x;
	if (abs(dy) > abs(dx))
		mlx_draw_line_high(data, p1, p2, color);
	else
		mlx_draw_line_low(data, p1, p2, color);
}