/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_integer_format.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfanucch <dfanucch@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:21:59 by dfanucch          #+#    #+#             */
/*   Updated: 2022/10/04 15:22:00 by dfanucch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

t_data_format	*get_integer_format(void)
{
	t_data_format	*data_format;

	data_format = get_decimal_format();
	if (data_format)
		data_format->id = "%i";
	return (data_format);
}
