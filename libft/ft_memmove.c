/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilverb <csilverb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 16:23:27 by csilverb          #+#    #+#             */
/*   Updated: 2021/01/04 19:18:23 by csilverb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		*ft_memmove(void *destn, const void *source, size_t count)
{
	size_t	i;
	char	*src;
	char	*dest;

	i = 0;
	src = (char *)source;
	dest = (char *)destn;
	if ((destn == '\0') && (source == '\0'))
	{
		return (NULL);
	}
	if (dest < src)
		while (i != count)
		{
			dest[i] = src[i];
			i++;
		}
	else
		while (count != 0)
		{
			dest[count - 1] = src[count - 1];
			count--;
		}
	return (dest);
}
