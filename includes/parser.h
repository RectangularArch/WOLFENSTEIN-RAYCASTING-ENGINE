/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilverb <csilverb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 13:41:33 by csilverb          #+#    #+#             */
/*   Updated: 2021/03/23 21:54:36 by csilverb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "main.h"
# include "error_handler.h"

void		parse_resolution(t_parse *parse, char *string);
void		parse_link(t_parse *parse, char *string);
void		parse_rgb(t_parse *parse, char *string);
void		parse_map(t_player *p, t_parse *parse, char **map, int i);
void		ft_is_closed(char **map, int str_count, int len);
void		set_player_pos(t_player *p, int y, int x, char compass);
void		ft_is_sprite(char **map, t_main *main_temp);
t_main		*main_temp_malloc(t_main *main_temp);
void		is_simple_map(t_player *p, int i, char **map, t_parse *parse);
char		**make_map(t_list **head, int size);
t_list		*fill_list(int fd, t_list *head);

#endif
