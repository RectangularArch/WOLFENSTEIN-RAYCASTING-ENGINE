/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilverb <csilverb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 23:24:22 by csilverb          #+#    #+#             */
/*   Updated: 2021/03/25 20:48:04 by csilverb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/engine.h"

int		create_trgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_win *window, int x, int y, int color)
{
	char *dst;

	dst = window->addr + (y * window->line_l + x * (window->bpp / 8));
	*(unsigned int*)dst = color;
}

void	draw_planes(t_main *main)
{
	int color_f;
	int color_c;
	int x;
	int y;

	color_f = create_trgb(main->parsed->c_rgb[0],
	main->parsed->c_rgb[1], main->parsed->c_rgb[2]);
	color_c = create_trgb(main->parsed->f_rgb[0],
	main->parsed->f_rgb[1], main->parsed->f_rgb[2]);
	x = 0;
	while (x < main->parsed->res[0])
	{
		y = -1;
		while (++y <= main->parsed->res[1] / 2)
			my_mlx_pixel_put(main->window, x, y, color_f);
		y = main->parsed->res[1] / 2 - 1;
		while (++y <= main->parsed->res[1] - 1)
			my_mlx_pixel_put(main->window, x, y, color_c);
		x++;
	}
	mlx_put_image_to_window(main->window->mlx,
	main->window->win, main->window->img, 0, 0);
}
