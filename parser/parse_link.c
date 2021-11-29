/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilverb <csilverb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 16:37:33 by csilverb          #+#    #+#             */
/*   Updated: 2021/03/22 22:14:48 by csilverb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

static char		*check_link(char *field, char *string)
{
	char	*link;
	int		fd;

	if (!(link = ft_strtrim(string + 2, " ")))
		error_handler(43);
	if ((fd = open(link, O_RDONLY)) == -1)
		link = NULL;
	else if (field != NULL)
		error_handler(38);
	close(fd);
	return (link);
}

void			parse_link(t_parse *parse, char *string)
{
	char	*link;

	link = NULL;
	if (ft_strnstr(string, "NO", 2) == &string[0]
	&& (link = check_link(parse->n_text, string)))
		parse->n_text = link;
	else if (ft_strnstr(string, "SO", 2) == &string[0]
	&& (link = check_link(parse->s_text, string)))
		parse->s_text = link;
	else if (ft_strnstr(string, "WE", 2) == &string[0]
	&& (link = check_link(parse->w_text, string)))
		parse->w_text = link;
	else if (ft_strnstr(string, "EA", 2) == &string[0]
	&& (link = check_link(parse->e_text, string)))
		parse->e_text = link;
	else if (ft_strnstr(string, "S ", 2) == &string[0]
	&& (link = check_link(parse->sp_text, string)))
		parse->sp_text = link;
	if (link == NULL)
		error_handler(38);
}
