/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_save.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 20:26:44 by nfedayki          #+#    #+#             */
/*   Updated: 2021/05/16 20:30:55 by nfedayki         ###   ########.fr       */
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

static void	bmp_prepare(t_ray *ray, t_param *prm)
{
	t_render	*render;
	t_monitor	*screen;

	render = prm->ptr;
	screen = ft_take_last_arg(prm->dlist, ID_RES)->content;
	ft_pixel_export(ray, prm, screen);
	mlx_destroy_image(render->mlx, ray->img.img);
	ray->img.img = NULL;
}

static void	bmp_render(t_ray *ray, t_param *prm)
{
	int			x;
	t_monitor	*screen;

	x = 0;
	screen = ft_take_last_arg(prm->dlist, ID_RES)->content;
	while (x < screen->width)
	{
		ft_init_ray(x, ray, prm);
		ft_ray_hits_scan(ray, prm);
		ft_ray_perspective(ray, prm);
		ft_ray_texture(ray, prm);
		ft_fill_buff(ray, prm);
		ft_sprite_building(ray, prm);
		ft_ft_fill_line_sprite(x, ray, prm, 0);
		ft_fill_line(x, ray, prm);
		ft_clear_list(&ray->sprites);
		x++;
	}
}

int	ft_pixel_calculate(t_param *prm)
{
	t_ray		ray;
	t_render	*render;
	t_monitor	*screen;

	render = prm->ptr;
	screen = ft_take_last_arg(prm->dlist, ID_RES)->content;
	ray.img = my_mlx_new_image(render->mlx, screen->width, screen->height);
	ray.line_buff = malloc(screen->height * sizeof(int));
	if (ray.line_buff == NULL)
		return (MAL_ERR_BUFF);
	bmp_render(&ray, prm);
	free(ray.line_buff);
	bmp_prepare(&ray, prm);
	return (ft_exit(0, prm));
}
