/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfanucch <dfanucch@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 10:14:50 by dfanucch          #+#    #+#             */
/*   Updated: 2022/12/17 10:14:50 by dfanucch         ###   ########.fr       */
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
# include <math.h>

typedef struct s_map_item {
	char	*color;
	int		height;
}	t_map_item;

typedef struct s_point {
	int	x;
	int	y;
	int	color;
}	t_point;

typedef struct s_img_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img_data;

t_list	**get_map_array(char *filename);
void	mlx_put_pixel_img(t_img_data *data, int x, int y, int color);
void	mlx_draw_line(t_img_data *data, t_point p1, t_point p2);
t_point	*new_point(int x, int y, int color);
void	del_point(t_point *point);
void	isometric_projection(t_point *point, int height);

#endif
