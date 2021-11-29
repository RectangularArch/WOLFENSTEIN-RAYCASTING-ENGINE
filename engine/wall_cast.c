/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_cast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilverb <csilverb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 01:24:15 by csilverb          #+#    #+#             */
/*   Updated: 2021/04/04 16:03:16 by csilverb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/engine.h"

static void	wcast_init(t_main *main, t_w_cast *wcast, int x)
{
	wcast->cam_x = 2 * x / (double)main->parsed->res[0] - 1;
	wcast->r_dir_x = main->p->dir_x + main->p->pl_x * wcast->cam_x;
	wcast->r_dir_y = main->p->dir_y + main->p->pl_y * wcast->cam_x;
	wcast->map_x = (int)main->p->x_pos;
	wcast->map_y = (int)main->p->y_pos;
	wcast->d_d_x = 1 / wcast->r_dir_x;
	wcast->d_d_y = 1 / wcast->r_dir_y;
	if ((1 / wcast->r_dir_x) < 0)
		wcast->d_d_x = 1 / wcast->r_dir_x * -1;
	if ((1 / wcast->r_dir_y) < 0)
		wcast->d_d_y = 1 / wcast->r_dir_y * -1;
	wcast->hit = 0;
}

static void	side_dist(t_main *main, t_w_cast *wcast)
{
	if (wcast->r_dir_x < 0)
	{
		wcast->step_x = -1;
		wcast->s_d_x = (main->p->x_pos - wcast->map_x) * wcast->d_d_x;
	}
	else
	{
		wcast->step_x = 1;
		wcast->s_d_x = (wcast->map_x + 1.0 - main->p->x_pos) * wcast->d_d_x;
	}
	if (wcast->r_dir_y < 0)
	{
		wcast->step_y = -1;
		wcast->s_d_y = (main->p->y_pos - wcast->map_y) * wcast->d_d_y;
	}
	else
	{
		wcast->step_y = 1;
		wcast->s_d_y = (wcast->map_y + 1.0 - main->p->y_pos) * wcast->d_d_y;
	}
}

static void	is_hit(t_main *main, t_w_cast *wcast)
{
	while (wcast->hit == 0)
	{
		if (wcast->s_d_x < wcast->s_d_y)
		{
			wcast->s_d_x += wcast->d_d_x;
			wcast->map_x += wcast->step_x;
			wcast->side = 0;
		}
		else
		{
			wcast->s_d_y += wcast->d_d_y;
			wcast->map_y += wcast->step_y;
			wcast->side = 1;
		}
		if (main->parsed->cl_map[wcast->map_y][wcast->map_x] == '1')
			wcast->hit = 1;
	}
	if (wcast->side == 0)
		wcast->perp_wall_dist = (wcast->map_x - main->p->x_pos
		+ (1 - wcast->step_x) / 2) / wcast->r_dir_x;
	else
		wcast->perp_wall_dist = (wcast->map_y - main->p->y_pos
		+ (1 - wcast->step_y) / 2) / wcast->r_dir_y;
}

static void	text_draw_params(t_main *main, t_w_cast *wcast)
{
	wcast->line_h = (int)(main->parsed->res[1] / wcast->perp_wall_dist);
	wcast->dr_st = -wcast->line_h / 2 + main->parsed->res[1] / 2;
	if (wcast->dr_st < 0)
		wcast->dr_st = 0;
	wcast->dr_end = wcast->line_h / 2 + main->parsed->res[1] / 2;
	if (wcast->dr_end >= main->parsed->res[1])
		wcast->dr_end = main->parsed->res[1] - 1;
	if (wcast->side == 0)
		wcast->wall_x = main->p->y_pos + wcast->perp_wall_dist * wcast->r_dir_y;
	else
		wcast->wall_x = main->p->x_pos + wcast->perp_wall_dist * wcast->r_dir_x;
	wcast->wall_x -= floor((wcast->wall_x));
}

void		wall_cast(t_main *main, t_w_cast *wcast)
{
	int x;

	x = 0;
	while (x < main->parsed->res[0])
	{
		wcast_init(main, wcast, x);
		side_dist(main, wcast);
		is_hit(main, wcast);
		text_draw_params(main, wcast);
		check_text(main, wcast);
		wcast->text_x = (int)(wcast->wall_x * (double)(wcast->tex_w));
		if (wcast->side == 0 && wcast->r_dir_x > 0)
			wcast->text_x = wcast->tex_w - wcast->text_x - 1;
		if (wcast->side == 1 && wcast->r_dir_y < 0)
			wcast->text_x = wcast->tex_w - wcast->text_x - 1;
		wcast->text_x = wcast->tex_w - wcast->text_x - 1;
		wcast->step = 1.0 * wcast->tex_h / wcast->line_h;
		wcast->text_pos = (wcast->dr_st - main->parsed->res[1]
		/ 2 + wcast->line_h / 2) * wcast->step;
		draw_text(main, wcast, x, 0);
		wcast->z_buff[x] = wcast->perp_wall_dist;
		x++;
	}
}
