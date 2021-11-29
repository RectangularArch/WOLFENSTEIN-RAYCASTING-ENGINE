/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilverb <csilverb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 22:02:33 by csilverb          #+#    #+#             */
/*   Updated: 2021/03/24 23:40:15 by csilverb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H
# include "main.h"
# include "error_handler.h"

# define ESC 53
# define W 13
# define S 1
# define A 0
# define D 2
# define R_ARR 124
# define L_ARR 123
# define P_SP 0.2
# define R_SP 0.1047198
# define S_U_DIV 1
# define S_V_DIV 1
# define S_V_MOVE 0.0
# define S_POS_CORR 0.5

typedef struct		s_wall_cast
{
	int		tex_w;
	int		tex_h;
	double	cam_x;
	double	r_dir_x;
	double	r_dir_y;
	int		map_x;
	int		map_y;
	double	s_d_x;
	double	s_d_y;
	double	d_d_x;
	double	d_d_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_h;
	int		dr_st;
	int		dr_end;
	double	wall_x;
	double	*z_buff;
	int		text_x;
	int		text_y;
	double	step;
	double	text_pos;
}					t_w_cast;

typedef struct		s_spr_cast
{
	double	spr_x;
	double	spr_y;
	double	inv_det;
	double	tr_x;
	double	tr_y;
	int		spr_scr_x;
	int		spr_scr_vmove;
	int		spr_h;
	int		dr_st_y;
	int		dr_end_y;
	int		spr_w;
	int		dr_st_x;
	int		dr_end_x;
	int		texx;
	int		texy;
	int		d;
}					t_s_cast;

void				text_read(t_main *main);
int					create_trgb(int r, int g, int b);
void				my_mlx_pixel_put(t_win *window, int x, int y, int color);
void				draw_planes(t_main *main);
void				draw_all(int argc, t_main *main);
int					key_hook(int keycode, t_main *main, int argc);
int					key_hook_cross(void);
void				sort_sprites(t_main *main, int low, int hight);
void				wall_cast(t_main *main, t_w_cast	*wcast);
void				check_text(t_main *main, t_w_cast *wcast);
void				draw_text(t_main *main, t_w_cast *wcast, int x, int y);
void				sprite_cast(t_main *main, t_w_cast *wcast, t_s_cast *scast);

#endif
