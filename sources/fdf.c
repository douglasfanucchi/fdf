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
	window = mlx_new_window(mlx, 1200, 600, "Hello World");
	img_data.img = mlx_new_image(mlx, 1200, 600);
	img_data.addr = mlx_get_data_addr(img_data.img, &img_data.bits_per_pixel,
						&img_data.line_length, &img_data.endian);
	// clock_t begin = clock();
	t_list **map_array = get_map_array("maps/42.fdf");
	t_list *row = *map_array;
	int y = 0;
	int	space = 20;
	while (row)
	{
		int x = 0;
		t_list *next_row = row->next;
		t_list *col = *((t_list **)row->content);
		t_list *down_col = NULL;
		if (next_row)
			down_col = *((t_list **)next_row->content);
		while (col)
		{
			t_map_item *item = col->content;
			t_map_item *right_item = NULL;
			t_map_item *down_item = NULL;
			int x1 = space * x;
			int y1 = space * y;
			int x2;
			int y2;
			int mx = 400;
			int my = 50;
			int color = 0x00FFFFFF;
			t_point	*p1 = new_point(x1, y1, color);
			isometric_projection(p1, item->height);
			p1->x += mx;
			p1->y += my;
			t_point	*p2 = NULL;
			if (col->next)
			{
				x2 = x1 + space;
				y2 = y1;
				right_item = col->next->content;
				p2 = new_point(x2, y2, color);
				isometric_projection(p2, right_item->height);
				p2->x += mx;
				p2->y += my;
				if (right_item->color)
					color = strtol(right_item->color, NULL, 0);
				mlx_draw_line(&img_data, *p1, *p2);
			}
			if (down_col)
			{
				x2 = x1;
				y2 = y1 + space;
				down_item = down_col->content;
				p2 = new_point(x2, y2, color);
				isometric_projection(p2, down_item->height);
				p2->x += mx;
				p2->y += my;
				if (down_item->color)
					color = strtol(down_item->color, NULL, 0);
				mlx_draw_line(&img_data, *p1, *p2);
			}
			col = col->next;
			if (down_col)
				down_col = down_col->next;
			x++;
		}
		row = row->next;
		y++;
	}
	free(map_array);
	// clock_t end = clock();
	// double time_spent = (double)(end - begin);

	mlx_put_image_to_window(mlx, window, img_data.img, 0, 0);
	mlx_loop(mlx);
}
