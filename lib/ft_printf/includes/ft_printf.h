/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfanucch <dfanucch@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:48:33 by dfanucch          #+#    #+#             */
/*   Updated: 2022/10/01 16:48:34 by dfanucch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <libft.h>

struct	s_data_format {
	char	*id;
	char	*(*formatter)(void *);
	void	*(*get_arg)(va_list);
	size_t	((*print)(struct s_data_format *, va_list));
};

typedef struct s_data_format	t_data_format;

typedef struct s_hex_base_converter {
	char	*hex_upper_digits;
	char	*hex_lower_digits;
	char	*(*convert)(unsigned long, char *);
}	t_hex_base_converter;

t_data_format			*get_char_format(void);
t_data_format			*get_str_format(void);
t_data_format			*get_hex_lower_format(void);
t_data_format			*get_hex_upper_format(void);
t_data_format			*get_pointer_format(void);
t_data_format			*get_decimal_format(void);
t_data_format			*get_integer_format(void);
t_data_format			*get_u_decimal_format(void);
t_data_format			*get_percentage_format(void);
t_hex_base_converter	*get_hex_base_converter(void);
t_list					**get_formats_list(void);
t_data_format			*find_format_from_str_start(
							t_list **list,
							const char *str);
void					del_data_formats(void *data_format);
int						ft_printf(const char *str, ...);
#endif
