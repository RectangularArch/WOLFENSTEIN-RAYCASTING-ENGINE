/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilverb <csilverb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 18:53:43 by csilverb          #+#    #+#             */
/*   Updated: 2021/03/25 00:26:18 by csilverb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/error_handler.h"

static char	*check_error(int error_code)
{
	char *error;

	error = NULL;
	if (error_code == 42)
		error = "Error\nMap filling error!";
	else if (error_code == 41)
		error = "Error\nInvalid map arguments!";
	else if (error_code == 40)
		error = "Error\nResolution parsing error!";
	else if (error_code == 39)
		error = "Error\nRGB color parsing error!";
	else if (error_code == 38)
		error = "Error\nTexture or sprite link parsing error!";
	else if (error_code == 37)
		error = "Error\nMap parsing error!";
	else if (error_code == 36)
		error = "Error\nInvalid characters in the map!";
	else if (error_code == 35)
		error = "Error\nPlayers count error!";
	else if (error_code == 34)
		error = "Error\nMap is not closed!";
	return (error);
}

static char	*check_error_2(int error_code)
{
	char *error;

	error = NULL;
	if (error_code == 43)
		error = "Error\nMalloc error!";
	else if (error_code == 44)
		error = "Error\nMap file read error!";
	else if (error_code == 45)
		error = "Error\nInvalid arguments count!";
	else if (error_code == 46)
		error = "Error\nInvalid arguments!";
	else if (error_code == 47)
		error = "Error\nOversize screenshot res!";
	else if (error_code == 48)
		error = "Error\nBMP malloc error!";
	return (error);
}

void		error_handler(int error_code)
{
	char *error;

	error = check_error(error_code);
	if (!error)
		error = check_error_2(error_code);
	else if (!error)
		error = "Error\nUnknown error!";
	printf("%s", error);
	exit(0);
}
