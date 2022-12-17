/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_percentage_format.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfanucch <dfanucch@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:28:55 by dfanucch          #+#    #+#             */
/*   Updated: 2022/10/04 16:28:56 by dfanucch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static size_t	print(t_data_format *data_format, va_list ap)
{
	char	c;

	if (!data_format && !ap)
		return (0);
	c = '%';
	write(1, &c, 1);
	return (1);
}

t_data_format	*get_percentage_format(void)
{
	t_data_format	*data_format;

	data_format = malloc(sizeof(t_data_format));
	if (data_format)
	{
		data_format->id = "%%";
		data_format->print = print;
		data_format->formatter = NULL;
		data_format->get_arg = NULL;
	}
	return (data_format);
}
