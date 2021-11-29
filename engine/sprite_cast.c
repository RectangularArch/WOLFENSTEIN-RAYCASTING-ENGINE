/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_cast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilverb <csilverb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 20:14:50 by csilverb          #+#    #+#             */
/*   Updated: 2021/04/03 18:18:25 by csilverb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/engine.h"

static void		scast_init(t_main *main, t_s_cast *scast, int i)
{
	scast->spr_x = main->parsed->sprites[i].x
	- main->p->x_pos + S_POS_CORR;
	scast->spr_y = main->parsed->sprites[i].y
	- main->p->y_pos + S_POS_CORR;
	scast->inv_det = 1.0 / (main->p->pl_x * main->p->dir_y
	- main->p->dir_x * main->p->pl_y);
	scast->tr_x = scast->inv_det *
	(main->p->dir_y * scast->spr_x - main->p->dir_x * scast->spr_y);
	scast->tr_y = scast->inv_det *
	(-main->p->pl_y * scast->spr_x + main->p->pl_x * scast->spr_y);
	scast->spr_scr_x = (int)((main->parsed->res[0] / 2)
	* (1 + scast->tr_x / scast->tr_y));
	scast->spr_scr_vmove = (int)(S_V_MOVE / scast->tr_y);
	scast->spr_h = abs((int)(main->parsed->res[1] / (scast->tr_y))) / S_V_DIV;
	scast->dr_st_y = -scast->spr_h / 2
	+ main->parsed->res[1] / 2 + scast->spr_scr_vmove;
	scast->dr_end_y = scast->spr_h / 2
	+ main->parsed->res[1] / 2 + scast->spr_scr_vmove;
	scast->spr_w = abs((int)(main->parsed->res[0] / (scast->tr_y))) / S_U_DIV;
	scast->dr_st_x = -scast->spr_w / 2 + scast->spr_scr_x;
	scast->dr_end_x = scast->spr_w / 2 + scast->spr_scr_x;
}

static char		*set_dst(t_main *main, t_s_cast *scast, int y)
{
	char	*dst;
	int		res;

	res = main->parsed->res[1];
	scast->d = (y - scast->spr_scr_vmove) * 256
	- res * 128 + scast->spr_h * 128;
	if ((scast->texy = ((scast->d * main->txts->res_sp[1])
	/ scast->spr_h) / 256) < 0)
		scast->texy = 0;
	if (scast->texy >= main->txts->res_sp[1])
		scast->texy = main->txts->res_sp[1] - 1;
	dst = main->txts->spr->addr + (scast->texy *
	main->txts->spr->line_l + scast->texx *
	(main->txts->spr->bpp / 8));
	return (dst);
}

static void		draw_spr(t_main *main, t_w_cast *wcast, t_s_cast *scast, int s)
{
	unsigned int	new_color;
	int				y;

	s = scast->dr_st_x;
	while (s <= scast->dr_end_x)
	{
		if ((scast->texx = (int)(256 * (s - (-scast->spr_w / 2
		+ scast->spr_scr_x)) * main->txts->res_sp[0] / scast->spr_w) / 256) < 0)
			scast->texx = 0;
		if (scast->texx >= main->txts->res_sp[0])
			scast->texx = main->txts->res_sp[0] - 1;
		if (scast->tr_y > 0 && s >= 0 && s < main->parsed->res[0]
		&& scast->tr_y < wcast->z_buff[s])
		{
			y = scast->dr_st_y;
			while (y < scast->dr_end_y)
			{
				new_color = *(unsigned int*)set_dst(main, scast, y);
				if (new_color != 0)
					my_mlx_pixel_put(main->window, s, y, new_color);
				y++;
			}
		}
		s++;
	}
}

void			sprite_cast(t_main *main, t_w_cast *wcast, t_s_cast *scast)
{
	int i;

	i = -1;
	while (++i < main->parsed->sp_count)
		main->parsed->sprites[i].dist = ((main->p->x_pos -
		main->parsed->sprites[i].x) * (main->p->x_pos -
		main->parsed->sprites[i].x) + (main->p->y_pos -
		main->parsed->sprites[i].y) * (main->p->y_pos -
		main->parsed->sprites[i].y));
	sort_sprites(main, 0, main->parsed->sp_count - 1);
	i = 0;
	while (i < main->parsed->sp_count)
	{
		scast_init(main, scast, i);
		if (scast->dr_st_y < 0)
			scast->dr_st_y = 0;
		if (scast->dr_end_y >= main->parsed->res[1])
			scast->dr_end_y = main->parsed->res[1] - 1;
		if (scast->dr_st_x < 0)
			scast->dr_st_x = 0;
		if (scast->dr_end_x >= main->parsed->res[0])
			scast->dr_end_x = main->parsed->res[0] - 1;
		draw_spr(main, wcast, scast, 0);
		i++;
	}
}
