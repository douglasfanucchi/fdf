/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_decimal_format.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfanucch <dfanucch@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:43:53 by dfanucch          #+#    #+#             */
/*   Updated: 2022/10/04 14:43:53 by dfanucch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static char	*formatter(void *data)
{
	int	*integer_data;

	integer_data = data;
	return (ft_itoa(*integer_data));
}

static void	*get_arg(va_list ap)
{
	int	*result;

	result = malloc(sizeof(int));
	if (result)
		*result = va_arg(ap, int);
	return (result);
}

static size_t	print(t_data_format *data_format, va_list ap)
{
	char	*arg;
	char	*formatted;
	size_t	len;

	arg = data_format->get_arg(ap);
	formatted = data_format->formatter(arg);
	ft_putstr(formatted);
	len = ft_strlen(formatted);
	free(arg);
	free(formatted);
	return (len);
}

t_data_format	*get_decimal_format(void)
{
	t_data_format	*data_format;

	data_format = malloc(sizeof(t_data_format));
	if (data_format)
	{
		data_format->id = "%d";
		data_format->formatter = formatter;
		data_format->get_arg = get_arg;
		data_format->print = print;
	}
	return (data_format);
}
