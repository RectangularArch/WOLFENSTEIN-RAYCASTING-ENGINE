/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilverb <csilverb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 15:15:05 by csilverb          #+#    #+#             */
/*   Updated: 2021/03/25 20:50:26 by csilverb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/engine.h"

void		draw_all(int argc, t_main *main)
{
	t_w_cast	*wcast;
	t_s_cast	*scast;

	if (!(wcast = (t_w_cast *)malloc(1 * sizeof(t_w_cast))))
		error_handler(43);
	if (!(scast = (t_s_cast *)malloc(1 * sizeof(t_s_cast))))
		error_handler(43);
	if (!(wcast->z_buff =
	(double *)malloc(main->parsed->res[0] * sizeof(double))))
		error_handler(43);
	draw_planes(main);
	wall_cast(main, wcast);
	sprite_cast(main, wcast, scast);
	if (argc == 3)
		screen(main);
	mlx_put_image_to_window(main->window->mlx,
	main->window->win, main->window->img, 0, 0);
	free(wcast->z_buff);
	free(wcast);
	free(scast);
}

static void	is_resolution(int argc, t_main *main)
{
	int temp_w;
	int temp_h;

	mlx_get_screen_size(main->window->mlx, &temp_w, &temp_h);
	if (argc == 2)
	{
		if (main->parsed->res[0] == -1 || main->parsed->res[1] == -1 ||
		main->parsed->res[0] > temp_w || main->parsed->res[1] > temp_h)
		{
			if (main->parsed->res[0] == -1 || main->parsed->res[0] > temp_w)
				main->parsed->res[0] = temp_w;
			if (main->parsed->res[1] == -1 || main->parsed->res[1] > temp_h)
				main->parsed->res[1] = temp_h;
		}
	}
	else
	{
		if (main->parsed->res[0] > MAX_SS_SIZE ||
		main->parsed->res[1] > MAX_SS_SIZE ||
		main->parsed->res[0] == -1 ||
		main->parsed->res[1] == -1)
			error_handler(47);
	}
}

void		engine(int argc, t_main *main)
{
	main->window->mlx = mlx_init();
	is_resolution(argc, main);
	main->window->win = mlx_new_window(main->window->mlx,
	main->parsed->res[0], main->parsed->res[1], "Window");
	main->window->img = mlx_new_image(main->window->mlx,
	main->parsed->res[0], main->parsed->res[1]);
	main->window->addr = mlx_get_data_addr(main->window->img,
	&main->window->bpp, &main->window->line_l, &main->window->en);
	text_read(main);
	draw_all(argc, main);
	mlx_hook(main->window->win, 2, (1L << 0), key_hook, main);
	mlx_hook(main->window->win, 17, (1L << 0), key_hook_cross, main);
	mlx_loop(main->window->mlx);
}
