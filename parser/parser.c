/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilverb <csilverb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 17:35:10 by csilverb          #+#    #+#             */
/*   Updated: 2021/03/25 00:27:53 by csilverb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

static void			is_simple(char **map)
{
	int i;

	i = -1;
	if (ft_strchr("\n", map[0][0]))
		error_handler(41);
	while (map[++i])
	{
		if (!ft_strchr("RNSWEFC 1\n", map[i][0]))
			error_handler(41);
	}
}

static void			parse_links(char *str, char **map, t_main *main_temp, int i)
{
	const char	*link_marks[6] = {"NO ", "SO ", "WE ", "EA ", "S ", "\0"};
	int			count;
	int			l;

	count = 3;
	l = -1;
	if (!ft_strchr("NSWE", str[0]))
		error_handler(41);
	while (++l <= 5 && map[i][0] != '\0')
	{
		if (l == 5)
			error_handler(41);
		if (l == 4)
			count = 2;
		if (ft_strnstr(str, link_marks[l], count) == &str[0])
		{
			main_temp->parsed->args++;
			parse_link(main_temp->parsed, str);
			break ;
		}
	}
}

static int			parse_data(char **map, t_main *main_temp, int i)
{
	char		*str;

	while (map[++i] != NULL && main_temp->parsed->args < 9)
	{
		if (!(str = ft_strtrim(map[i], " ")))
			error_handler(43);
		if (ft_strnstr(str, "R ", 2) == &str[0])
		{
			main_temp->parsed->args++;
			parse_resolution(main_temp->parsed, str);
		}
		else if (ft_strnstr(str, "F ", 2) == &str[0]
		|| ft_strnstr(str, "C ", 2) == &str[0])
			parse_rgb(main_temp->parsed, str);
		else if (map[i][0] != '\0' && main_temp->parsed->args == 8)
			parse_map(main_temp->p, main_temp->parsed, map, i);
		else
			parse_links(str, map, main_temp, i);
		if (str)
			free(str);
	}
	return (main_temp->parsed->args);
}

t_main				*parser(char **map)
{
	t_main		*main_temp;

	main_temp = NULL;
	is_simple(map);
	main_temp = main_temp_malloc(main_temp);
	main_temp->parsed->args = parse_data(map, main_temp, -1);
	if (main_temp->parsed->cl_map == NULL)
		error_handler(37);
	if (!(main_temp->parsed->sprites =
	(t_sprite *)malloc(main_temp->parsed->sp_count * sizeof(t_sprite))))
		error_handler(43);
	ft_is_sprite(main_temp->parsed->cl_map, main_temp);
	if (main_temp->parsed->args < 9)
		return (NULL);
	return (main_temp);
}
