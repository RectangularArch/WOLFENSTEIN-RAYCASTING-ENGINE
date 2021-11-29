/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilverb <csilverb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 13:34:35 by csilverb          #+#    #+#             */
/*   Updated: 2021/03/16 13:38:40 by csilverb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/get_next_line.h"

int			l_count(char *result_line)
{
	int		len;
	char	is_space;

	len = 0;
	if (ft_strchr(result_line, '\n'))
		is_space = '\n';
	else
		is_space = '\0';
	while (result_line[len] != is_space)
		len++;
	return (len);
}

char		*make_read(char *result_line, int fd)
{
	char	*buff;
	int		read_result;

	read_result = 1;
	if ((buff = (char *)malloc(sizeof(char) * (1 + 1))) == NULL)
		return (NULL);
	if (result_line == NULL)
	{
		read_result = read(fd, buff, 1);
		if (read_result < 0)
		{
			free(buff);
			return (NULL);
		}
		buff[read_result] = '\0';
		result_line = ft_strdup_gnl(buff);
	}
	while (ft_strchr(result_line, '\n') == NULL && read_result > 0)
	{
		read_result = read(fd, buff, 1);
		buff[read_result] = '\0';
		result_line = ft_strjoin_gnl(result_line, buff);
	}
	free(buff);
	return (result_line);
}

int			get_next_line(int fd, char **line)
{
	static char	*res;
	int			l;
	char		*temp;

	if (fd < 0 || 1 < 1 || !line)
		return (-1);
	if ((res = make_read(res, fd)) == NULL)
		return (-1);
	l = l_count(res);
	if (ft_strchr(res, '\n') != NULL)
	{
		temp = res;
		*line = ft_substr(temp, 0, l);
		res = ft_substr(temp, l + 1, ft_strlen(res) - ft_strlen(*line));
		free(temp);
		return (1);
	}
	*line = ft_substr(res, 0, l);
	free(res);
	res = NULL;
	return (0);
}
