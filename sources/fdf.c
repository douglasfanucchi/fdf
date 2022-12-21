#include <fdf.h>
#include <mlx.h>

void	mlx_put_pixel_img(t_img_data *data, int x, int y, int color)
{
	char	*dst;

	if (x > 1200 || x < 0 || y > 600 || y < 0)
		return;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main()
{
	void	*mlx;
	void	*window;
	t_img_data	img_data;

	mlx = mlx_init();
	window = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "FDF");
	img_data.img = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	img_data.addr = mlx_get_data_addr(img_data.img, &img_data.bits_per_pixel,
						&img_data.line_length, &img_data.endian);
	t_cartesian_map	*map = new_cartesian_map(*get_map_array("maps/42.fdf"), 50);
	t_list	*row = *map->rows;
	while (row)
	{
		t_list	*col = *((t_list **)row->content);
		t_list	*down_column = NULL;
		if (row->next)
			down_column = *((t_list **)row->next->content);
		while (col)
		{
			t_point	*point = (t_point *)col->content;
			if (col->next)
				mlx_draw_line(&img_data, *point, *((t_point *)col->next->content));
			if (down_column)
			{
				mlx_draw_line(&img_data, *point, *((t_point *)down_column->content));
				down_column = down_column->next;
			}
			col = col->next;
		}
		row = row->next;
	}

	mlx_put_image_to_window(mlx, window, img_data.img, 0, 0);
	mlx_loop(mlx);
}
