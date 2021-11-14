/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 20:37:34 by nfedayki          #+#    #+#             */
/*   Updated: 2021/05/13 06:14:29 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub_utils.h"
#include "macroses.h"
#include "struct.h"
#include "ft_utils.h"

void	ft_forward(t_param *prm)
{
	t_player	*player;
	t_map		*map;
	t_config	*conf;

	conf = ft_take_last_arg(prm->dlist, ID_CONF)->content;
	player = ft_take_last_arg(prm->dlist, ID_PLAYER)->content;
	map = ft_take_last_arg(prm->dlist, ID_MAP)->content;
	if ((int)(player->pos.y) >= 0 && (int)(player->pos.y) <= map->size_y
			&& (int)(player->pos.x + player->dir.x * conf->front_speed) >= 0
			&& (int)(player->pos.x + player->dir.x * conf->front_speed)
				<= map->size_x && (int)(player->pos.x) >= 0
			&& (int)(player->pos.x) <= map->size_x
			&& (int)(player->pos.y + player->dir.y * conf->front_speed) >= 0
			&& (int)(player->pos.y + player->dir.y * conf->front_speed)
				<= map->size_y)
	{
		if (!ft_isset(map->grid[(int)(player->pos.y)]
			[(int)(player->pos.x + player->dir.x * conf->front_speed)],
					MAP_OBSTACLE))
			player->pos.x += player->dir.x * conf->front_speed;
		if (!ft_isset(map->grid[(int)(player->pos.y
					+ player->dir.y * conf->front_speed)]
			[(int)(player->pos.x)], MAP_OBSTACLE))
			player->pos.y += player->dir.y * conf->front_speed;
	}
}

void	ft_backward(t_param *prm)
{
	t_player	*player;
	t_map		*map;
	t_config	*conf;

	conf = ft_take_last_arg(prm->dlist, ID_CONF)->content;
	player = ft_take_last_arg(prm->dlist, ID_PLAYER)->content;
	map = ft_take_last_arg(prm->dlist, ID_MAP)->content;
	if ((int)(player->pos.y) >= 0 && (int)(player->pos.y) <= map->size_y
			&& (int)(player->pos.x - player->dir.x * conf->back_speed) >= 0
			&& (int)(player->pos.x - player->dir.x * conf->back_speed)
				<= map->size_x && (int)(player->pos.x) >= 0
			&& (int)(player->pos.x) <= map->size_x
			&& (int)(player->pos.y - player->dir.y * conf->back_speed) >= 0
			&& (int)(player->pos.y - player->dir.y * conf->back_speed)
				<= map->size_y)
	{
		if (!ft_isset(map->grid[(int)(player->pos.y)]
			[(int)(player->pos.x - player->dir.x * conf->back_speed)],
					MAP_OBSTACLE))
			player->pos.x -= player->dir.x * conf->back_speed;
		if (!ft_isset(map->grid[(int)(player->pos.y
					- player->dir.y * conf->back_speed)]
			[(int)(player->pos.x)], MAP_OBSTACLE))
			player->pos.y -= player->dir.y * conf->back_speed;
	}
}

void	ft_strafe_left(t_param *prm)
{
	t_player	*player;
	t_map		*map;
	t_config	*conf;

	conf = ft_take_last_arg(prm->dlist, ID_CONF)->content;
	player = ft_take_last_arg(prm->dlist, ID_PLAYER)->content;
	map = ft_take_last_arg(prm->dlist, ID_MAP)->content;
	if ((int)(player->pos.y) >= 0 && (int)(player->pos.y) <= map->size_y
			&& (int)(player->pos.x + player->dir.y * conf->strafe_speed) >= 0
			&& (int)(player->pos.x + player->dir.y * conf->strafe_speed)
				<= map->size_x && (int)(player->pos.x) >= 0
			&& (int)(player->pos.x) <= map->size_x
			&& (int)(player->pos.y - player->dir.x * conf->strafe_speed) >= 0
			&& (int)(player->pos.y - player->dir.x * conf->strafe_speed)
				<= map->size_y)
	{
		if (!ft_isset(map->grid[(int)(player->pos.y)]
			[(int)(player->pos.x + player->dir.y * conf->strafe_speed)],
						MAP_OBSTACLE))
			player->pos.x += player->dir.y * conf->strafe_speed;
		if (!ft_isset(map->grid[(int)(player->pos.y
					- player->dir.x * conf->strafe_speed)]
			[(int)(player->pos.x)], MAP_OBSTACLE))
			player->pos.y -= player->dir.x * conf->strafe_speed;
	}
}

void	ft_strafe_right(t_param *prm)
{
	t_player	*player;
	t_map		*map;
	t_config	*conf;

	conf = ft_take_last_arg(prm->dlist, ID_CONF)->content;
	player = ft_take_last_arg(prm->dlist, ID_PLAYER)->content;
	map = ft_take_last_arg(prm->dlist, ID_MAP)->content;
	if ((int)(player->pos.y) >= 0 && (int)(player->pos.y) <= map->size_y
			&& (int)(player->pos.x - player->dir.y * conf->strafe_speed) >= 0
			&& (int)(player->pos.x - player->dir.y * conf->strafe_speed)
				<= map->size_x && (int)(player->pos.x) >= 0
			&& (int)(player->pos.x) <= map->size_x
			&& (int)(player->pos.y + player->dir.x * conf->strafe_speed) >= 0
			&& (int)(player->pos.y + player->dir.x * conf->strafe_speed)
				<= map->size_y)
	{
		if (!ft_isset(map->grid[(int)(player->pos.y)]
			[(int)(player->pos.x
				- player->dir.y * conf->strafe_speed)], MAP_OBSTACLE))
			player->pos.x -= player->dir.y * conf->strafe_speed;
		if (!ft_isset(map->grid[(int)(player->pos.y
					+ player->dir.x * conf->strafe_speed)]
			[(int)(player->pos.x)], MAP_OBSTACLE))
			player->pos.y += player->dir.x * conf->strafe_speed;
	}
}

void	ft_rotate_left(t_param *prm)
{
	double		old_dir_x;
	t_player	*player;
	t_config	*conf;

	conf = ft_take_last_arg(prm->dlist, ID_CONF)->content;
	player = ft_take_last_arg(prm->dlist, ID_PLAYER)->content;
	old_dir_x = player->dir.x;
	player->dir.x = (player->dir.x * cos(-conf->rot_speed))
		- (player->dir.y * sin(-conf->rot_speed));
	player->dir.y = (old_dir_x * sin(-conf->rot_speed))
		+ (player->dir.y * cos(-conf->rot_speed));
	player->plane.x = -player->dir.y * ((player->view_angle * M_PI) / 180.0);
	player->plane.y = player->dir.x * ((player->view_angle * M_PI) / 180.0);
}
