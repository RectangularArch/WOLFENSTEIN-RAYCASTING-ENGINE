/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilverb <csilverb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 14:25:16 by csilverb          #+#    #+#             */
/*   Updated: 2021/03/25 00:50:12 by csilverb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

static int		map_len(char **map)
{
	int i;
	int len;

	len = 0;
	i = -1;
	while (map[++i] != '\0')
	{
		if (len < (int)ft_strlen(map[i]))
			len = ft_strlen(map[i]);
	}
	return (len);
}

static int		map_width(char **map, int i)
{
	int width;
	int w;

	w = i;
	while (map[i] != '\0')
	{
		i++;
	}
	width = i - w;
	return (width);
}

static void		add_space(t_parse *parse, char **map, int l, int k)
{
	if (k < map_len(map))
		while (k != map_len(map))
		{
			parse->cl_map[l][k] = ' ';
			k++;
		}
}

static void		is_error(int str_count, t_parse *parse)
{
	if (str_count == 0)
		error_handler(37);
	if (!(parse->cl_map = ft_calloc(str_count + 1, sizeof(char *))))
		error_handler(43);
	if (parse->cl_map == NULL)
		error_handler(37);
}

void			parse_map(t_player *p, t_parse *parse, char **map, int i)
{
	int		l;
	int		k;
	int		str_count;

	k = 0;
	l = 0;
	is_simple_map(p, i, map, parse);
	str_count = map_width(map, i);
	is_error(str_count, parse);
	while (map[i] != '\0')
	{
		k = 0;
		if (!(parse->cl_map[l] = ft_calloc(map_len(map) + 1, sizeof(char))))
			error_handler(43);
		while (map[i][k] != '\0')
		{
			parse->cl_map[l][k] = map[i][k];
			k++;
		}
		add_space(parse, map, l, k);
		l++;
		i++;
	}
	ft_is_closed(parse->cl_map, str_count, map_len(parse->cl_map));
	parse->args++;
}
