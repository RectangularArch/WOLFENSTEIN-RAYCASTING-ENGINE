/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilverb <csilverb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 14:27:19 by csilverb          #+#    #+#             */
/*   Updated: 2021/03/25 23:10:02 by csilverb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

static char		ft_check_flag(char *string, t_parse *parsed)
{
	char flag;

	if (ft_strnstr(string, "F", 1) == &string[0])
	{
		parsed->f_flag++;
		flag = 'F';
	}
	if (ft_strnstr(string, "C", 1) == &string[0])
	{
		parsed->c_flag++;
		flag = 'C';
	}
	if (parsed->f_flag > 1 || parsed->c_flag > 1)
		error_handler(39);
	return (flag);
}

static int		ft_num_len_rgb(int num)
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

static char		*while_cutter(char *string, char flag, int c, t_parse *parsed)
{
	while (string[0] == ' ')
		string++;
	if (flag == 'F')
		parsed->f_rgb[c] = ft_atoi(string);
	else if (flag == 'C')
		parsed->c_rgb[c] = ft_atoi(string);
	if (ft_atoi(string) == 0 && string[0] != '0')
		return (&string[0]);
	while (string[0] == '0')
		string++;
	if (string[0] == ',' && c == 2)
		error_handler(39);
	if (flag == 'F' && string[0] != '\0')
		string += ft_num_len_rgb(parsed->f_rgb[c]);
	else if (flag == 'C' && string[0] != '\0')
		string += ft_num_len_rgb(parsed->c_rgb[c]);
	while (string[0] == ' ')
		string++;
	if (string[0] == ',' && c != 2)
		string++;
	return (string);
}

void			parse_rgb(t_parse *parsed, char *string)
{
	char	flag;
	int		c;

	c = 0;
	flag = ft_check_flag(string, parsed);
	while (string[++c] != '\0')
		if (string[c] != ' ' && string[c] != ','
		&& (string[c] < 48 || string[c] > 57))
			error_handler(39);
	if ((int)ft_strlen(string) == c)
	{
		c = 0;
		string++;
		while (ft_atoi(string) >= 0 && ft_atoi(string) <= 255
		&& c < 3 && string[0 != '\0'])
		{
			string = while_cutter(string, flag, c, parsed);
			c++;
		}
		if (c < 3 || ft_strlen(string) > 0)
			error_handler(39);
	}
	parsed->args++;
}
