/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilverb <csilverb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 17:19:18 by csilverb          #+#    #+#             */
/*   Updated: 2021/01/04 19:18:23 by csilverb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strchr(const char *str, int ch)
{
	int i;

	i = 0;
	if (ch == '\0')
	{
		while (str[i] != 0)
		{
			i++;
		}
		return ((char *)&str[i]);
	}
	while (str[i] != 0)
	{
		if (str[i] == ch)
		{
			return ((char *)&str[i]);
		}
		i++;
	}
	return (NULL);
}
