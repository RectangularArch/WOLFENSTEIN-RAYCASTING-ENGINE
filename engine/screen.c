/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilverb <csilverb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:22:24 by csilverb          #+#    #+#             */
/*   Updated: 2021/03/25 01:52:07 by csilverb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/screen.h"

static int		get_color(t_main *main, int y, int x)
{
	int		new_color;
	char	*dst;

	dst = main->window->addr +
	(y * main->window->line_l + x * (main->window->bpp / 8));
	new_color = *(int*)dst;
	return (new_color);
}

static void		bmp_init(t_main *main, t_bitmap *pbitmap, int pixelbytesize)
{
	pbitmap->fileheader.bm[0] = 0x42;
	pbitmap->fileheader.bm[1] = 0x4D;
	pbitmap->fileheader.filesize = pixelbytesize +
	sizeof(t_bitmapinfoheader) + sizeof(t_fileheader) - 2;
	pbitmap->fileheader.fileoffset_to_pixelarray =
	sizeof(t_bitmapinfoheader) + sizeof(t_fileheader) - 2;
	pbitmap->bitmapinfoheader.dibheadersize = sizeof(t_bitmapinfoheader);
	pbitmap->bitmapinfoheader.width = main->parsed->res[0];
	pbitmap->bitmapinfoheader.height = main->parsed->res[1];
	pbitmap->bitmapinfoheader.planes = 1;
	pbitmap->bitmapinfoheader.bitsperpixel = 32;
	pbitmap->bitmapinfoheader.compression = 0;
	pbitmap->bitmapinfoheader.imagesize = 0;
	pbitmap->bitmapinfoheader.ypixelpermeter = 0;
	pbitmap->bitmapinfoheader.xpixelpermeter = 0;
	pbitmap->bitmapinfoheader.numcolorspallette = 0;
	pbitmap->bitmapinfoheader.mostimpcolor = 0;
}

static int		*get_color_str(t_main *main)
{
	int			c;
	int			y;
	int			x;
	int			pxl;
	int			*pxlstr;

	if (!(pxlstr = (int *)malloc(sizeof(int)
	* main->parsed->res[1] * main->parsed->res[0])))
		error_handler(48);
	c = 1;
	y = 0;
	while (y != main->parsed->res[1])
	{
		x = main->parsed->res[0] - 1;
		while (x >= 0)
		{
			pxl = get_color(main, y, x);
			pxlstr[main->parsed->res[1] * main->parsed->res[0] - c] = pxl;
			c++;
			x--;
		}
		y++;
	}
	return (pxlstr);
}

void			screen(t_main *main)
{
	t_bitmap	*pbitmap;
	int			fd;
	int			pixelbytesize;
	int			*pxlstr;

	fd = open("screenshot.bmp", O_TRUNC | O_CREAT | O_RDWR
	| O_APPEND, S_IREAD | S_IWRITE);
	if (!(pbitmap = (t_bitmap *)ft_calloc(1, sizeof(t_bitmap))))
		error_handler(48);
	pixelbytesize = main->parsed->res[0] * main->parsed->res[1] * 32 / 8;
	bmp_init(main, pbitmap, pixelbytesize);
	write(fd, &pbitmap->fileheader.bm, sizeof(pbitmap->fileheader.bm));
	write(fd, &pbitmap->fileheader.filesize,
	sizeof(pbitmap->fileheader.filesize));
	write(fd, &pbitmap->fileheader.reserved,
	sizeof(pbitmap->fileheader.reserved));
	write(fd, &pbitmap->fileheader.fileoffset_to_pixelarray,
	sizeof(pbitmap->fileheader.fileoffset_to_pixelarray));
	write(fd, &pbitmap->bitmapinfoheader, sizeof(pbitmap->bitmapinfoheader));
	pxlstr = get_color_str(main);
	write(fd, pxlstr, pixelbytesize);
	close(fd);
	free(pbitmap);
	free(pxlstr);
	exit(0);
}
