/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pointer_format.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfanucch <dfanucch@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:15:23 by dfanucch          #+#    #+#             */
/*   Updated: 2022/10/04 13:15:23 by dfanucch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static char	*formatter(void *data)
{
	t_hex_base_converter	*converter;
	char					*prefix;
	char					*hex;
	char					*result;
	unsigned long			*unsigned_data;

	unsigned_data = data;
	result = NULL;
	if (*unsigned_data == 0)
		return (ft_strdup("(nil)"));
	converter = get_hex_base_converter();
	if (converter)
	{
		prefix = ft_strdup("0x");
		hex = converter->convert(
				*unsigned_data,
				converter->hex_lower_digits);
		result = ft_strjoin(prefix, hex);
		free(prefix);
		free(hex);
		free(converter);
	}
	return (result);
}

static void	*get_arg(va_list ap)
{
	unsigned long	*result;

	result = malloc(sizeof(unsigned long));
	if (result)
		*result = va_arg(ap, unsigned long);
	return (result);
}

t_data_format	*get_pointer_format(void)
{
	t_data_format	*data_format;

	data_format = get_hex_lower_format();
	if (data_format)
	{
		data_format->id = "%p";
		data_format->formatter = formatter;
		data_format->get_arg = get_arg;
	}
	return (data_format);
}
