/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfanucch <dfanucch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:42:39 by dfanucch          #+#    #+#             */
/*   Updated: 2022/12/21 14:29:54 by dfanucch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

static char	to_lower(char hex)
{
	if (hex >= 'A' && hex <= 'Z')
		return (hex + 32);
	return (hex);
}

int	ft_atohex(char *hex)
{
	const char	*hex_digits;
	char		*current_digit;
	int			value;
	int			len;

	hex_digits = "0123456789abcdef";
	if (!ft_strncmp(hex, "0x", 2))
		hex += 2;
	len = ft_strlen(hex);
	value = 0;
	while (len > 0)
	{
		len--;
		current_digit = ft_strchr(hex_digits, to_lower(*hex));
		value += (current_digit - hex_digits) * pow(16, len);
		hex++;
	}
	return (value);
}
