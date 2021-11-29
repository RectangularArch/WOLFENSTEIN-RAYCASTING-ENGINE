/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilverb <csilverb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 22:58:07 by csilverb          #+#    #+#             */
/*   Updated: 2021/03/24 23:42:49 by csilverb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREEN_H
# define SCREEN_H
# include "engine.h"

typedef struct	s_fileheader
{
	char				bm[2];
	int					filesize;
	int					reserved;
	int					fileoffset_to_pixelarray;
}				t_fileheader;

typedef struct	s_bitmapinfoheader
{
	int					dibheadersize;
	int					width;
	int					height;
	short				planes;
	short				bitsperpixel;
	int					compression;
	int					imagesize;
	int					ypixelpermeter;
	int					xpixelpermeter;
	int					numcolorspallette;
	int					mostimpcolor;
}				t_bitmapinfoheader;

typedef struct	s_bitmap
{
	t_fileheader		fileheader;
	t_bitmapinfoheader	bitmapinfoheader;
}				t_bitmap;

#endif
