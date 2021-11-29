/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilverb <csilverb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 01:18:29 by csilverb          #+#    #+#             */
/*   Updated: 2021/03/25 01:25:52 by csilverb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

static void	check_closed(char **map, int i, int k, int len)
{
	if ((!ft_strchr(" 1", map[i][k]) && k == 0)
	|| (!ft_strchr(" 1", map[i][k]) && k == len - 1))
		error_handler(34);
	else if (map[i][k] == '0' || map[i][k] == '2')
		if (map[i][k - 1] == ' ' || map[i][k + 1] == ' '
		|| map[i - 1][k] == ' ' || map[i + 1][k] == ' '
		|| map[i - 1][k - 1] == ' ' || map[i + 1][k - 1] == ' '
		|| map[i - 1][k + 1] == ' ' || map[i + 1][k + 1] == ' ')
			error_handler(34);
}

void		ft_is_closed(char **map, int str_count, int len)
{
	int		i;
	int		k;

	i = 0;
	while (map[i] != NULL)
	{
		k = -1;
		if (i == 0 || i == str_count - 1)
			while (map[i][++k] != '\0')
			{
				if (!ft_strchr(" 1", map[i][k]))
					error_handler(34);
			}
		else
			while (map[i][++k] != '\0')
			{
				check_closed(map, i, k, len);
			}
		i++;
	}
}

static void	set_player_pos_cutter(t_player *p, char compass)
{
	if (compass == 'W')
	{
		p->dir_x = -1;
		p->dir_y = 0;
		p->pl_x = 0;
		p->pl_y = -0.66;
	}
	if (compass == 'S')
	{
		p->dir_x = 0;
		p->dir_y = 1;
		p->pl_x = -0.66;
		p->pl_y = 0;
	}
}

void		set_player_pos(t_player *p, int y, int x, char compass)
{
	p->y_pos = y + 0.5;
	p->x_pos = x + 0.5;
	if (compass == 'N')
	{
		p->dir_x = 0;
		p->dir_y = -1;
		p->pl_x = 0.66;
		p->pl_y = 0;
	}
	if (compass == 'E')
	{
		p->dir_x = 1;
		p->dir_y = 0;
		p->pl_x = 0;
		p->pl_y = 0.66;
	}
	set_player_pos_cutter(p, compass);
}

void		is_simple_map(t_player *p, int i, char **map, t_parse *parse)
{
	int counter;
	int k;

	counter = 0;
	while (map[i] != NULL)
	{
		k = -1;
		while (map[i][++k] != '\0' || map[i][0] == '\0')
		{
			if (ft_strchr("WESN", map[i][k]) && map[i][0] != '\0')
			{
				set_player_pos(p, counter, k, map[i][k]);
				map[i][k] = '0';
				p->pl_count++;
			}
			if (map[i][k] == '2')
				parse->sp_count++;
			if (!ft_strchr(" 012WESN", map[i][k]) || map[i][0] == '\0')
				error_handler(36);
		}
		i++;
		counter++;
	}
	if (p->pl_count != 1)
		error_handler(35);
}
