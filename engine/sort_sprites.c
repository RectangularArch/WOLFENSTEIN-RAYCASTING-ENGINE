/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilverb <csilverb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:26:49 by csilverb          #+#    #+#             */
/*   Updated: 2021/03/23 22:36:37 by csilverb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/engine.h"

static void	swap(t_main *main, int i, int j)
{
	t_sprite temp;

	temp = main->parsed->sprites[i];
	main->parsed->sprites[i] = main->parsed->sprites[j];
	main->parsed->sprites[j] = temp;
}

static int	partition(t_main *main, int low, int hight)
{
	double	pivot;
	int		i;
	int		j;

	i = low - 1;
	j = low;
	pivot = main->parsed->sprites[hight].dist;
	while (j <= hight - 1)
	{
		if (main->parsed->sprites[j].dist > pivot)
		{
			i++;
			swap(main, i, j);
		}
		j++;
	}
	swap(main, i + 1, hight);
	return (i + 1);
}

void		sort_sprites(t_main *main, int low, int hight)
{
	int pi;

	if (low < hight)
	{
		pi = partition(main, low, hight);
		sort_sprites(main, low, pi - 1);
		sort_sprites(main, pi + 1, hight);
	}
}
