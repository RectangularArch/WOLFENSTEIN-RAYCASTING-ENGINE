/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilverb <csilverb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 13:35:36 by csilverb          #+#    #+#             */
/*   Updated: 2021/03/16 13:38:40 by csilverb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/get_next_line.h"

char		*ft_strdup_gnl(char *str)
{
	int		i;
	size_t	len;
	char	*s;

	len = 0;
	i = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	s = malloc(len + 1);
	if (s == NULL)
	{
		return (NULL);
	}
	while (len > 0)
	{
		s[i] = str[i];
		len--;
		i++;
	}
	s[i] = '\0';
	return (s);
}

char		*ft_strjoin_gnl(char *s1, char *s2)
{
	char		*s;
	size_t		i;
	size_t		j;

	i = -1;
	j = -1;
	if (!s1 || !s2)
		return (NULL);
	s = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s == NULL)
		return (NULL);
	while (s1[++i] != '\0')
	{
		s[i] = s1[i];
	}
	while (s2[++j] != '\0')
	{
		s[i] = s2[j];
		i++;
	}
	s[i] = '\0';
	free(s1);
	return (s);
}
