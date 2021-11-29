/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_cast_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilverb <csilverb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 01:27:33 by csilverb          #+#    #+#             */
/*   Updated: 2021/04/04 16:03:34 by csilverb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/engine.h"

void				check_text(t_main *main, t_w_cast *wcast)
{
	if (wcast->side == 1 && wcast->r_dir_y > 0)
	{
		wcast->tex_w = main->txts->res_s[0];
		wcast->tex_h = main->txts->res_s[1];
	}
	if (wcast->side == 1 && wcast->r_dir_y < 0)
	{
		wcast->tex_w = main->txts->res_n[0];
		wcast->tex_h = main->txts->res_n[1];
	}
	if (wcast->side == 0 && wcast->r_dir_x > 0)
	{
		wcast->tex_w = main->txts->res_e[0];
		wcast->tex_h = main->txts->res_e[1];
	}
	if (wcast->side == 0 && wcast->r_dir_x < 0)
	{
		wcast->tex_w = main->txts->res_w[0];
		wcast->tex_h = main->txts->res_w[1];
	}
}

static unsigned int	color_darker(t_w_cast *wcast, unsigned int new_color)
{
	if (wcast->side == 0)
		new_color = (new_color >> 1) & 8355711;
	return (new_color);
}

void				draw_text(t_main *main, t_w_cast *wcast, int x, int y)
{
	unsigned int	new_color;
	char			*dst;

	y = wcast->dr_st;
	while (y <= wcast->dr_end)
	{
		wcast->text_y = (int)wcast->text_pos & (wcast->tex_h - 1);
		wcast->text_pos += wcast->step;
		if (wcast->side == 1 && wcast->r_dir_y > 0)
			dst = main->txts->s->addr + (wcast->text_y *
			main->txts->s->line_l + wcast->text_x * (main->txts->s->bpp / 8));
		if (wcast->side == 1 && wcast->r_dir_y < 0)
			dst = main->txts->n->addr + (wcast->text_y *
			main->txts->n->line_l + wcast->text_x * (main->txts->n->bpp / 8));
		if (wcast->side == 0 && wcast->r_dir_x > 0)
			dst = main->txts->e->addr + (wcast->text_y *
			main->txts->e->line_l + wcast->text_x * (main->txts->e->bpp / 8));
		if (wcast->side == 0 && wcast->r_dir_x < 0)
			dst = main->txts->w->addr + (wcast->text_y *
			main->txts->w->line_l + wcast->text_x * (main->txts->w->bpp / 8));
		new_color = *(unsigned int*)dst;
		new_color = color_darker(wcast, new_color);
		my_mlx_pixel_put(main->window, x, y, new_color);
		y++;
	}
}
