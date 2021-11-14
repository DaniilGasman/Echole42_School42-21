/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_engine_ray.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 20:41:18 by nfedayki          #+#    #+#             */
/*   Updated: 2021/05/13 05:38:47 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "mlx.h"
#include "cub_utils.h"
#include "ft_utils.h"
#include "macroses.h"
#include "struct.h"

static void	ray_increment(t_ray *ray)
{
	if (ray->side_dist.x < ray->side_dist.y)
	{
		ray->side_dist.x += ray->delta_dist.x;
		ray->map.x += ray->step.x;
		ray->id_side = ray->side.x;
	}
	else
	{
		ray->side_dist.y += ray->delta_dist.y;
		ray->map.y += ray->step.y;
		ray->id_side = ray->side.y;
	}
}

void	ft_ray_hits_scan(t_ray *ray, t_param *prm)
{
	t_player	*player;
	t_map		*map;
	t_sprite	*new;

	player = ft_take_last_arg(prm->dlist, ID_PLAYER)->content;
	map = ft_take_last_arg(prm->dlist, ID_MAP)->content;
	while (ray->hit == 0)
	{
		ray_increment(ray);
		if (!((ray->map.y >= 0 && ray->map.y <= map->size_y) && (ray->map.x >= 0
					&& ray->map.x <= ft_strlen(map->grid[(int)ray->map.y]))))
			return ;
		if (map->grid[ray->map.y][ray->map.x] == '1')
			ray->hit = 1;
		else if (map->grid[ray->map.y][ray->map.x] == '2')
		{
			new = ft_new_sprite_create(ray->map.x, ray->map.y);
			new->dist = ((player->pos.x - new->pos.x)
					* (player->pos.x - new->pos.x)
					+ (player->pos.y - new->pos.y)
					* (player->pos.y - new->pos.y));
			ft_put_sprite_front(&ray->sprites, new);
		}
	}
}

void	ft_ray_perspective(t_ray *ray, t_param *prm)
{
	t_player	*player;
	t_monitor	*screen;

	player = ft_take_last_arg(prm->dlist, ID_PLAYER)->content;
	screen = ft_take_last_arg(prm->dlist, ID_RES)->content;
	if (ray->id_side % 2 == 0)
		ray->perp_wall_dist = (ray->map.x - player->pos.x
				+ (1 - ray->step.x) / 2) / ray->dir.x;
	else
		ray->perp_wall_dist = (ray->map.y - player->pos.y
				+ (1 - ray->step.y) / 2) / ray->dir.y;
	ray->line_height = (int)(screen->height / ray->perp_wall_dist);
	ray->draw_start = (-ray->line_height / 2) + (screen->height / 2);
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = (ray->line_height / 2) + (screen->height / 2);
	if (ray->draw_end >= screen->height)
		ray->draw_end = screen->height - 1;
}

static void	side_texture(t_ray *ray, t_param *prm)
{
	if (ray->id_side == 0)
		ray->tx_ptr = ft_take_last_arg(prm->dlist, ID_TX_WE)->content;
	else if (ray->id_side == 1)
		ray->tx_ptr = ft_take_last_arg(prm->dlist, ID_TX_NO)->content;
	else if (ray->id_side == 2)
		ray->tx_ptr = ft_take_last_arg(prm->dlist, ID_TX_EA)->content;
	else if (ray->id_side == 3)
		ray->tx_ptr = ft_take_last_arg(prm->dlist, ID_TX_SO)->content;
}

void	ft_ray_texture(t_ray *ray, t_param *prm)
{
	t_player	*player;
	t_monitor	*screen;

	player = ft_take_last_arg(prm->dlist, ID_PLAYER)->content;
	screen = ft_take_last_arg(prm->dlist, ID_RES)->content;
	side_texture(ray, prm);
	if (ray->id_side % 2 == 0)
		ray->wall_x = player->pos.y + ray->perp_wall_dist * ray->dir.y;
	else
		ray->wall_x = player->pos.x + ray->perp_wall_dist * ray->dir.x;
	ray->wall_x -= floor(ray->wall_x);
	ray->tex.x = (int)(ray->wall_x * (double)(ray->tx_ptr->width));
	if ((ray->id_side % 2 == 0) && ray->dir.x > 0)
		ray->tex.x = ray->tx_ptr->width - ray->tex.x - 1;
	if (ray->id_side % 2 == 1 && ray->dir.y < 0)
		ray->tex.x = ray->tx_ptr->width - ray->tex.x - 1;
	ray->tex_step = 1.0 * ray->tx_ptr->height / ray->line_height;
	ray->tex_pos = (ray->draw_start - screen->height / 2 + ray->line_height / 2)
		* ray->tex_step;
}
