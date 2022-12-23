/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfanucch <dfanucch@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 22:27:50 by dfanucch          #+#    #+#             */
/*   Updated: 2022/12/22 22:27:50 by dfanucch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void	mlx_free_map_array_item(void *content)
{
	t_map_item	*item;

	item = content;
	free(item->color);
	free(item);
}

static void	del_columns(void *content)
{
	t_list	**columns;

	columns = content;
	ft_lstclear(columns, mlx_free_map_array_item);
}

void	mlx_destroy_map_array(t_list **rows)
{
	ft_lstclear(rows, del_columns);
}
