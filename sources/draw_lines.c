#include <fdf.h>
#include <stdio.h>

void	mlx_draw_line_low(t_img_data *data, int i0, int d0, int i1, int d1, int color)
{
	int	dd;
	int	di;
	int	step;
	int	e;

	dd = d1 - d0;
	di = i1 - i0;
	step = 1;
	e = 0;
	if (dd < 0)
	{
		step = -1;
		dd *= -1;
	}
	mlx_put_pixel_img(data, i0, d0, color);
	while (i0 <= i1)
	{
		i0++;
		e += 2*dd;
		if (e >= 2*di)
		{
			d0+=step;
			e -= 2*di;
		}
		ft_printf("(%d, %d)\n", i0, d0);
		mlx_put_pixel_img(data, i0, d0, color);
	}
}

void	mlx_draw_line_high(t_img_data *data, int i0, int d0, int i1, int d1, int color)
{
	int	dd;
	int	di;
	int	step;
	int	e;

	dd = d1 - d0;
	di = i1 - i0;
	step = 1;
	e = 0;
	if (dd < 0)
	{
		step = -1;
		dd *= -1;
	}
	mlx_put_pixel_img(data, i0, d0, color);
	while (d0 != d1)
	{
		d0+=step;
		e += 2*di;
		if (e >= 2*dd)
		{
			i0++;
			e -= 2*dd;
		}
		ft_printf("(%d, %d)\n", i0, d0);
		mlx_put_pixel_img(data, i0, d0, color);
	}
}

void	mlx_draw_line(t_img_data *data, int i0, int d0, int i1, int d1, int color)
{
	int		dd;
	int		di;
	int		tmp;

	if (i0 > i1)
	{
		tmp = i0;
		i0 = i1;
		i1 = tmp;
		tmp = d0;
		d0 = d1;
		d1 = tmp;
	}
	di = i1 - i0;
	dd = d1 - d0;
	if (abs(dd) > abs(di))
		return mlx_draw_line_high(data, i0, d0, i1, d1, color);
	mlx_draw_line_low(data, i0, d0, i1, d1, color);
}

t_point	*rotate(int x, int y, int z)
{
	t_point	*point;
	double	angle;

	point = malloc(sizeof(t_point));
	angle = 45 * M_PI / 180;
	point->x = cos(angle) * x - sin(angle) * y;
	point->y = sin(angle) * x + cos(angle) * y;
	angle = atan(M_SQRT2);
	point->y = cos(angle) * point->y - sin(angle) * z;
	return (point);
}
