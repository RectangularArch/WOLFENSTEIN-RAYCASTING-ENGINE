/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilverb <csilverb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 22:00:50 by csilverb          #+#    #+#             */
/*   Updated: 2021/03/25 01:44:51 by csilverb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/engine.h"

static void	is_text_malloc(t_main *main)
{
	if (!(main->txts->n = (t_win *)malloc(1 * sizeof(t_win)))
	|| !(main->txts->s = (t_win *)malloc(1 * sizeof(t_win)))
	|| !(main->txts->e = (t_win *)malloc(1 * sizeof(t_win)))
	|| !(main->txts->w = (t_win *)malloc(1 * sizeof(t_win))))
		error_handler(43);
}

static void	is_sprite_malloc(t_main *main)
{
	if (!(main->txts->spr = (t_win *)malloc(1 * sizeof(t_win))))
		error_handler(43);
}

static void	sprite_read(t_main *main)
{
	is_sprite_malloc(main);
	if (!(main->txts->spr->img = mlx_xpm_file_to_image(main->window->mlx,
	main->parsed->sp_text, &main->txts->res_sp[0], &main->txts->res_sp[1])))
		error_handler(43);
	main->txts->spr->addr = mlx_get_data_addr(main->txts->spr->img,
	&main->txts->spr->bpp, &main->txts->spr->line_l, &main->txts->spr->en);
}

void		text_read(t_main *main)
{
	is_text_malloc(main);
	if (!(main->txts->n->img = mlx_xpm_file_to_image(main->window->mlx,
	main->parsed->n_text, &main->txts->res_n[0], &main->txts->res_n[1])))
		error_handler(43);
	main->txts->n->addr = mlx_get_data_addr(main->txts->n->img,
	&main->txts->n->bpp, &main->txts->n->line_l, &main->txts->n->en);
	if (!(main->txts->s->img = mlx_xpm_file_to_image(main->window->mlx,
	main->parsed->s_text, &main->txts->res_s[0], &main->txts->res_s[1])))
		error_handler(43);
	main->txts->s->addr = mlx_get_data_addr(main->txts->s->img,
	&main->txts->s->bpp, &main->txts->s->line_l, &main->txts->s->en);
	if (!(main->txts->e->img = mlx_xpm_file_to_image(main->window->mlx,
	main->parsed->e_text, &main->txts->res_e[0], &main->txts->res_e[1])))
		error_handler(43);
	main->txts->e->addr = mlx_get_data_addr(main->txts->e->img,
	&main->txts->e->bpp, &main->txts->e->line_l, &main->txts->e->en);
	if (!(main->txts->w->img = mlx_xpm_file_to_image(main->window->mlx,
	main->parsed->w_text, &main->txts->res_w[0], &main->txts->res_w[1])))
		error_handler(43);
	main->txts->w->addr = mlx_get_data_addr(main->txts->w->img,
	&main->txts->w->bpp, &main->txts->w->line_l, &main->txts->w->en);
	sprite_read(main);
}
