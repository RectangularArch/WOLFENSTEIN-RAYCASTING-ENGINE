/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilverb <csilverb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:43:58 by csilverb          #+#    #+#             */
/*   Updated: 2021/03/23 21:54:36 by csilverb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

void		ft_is_sprite(char **map, t_main *main_temp)
{
	int k;
	int i;
	int s;

	i = 0;
	s = 0;
	while (map[i] != NULL)
	{
		k = -1;
		while (map[i][++k] != '\0')
		{
			if (map[i][k] == '2')
			{
				main_temp->parsed->sprites[s].x = k;
				main_temp->parsed->sprites[s].y = i;
				s++;
			}
		}
		i++;
	}
}

t_main		*main_temp_malloc(t_main *main_temp)
{
	t_main *temp;

	if (!(temp = (t_main *)malloc(1 * sizeof(t_main)))
	|| !(temp->parsed = (t_parse *)malloc(1 * sizeof(t_parse)))
	|| !(temp->p = (t_player *)malloc(1 * sizeof(t_player)))
	|| !(temp->window = (t_win *)malloc(1 * sizeof(t_win)))
	|| !(temp->txts = (t_text *)malloc(1 * sizeof(t_text))))
		error_handler(43);
	ft_memset(temp->parsed, 0, sizeof(t_parse));
	ft_memset(temp->p, 0, sizeof(t_player));
	ft_memset(temp->window, 0, sizeof(t_win));
	ft_memset(temp->txts, 0, sizeof(t_text));
	main_temp = temp;
	return (main_temp);
}

char		**make_map(t_list **head, int size)
{
	char	**map;
	int		i;
	t_list	*tmp;

	i = -1;
	tmp = *head;
	if (!(map = ft_calloc(size + 1, sizeof(char *))))
		error_handler(43);
	while (tmp)
	{
		map[++i] = tmp->content;
		tmp = tmp->next;
	}
	return (map);
}

t_list		*fill_list(int fd, t_list *head)
{
	char	*line;

	line = NULL;
	while (get_next_line(fd, &line))
		ft_lstadd_back(&head, ft_lstnew(line));
	ft_lstadd_back(&head, ft_lstnew(line));
	return (head);
}
