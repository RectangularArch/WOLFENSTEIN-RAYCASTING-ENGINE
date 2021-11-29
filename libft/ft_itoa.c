/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilverb <csilverb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 21:16:14 by csilverb          #+#    #+#             */
/*   Updated: 2021/01/04 19:18:23 by csilverb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char			*ft_wrtr(char *s, unsigned int un, int n, int count)
{
	int				i;
	unsigned int	dig;
	char			*res;

	res = s;
	i = count - 1;
	dig = un;
	res[i] = '\0';
	i--;
	if (dig == 0)
	{
		res[i] = '0';
		return (res);
	}
	while (dig != 0)
	{
		res[i] = (dig % 10) + '0';
		dig /= 10;
		i--;
	}
	if (n < 0)
	{
		res[i] = '-';
	}
	return (res);
}

static int			ft_memc(int n)
{
	int		dig;
	int		mem;

	dig = n;
	mem = (n <= 0) ? 2 : 1;
	while (dig != 0)
	{
		dig /= 10;
		mem++;
	}
	return (mem);
}

char				*ft_itoa(int n)
{
	unsigned int	un;
	char			*s;

	un = (n < 0) ? n * -1 : n;
	s = malloc(ft_memc(n) * sizeof(char));
	if (s == NULL)
		return (NULL);
	s = ft_wrtr(s, un, n, ft_memc(n));
	return (s);
}
