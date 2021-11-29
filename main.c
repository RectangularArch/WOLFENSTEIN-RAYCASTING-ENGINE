/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilverb <csilverb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 14:04:02 by csilverb          #+#    #+#             */
/*   Updated: 2021/03/23 21:05:55 by csilverb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/main.h"
#include "includes/parser.h"
#include "includes/error_handler.h"

static void		is_cub(char *argv)
{
	char *point;

	point = ft_strrchr(argv, '.');
	if (ft_strnstr(point, ".cub\0", 5) != point)
		error_handler(46);
}

static void		is_save(char *argv)
{
	if (ft_strncmp(argv, "--save\0", 7) != 0)
		error_handler(46);
}

static int		ft_is_read(char *argv)
{
	int		fd;
	char	buff[1];

	fd = open(argv, O_RDONLY);
	if (read(fd, buff, 1) != 1)
		return (-1);
	close(fd);
	fd = open(argv, O_RDONLY);
	return (fd);
}

int				main(int argc, char **argv)
{
	t_list	*head;
	t_main	*main;
	int		fd;
	char	**map;

	head = NULL;
	if ((fd = ft_is_read(argv[1])) == -1)
		error_handler(44);
	if (argc == 2 || argc == 3)
	{
		head = fill_list(fd, head);
		map = make_map(&head, ft_lstsize(head));
		if ((main = parser(map)) == NULL)
			error_handler(42);
		if (argc == 3)
			is_save(argv[2]);
		is_cub(argv[1]);
		engine(argc, main);
	}
	else
		error_handler(45);
	return (0);
}
