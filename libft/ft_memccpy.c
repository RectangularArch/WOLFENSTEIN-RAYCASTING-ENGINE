/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilverb <csilverb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 15:42:44 by csilverb          #+#    #+#             */
/*   Updated: 2021/01/04 19:18:23 by csilverb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		*ft_memccpy(void *dst, const void *s, int ch, size_t count)
{
	size_t	i;
	char	*src;
	char	*dest;

	i = 0;
	src = (char *)s;
	dest = (char *)dst;
	while (i != count)
	{
		dest[i] = src[i];
		if (src[i] == (char)ch)
			return (&dest[i + 1]);
		i++;
	}
	return (NULL);
}
