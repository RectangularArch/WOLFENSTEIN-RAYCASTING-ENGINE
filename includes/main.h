/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilverb <csilverb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 14:07:29 by csilverb          #+#    #+#             */
/*   Updated: 2021/03/25 01:54:17 by csilverb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "libft.h"
# include "../minilibx_mms_20200219/mlx.h"
# include "error_handler.h"
# define SCALE 15
# define MAX_SS_SIZE 16384

typedef struct		s_win
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*addr;
	int			line_l;
	int			bpp;
	int			en;
}					t_win;

typedef struct		s_sprite
{
	int			x;
	int			y;
	double		dist;
}					t_sprite;

typedef struct		s_parse
{
	int			args;
	int			res[2];
	char		*n_text;
	char		*s_text;
	char		*w_text;
	char		*e_text;
	char		*sp_text;
	int			f_rgb[3];
	int			f_flag;
	int			c_rgb[3];
	int			c_flag;
	char		**cl_map;
	int			sp_count;
	t_sprite	*sprites;
}					t_parse;

typedef struct		s_player
{
	double		x_pos;
	double		y_pos;
	double		dir_x;
	double		dir_y;
	double		pl_x;
	double		pl_y;
	double		dir_start;
	double		dir_end;
	int			pl_count;
}					t_player;

typedef struct		s_text
{
	t_win		*n;
	int			res_n[2];
	t_win		*s;
	int			res_s[2];
	t_win		*w;
	int			res_w[2];
	t_win		*e;
	int			res_e[2];
	t_win		*spr;
	int			res_sp[2];
}					t_text;

typedef struct		s_main
{
	t_parse		*parsed;
	t_player	*p;
	t_win		*window;
	t_text		*txts;
}					t_main;

int					get_next_line(int fd, char **line);
t_main				*parser(char **map);
void				mxl(t_main *main);
void				engine(int argc, t_main *main);
void				screen(t_main *main);

#endif
