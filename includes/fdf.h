/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfanucch <dfanucch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 10:14:50 by dfanucch          #+#    #+#             */
/*   Updated: 2022/12/21 17:28:13 by dfanucch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <libft.h>
# include <ft_printf.h>
# include <mlx.h>
# include <math.h>
# include <string.h>
# include <errno.h>
# include <stdio.h>

# define WIN_WIDTH 1200
# define WIN_HEIGHT 600
# define ESC_KEYCODE 65307
# define H_KEYCODE 104
# define J_KEYCODE 106
# define K_KEYCODE 107
# define L_KEYCODE 108
# define PLUS_KEYCODE 61
# define MINUS_KEYCODE 45

typedef struct s_map_item {
	char	*color;
	int		height;
}	t_map_item;

typedef struct s_cartesian_map {
	int		x_min;
	int		x_max;
	int		y_min;
	int		y_max;
	int		width;
	int		height;
	double	scale;
	t_list	**rows;
}	t_cartesian_map;

typedef struct s_point {
	int	x;
	int	y;
	int	color;
}	t_point;

typedef struct s_data {
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	void			*window;
	void			*mlx;
	t_cartesian_map	*map;
	char			*map_name;
}	t_data;

typedef struct s_map_array {
	t_list	**map;
	int		rows;
	int		cols;
}	t_map_array;

t_map_array		*get_map_array(char *filename);
void			mlx_draw_line(t_data *data, t_point p1, t_point p2);
t_point			*new_point(int x, int y, int color);
void			del_point(t_point *point);
void			isometric_projection(t_point *point, int height);
t_cartesian_map	*new_cartesian_map(t_list **row, double scale);
int 			mlx_handle_key_press(int keycode, void *my_data);
int 			mlx_close_window(void *my_data);
int				mlx_render_frame(void *my_data);
void			register_hooks(t_data *data);
int				mlx_draw_map(t_data *data);
void			mlx_destroy_map_array(t_list **rows);

#endif
