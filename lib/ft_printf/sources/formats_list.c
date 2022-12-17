/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_formats_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfanucch <dfanucch@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:01:37 by dfanucch          #+#    #+#             */
/*   Updated: 2022/10/05 23:01:37 by dfanucch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

t_list	**get_formats_list(void)
{
	t_list	**head;

	head = malloc(sizeof(t_list *));
	if (head)
	{
		*head = ft_lstnew(get_char_format());
		ft_lstadd_back(head, ft_lstnew(get_decimal_format()));
		ft_lstadd_back(head, ft_lstnew(get_hex_lower_format()));
		ft_lstadd_back(head, ft_lstnew(get_hex_upper_format()));
		ft_lstadd_back(head, ft_lstnew(get_integer_format()));
		ft_lstadd_back(head, ft_lstnew(get_percentage_format()));
		ft_lstadd_back(head, ft_lstnew(get_pointer_format()));
		ft_lstadd_back(head, ft_lstnew(get_str_format()));
		ft_lstadd_back(head, ft_lstnew(get_u_decimal_format()));
	}
	return (head);
}

t_data_format	*find_format_from_str_start(t_list **list, const char *str)
{
	t_list			*node;
	t_data_format	*data_format;

	if (*str != '%' || list == NULL)
		return (NULL);
	node = *list;
	while (node)
	{
		data_format = node->content;
		if (!ft_strncmp(data_format->id, str, ft_strlen(data_format->id)))
			return (data_format);
		node = node->next;
	}
	return (NULL);
}

void	del_data_formats(void *data_format)
{
	free(data_format);
}
