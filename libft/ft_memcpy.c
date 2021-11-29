/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilverb <csilverb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 13:55:54 by csilverb          #+#    #+#             */
/*   Updated: 2021/01/04 19:18:23 by csilverb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		*ft_memcpy(void *destptr, const void *srcptr, size_t num)
{
	size_t	i;
	char	*src;
	char	*dest;

	i = 0;
	src = (char *)srcptr;
	dest = (char *)destptr;
	if ((destptr == '\0') && (srcptr == '\0'))
	{
		return (NULL);
	}
	while (i != num)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
