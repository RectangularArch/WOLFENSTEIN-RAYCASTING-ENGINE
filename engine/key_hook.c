/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilverb <csilverb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 20:39:11 by csilverb          #+#    #+#             */
/*   Updated: 2021/03/24 20:12:12 by csilverb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/engine.h"

static int		w_s_key(int keycode, t_main *main, int is_key)
{
	if (keycode == W)
	{
		if (main->parsed->cl_map[(int)main->p->y_pos]
		[(int)(main->p->x_pos + main->p->dir_x * P_SP)] == '0')
			main->p->x_pos += main->p->dir_x * P_SP;
		if (main->parsed->cl_map[(int)(main->p->y_pos
		+ main->p->dir_y * P_SP)][(int)main->p->x_pos] == '0')
			main->p->y_pos += main->p->dir_y * P_SP;
		is_key++;
	}
	if (keycode == S)
	{
		if (main->parsed->cl_map[(int)main->p->y_pos]
		[(int)(main->p->x_pos - main->p->dir_x * P_SP)] == '0')
			main->p->x_pos -= main->p->dir_x * P_SP;
		if (main->parsed->cl_map[(int)(main->p->y_pos
		- main->p->dir_y * P_SP)][(int)main->p->x_pos] == '0')
			main->p->y_pos -= main->p->dir_y * P_SP;
		is_key++;
	}
	return (is_key);
}

static int		a_d_key(int keycode, t_main *main, int is_key)
{
	if (keycode == A)
	{
		if (main->parsed->cl_map[(int)main->p->y_pos]
		[(int)(main->p->x_pos + main->p->dir_y * P_SP)] == '0')
			main->p->x_pos += main->p->dir_y * P_SP;
		if (main->parsed->cl_map[(int)(main->p->y_pos
		- main->p->dir_x * P_SP)][(int)main->p->x_pos] == '0')
			main->p->y_pos -= main->p->dir_x * P_SP;
		is_key++;
	}
	if (keycode == D)
	{
		if (main->parsed->cl_map[(int)main->p->y_pos]
		[(int)(main->p->x_pos - main->p->dir_y * P_SP)] == '0')
			main->p->x_pos -= main->p->dir_y * P_SP;
		if (main->parsed->cl_map[(int)(main->p->y_pos
		+ main->p->dir_x * P_SP)][(int)main->p->x_pos] == '0')
			main->p->y_pos += main->p->dir_x * P_SP;
		is_key++;
	}
	return (is_key);
}

static int		arr_key(int keycode, t_main *main, int is_key)
{
	double old_dir_x;
	double old_pl_x;

	old_dir_x = main->p->dir_x;
	old_pl_x = main->p->pl_x;
	if (keycode == R_ARR)
	{
		main->p->dir_x = main->p->dir_x *
		cos(R_SP) - main->p->dir_y * sin(R_SP);
		main->p->dir_y = old_dir_x * sin(R_SP) + main->p->dir_y * cos(R_SP);
		main->p->pl_x = main->p->pl_x * cos(R_SP) - main->p->pl_y * sin(R_SP);
		main->p->pl_y = old_pl_x * sin(R_SP) + main->p->pl_y * cos(R_SP);
		is_key++;
	}
	if (keycode == L_ARR)
	{
		main->p->dir_x = main->p->dir_x
		* cos(-R_SP) - main->p->dir_y * sin(-R_SP);
		main->p->dir_y = old_dir_x * sin(-R_SP) + main->p->dir_y * cos(-R_SP);
		main->p->pl_x = main->p->pl_x * cos(-R_SP) - main->p->pl_y * sin(-R_SP);
		main->p->pl_y = old_pl_x * sin(-R_SP) + main->p->pl_y * cos(-R_SP);
		is_key++;
	}
	return (is_key);
}

int				key_hook(int keycode, t_main *main, int argc)
{
	int is_key;

	if (keycode == ESC)
		exit(0);
	is_key = 0;
	if (!(is_key = w_s_key(keycode, main, is_key)))
		if (!(is_key = a_d_key(keycode, main, is_key)))
			is_key = arr_key(keycode, main, is_key);
	if (is_key == 1)
	{
		mlx_destroy_image(main->window->mlx, main->window->img);
		main->window->img = mlx_new_image(main->window->mlx,
		main->parsed->res[0], main->parsed->res[1]);
		main->window->addr = mlx_get_data_addr(main->window->img,
		&main->window->bpp, &main->window->line_l, &main->window->en);
		draw_all(argc, main);
	}
	return (keycode);
}

int				key_hook_cross(void)
{
	exit(0);
}
