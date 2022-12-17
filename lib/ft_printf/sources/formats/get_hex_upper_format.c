/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hex_upper_format.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfanucch <dfanucch@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 12:44:15 by dfanucch          #+#    #+#             */
/*   Updated: 2022/10/04 12:44:15 by dfanucch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static char	*formatter(void *data)
{
	unsigned int			*unsigned_data;
	t_hex_base_converter	*converter;
	char					*result;

	result = NULL;
	converter = get_hex_base_converter();
	unsigned_data = data;
	if (converter)
		result = converter->convert(*unsigned_data,
				converter->hex_upper_digits);
	free(converter);
	return (result);
}

t_data_format	*get_hex_upper_format(void)
{
	t_data_format	*data_format;

	data_format = get_hex_lower_format();
	if (data_format)
	{
		data_format->id = "%X";
		data_format->formatter = formatter;
	}
	return (data_format);
}
