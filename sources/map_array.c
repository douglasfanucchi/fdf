/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfanucch <dfanucch@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 10:13:08 by dfanucch          #+#    #+#             */
/*   Updated: 2022/12/17 10:13:09 by dfanucch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static t_map_item	*new_map_item(char *item_info)
{
	t_map_item	*item;
	char		**info_splitted;

	item = malloc(sizeof(t_map_item));
	if (!item)
		return (NULL);
	info_splitted = ft_split(item_info, ',');
	item->height = ft_atoi(info_splitted[0]);
	item->color = NULL;
	if (info_splitted[1])
		item->color = info_splitted[1];
	free(info_splitted[0]);
	free(info_splitted);
	return (item);
}

static t_list	**new_map_columns(char *line)
{
	t_list		**map_columns;
	char		**columns;
	size_t		j;
	t_map_item	*item;

	map_columns = malloc(sizeof(t_list **));
	*map_columns = NULL;
	columns = ft_split(line, ' ');
	j = 0;
	while (columns[j])
	{
		item = new_map_item(columns[j]);
		ft_lstadd_back(map_columns, ft_lstnew(item));
		free(columns[j]);
		j++;
	}
	free(columns);
	return (map_columns);
}

static t_list	**map_parser(int fd)
{
	t_list		**map_array;
	t_list		**map_columns;
	char		*line;

	map_array = malloc(sizeof(t_list **));
	if (!map_array)
		return (NULL);
	*map_array = NULL;
	line = get_next_line(fd);
	while (line)
	{
		map_columns = new_map_columns(line);
		ft_lstadd_back(map_array, ft_lstnew(map_columns));
		free(line);
		line = get_next_line(fd);
	}
	return (map_array);
}

t_list	**get_map_array(char *filename)
{
	static t_list	**map_array;
	int				fd;

	if (!map_array)
	{
		fd = open(filename, O_RDONLY);
		if (fd == -1)
			return (NULL);
		map_array = map_parser(fd);
		close(fd);
	}
	return (map_array);
}
