/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_char_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfanucch <dfanucch@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 01:52:07 by dfanucch          #+#    #+#             */
/*   Updated: 2022/10/02 01:52:08 by dfanucch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void	*get_arg(va_list ap)
{
	char	*result;

	result = malloc(sizeof(char) * 2);
	if (result)
	{
		*result = (char) va_arg(ap, int);
		*(result + 1) = 0;
	}
	return (result);
}

static size_t	print(t_data_format *data_format, va_list ap)
{
	char	*arg;

	arg = data_format->get_arg(ap);
	write(1, arg, 1);
	free(arg);
	return (1);
}

t_data_format	*get_char_format(void)
{
	t_data_format	*data_format;

	data_format = (t_data_format *)malloc(sizeof(t_data_format));
	if (data_format)
	{
		data_format->id = "%c";
		data_format->get_arg = get_arg;
		data_format->print = print;
		data_format->formatter = NULL;
	}
	return (data_format);
}
