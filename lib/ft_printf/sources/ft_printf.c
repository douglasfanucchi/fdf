/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfanucch <dfanucch@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:05:02 by dfanucch          #+#    #+#             */
/*   Updated: 2022/10/06 13:05:02 by dfanucch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	ft_printf(const char *str, ...)
{
	t_list			**formats;
	t_data_format	*data_format;
	va_list			ap;
	int				len;

	len = 0;
	va_start(ap, str);
	formats = get_formats_list();
	while (*str)
	{
		data_format = find_format_from_str_start(formats, str);
		if (data_format)
		{
			len += data_format->print(data_format, ap);
			str += ft_strlen(data_format->id);
			continue ;
		}
		write(1, str++, 1);
		len++;
		if (*(str - 1) == '%' && *str == 0)
			len = -1;
	}
	ft_lstclear(formats, del_data_formats);
	free(formats);
	va_end(ap);
	return (len);
}
