/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 20:26:30 by nfedayki          #+#    #+#             */
/*   Updated: 2021/05/12 17:57:46 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "mlx.h"
#include "cub_utils.h"
#include "ft_utils.h"
#include "macroses.h"
#include "struct.h"

static int	get_pic_color(int x, int y, t_data *img)
{
	int		color;
	char	*dst;

	dst = img->addr + (y * img->line_length + x * img->bits_per_pixel / 8);
	color = *(unsigned int *)dst;
	return (color);
}

static void	fill_bmp_header(int fd, t_param *prm)
{
	int			tmp;
	int			ret;
	t_monitor	*screen;

	screen = ft_take_last_arg(prm->dlist, ID_RES)->content;
	tmp = 0x42;
	ret = write(fd, &tmp, 1);
	tmp = 0x4D;
	ret = write(fd, &tmp, 1);
	tmp = (screen->height * screen->width) * 4 + 14 + 40;
	ret = write(fd, &tmp, 4);
	tmp = 0;
	ret = write(fd, &tmp, 2);
	ret = write(fd, &tmp, 2);
	tmp = 54;
	ret = write(fd, &tmp, 4);
	if (ret < 0)
		return ;
}

static void	fill_dib_header(int fd, t_param *prm)
{
	int			tmp;
	int			ret;
	t_monitor	*screen;

	screen = ft_take_last_arg(prm->dlist, ID_RES)->content;
	tmp = 40;
	ret = write(fd, &tmp, 4);
	tmp = screen->width;
	ret = write(fd, &tmp, 4);
	tmp = screen->height;
	ret = write(fd, &tmp, 4);
	tmp = 1;
	ret = write(fd, &tmp, 2);
	tmp = 32;
	ret = write(fd, &tmp, 2);
	tmp = 0;
	ret = write(fd, &tmp, 4);
	ret = write(fd, &tmp, 4);
	ret = write(fd, &tmp, 4);
	ret = write(fd, &tmp, 4);
	ret = write(fd, &tmp, 4);
	ret = write(fd, &tmp, 4);
	if (ret < 0)
		return ;
}

void	ft_pixel_export(t_ray *ray, t_param *prm, t_monitor *screen)
{
	int			fd;
	mode_t		mode;
	int			x;
	int			y;
	int			tmp;

	mode = S_IRWXU | S_IRGRP | S_IROTH;
	fd = open("cub3d.bmp", O_RDWR | O_CREAT, mode);
	fill_bmp_header(fd, prm);
	fill_dib_header(fd, prm);
	y = screen->height - 1;
	while (y > -1)
	{
		x = 0;
		while (x < screen->width)
		{
			tmp = get_pic_color(x, y, &ray->img);
			if (write(fd, &tmp, 4) < 0)
				return ;
			x++;
		}
		y--;
	}
}
