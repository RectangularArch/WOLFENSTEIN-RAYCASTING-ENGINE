/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_resolution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilverb <csilverb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:55:17 by csilverb          #+#    #+#             */
/*   Updated: 2021/03/22 22:12:09 by csilverb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

static int	ft_num_len(int num)
{
	int i;

	i = 0;
	if (num == 0)
		i = 1;
	while (num != 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

static void	is_simple(char *string)
{
	int c;

	c = -1;
	while (string[++c] != '\0')
		if (string[c] != ' ' && (string[c] < 48 || string[c] > 57))
			error_handler(40);
}

static char	*overflow(char *string)
{
	while (string[0] == ' ')
		string++;
	while (string[0] != ' ')
		string++;
	return (string);
}

void		parse_resolution(t_parse *parsed, char *string)
{
	int	c;
	int i;

	c = -1;
	string++;
	is_simple(string);
	while (++c < 2)
	{
		i = 0;
		if (parsed->res[c] != 0)
			error_handler(40);
		if ((parsed->res[c] = ft_atoi(string)) == -1)
		{
			string = overflow(string);
			continue ;
		}
		if (parsed->res[c] == 0)
			error_handler(40);
		while (string[i] == ' ' || string[i] == '0')
			i++;
		string += i;
		string += ft_num_len(parsed->res[c]);
	}
	if (c < 2 || ft_atoi(string) > 0)
		error_handler(40);
}
