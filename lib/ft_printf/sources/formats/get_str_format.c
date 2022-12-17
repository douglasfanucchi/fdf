/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfanucch <dfanucch@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 02:10:54 by dfanucch          #+#    #+#             */
/*   Updated: 2022/10/02 02:10:54 by dfanucch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void	*get_arg(va_list ap)
{
	char	*arg;

	arg = va_arg(ap, char *);
	if (!arg)
		return (ft_strdup("(null)"));
	return (ft_strdup(arg));
}

static size_t	print(t_data_format *data_format, va_list ap)
{
	char	*arg;
	size_t	len;

	len = 0;
	arg = data_format->get_arg(ap);
	if (arg != NULL)
	{
		ft_putstr(arg);
		len = ft_strlen(arg);
	}
	free(arg);
	return (len);
}

t_data_format	*get_str_format(void)
{
	t_data_format	*data_format;

	data_format = (t_data_format *)malloc(sizeof(t_data_format));
	if (data_format)
	{
		data_format->id = "%s";
		data_format->get_arg = get_arg;
		data_format->print = print;
		data_format->formatter = NULL;
	}
	return (data_format);
}
