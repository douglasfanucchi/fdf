/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_base.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfanucch <dfanucch@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 12:30:26 by dfanucch          #+#    #+#             */
/*   Updated: 2022/10/02 12:30:27 by dfanucch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static size_t	nlen(unsigned long n)
{
	size_t	len;

	len = 1;
	while (n / 16)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static char	*convert(unsigned long n, char *digits)
{
	char	*result;
	size_t	result_len;
	size_t	i;

	result_len = 1;
	i = 0;
	result_len = nlen(n);
	result = malloc((result_len + 1) * sizeof(char));
	if (result)
	{
		result[result_len] = 0;
		while (n / 16)
		{
			result[result_len - 1 - i++] = digits[n % 16];
			n /= 16;
		}
		result[result_len - 1 - i] = digits[n % 16];
	}
	return (result);
}

t_hex_base_converter	*get_hex_base_converter(void)
{
	t_hex_base_converter	*converter;

	converter = malloc(sizeof(t_hex_base_converter));
	if (converter)
	{
		converter->hex_lower_digits = "0123456789abcdef";
		converter->hex_upper_digits = "0123456789ABCDEF";
		converter->convert = convert;
	}
	return (converter);
}
