/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_engine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 20:41:58 by nfedayki          #+#    #+#             */
/*   Updated: 2021/05/16 20:48:11 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "mlx.h"
#include "cub_utils.h"
#include "ft_utils.h"
#include "macroses.h"
#include "struct.h"

static void	set_step_x(t_ray *ray, t_param *prm)
{
	t_player	*player;

	player = ft_take_last_arg(prm->dlist, ID_PLAYER)->content;
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (player->pos.x - ray->map.x) * ray->delta_dist.x;
		ray->side.x = 0;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (ray->map.x + 1.0
				- player->pos.x) * ray->delta_dist.x;
		ray->side.x = 2;
	}
}

static void	set_step_y(t_ray *ray, t_param *prm)
{
	t_player	*player;

	player = ft_take_last_arg(prm->dlist, ID_PLAYER)->content;
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (player->pos.y - ray->map.y) * ray->delta_dist.y;
		ray->side.y = 1;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (ray->map.y + 1.0 - player->pos.y)
			* ray->delta_dist.y;
		ray->side.y = 3;
	}
}

void	ft_init_ray(int x, t_ray *ray, t_param *prm)
{
	t_monitor	*screen;
	t_player	*player;

	screen = ft_take_last_arg(prm->dlist, ID_RES)->content;
	player = ft_take_last_arg(prm->dlist, ID_PLAYER)->content;
	ray->camera_x = 2 * x / (double)screen->width - 1;
	ray->dir.x = player->dir.x + player->plane.x * ray->camera_x;
	ray->dir.y = player->dir.y + player->plane.y * ray->camera_x;
	ray->map.x = (int)player->pos.x;
	ray->map.y = (int)player->pos.y;
	ray->delta_dist.x = fabs(1 / ray->dir.x);
	ray->delta_dist.y = fabs(1 / ray->dir.y);
	ray->hit = 0;
	ray->sprites = NULL;
	set_step_x(ray, prm);
	set_step_y(ray, prm);
}

static void	cast_x_rays(int x, int x_max, t_ray *ray, t_param *prm)
{
	while (x < x_max)
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

int	ft_ray_cast(t_param *prm)
{
	t_ray		ray;
	t_monitor	*screen;
	t_render	*render;
	int			x;

	x = 0;
	render = prm->ptr;
	screen = ft_take_last_arg(prm->dlist, ID_RES)->content;
	ray.img = my_mlx_new_image(render->mlx, screen->width, screen->height);
	ray.line_buff = malloc(screen->height * sizeof(int));
	if (ray.line_buff == NULL)
		return (MAL_ERR_BUFF);
	cast_x_rays(x, screen->width, &ray, prm);
	ft_img_update(&ray, prm);
	ft_move(prm);
	return (0);
}
