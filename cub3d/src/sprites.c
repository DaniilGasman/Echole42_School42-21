/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 20:42:19 by nfedayki          #+#    #+#             */
/*   Updated: 2021/05/13 05:59:02 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "cub_utils.h"
#include "struct.h"
#include "macroses.h"
#include "ft_utils.h"

void	ft_calc_sprite_draw_val(t_sprite *ptr, t_param *prm)
{
	t_monitor	*screen;

	screen = ft_take_last_arg(prm->dlist, ID_RES)->content;
	ptr->draw_start.y = -ptr->sprite_height / 2 + screen->height / 2;
	if (ptr->draw_start.y < 0)
		ptr->draw_start.y = 0;
	ptr->draw_end.y = ptr->sprite_height / 2 + screen->height / 2;
	if (ptr->draw_end.y >= screen->height)
		ptr->draw_end.y = screen->height - 1;
	ptr->sprite_width = abs((int)(screen->height / (ptr->transform.y)));
	ptr->draw_start.x = -ptr->sprite_width / 2 + ptr->sprite_screen_x;
	if (ptr->draw_start.x < 0)
		ptr->draw_start.x = 0;
	ptr->draw_end.x = ptr->sprite_width / 2 + ptr->sprite_screen_x;
	if (ptr->draw_end.x >= screen->width)
		ptr->draw_end.x = screen->width - 1;
}

void	ft_sprite_building(t_ray *ray, t_param *prm)
{
	t_sprite	*ptr;
	t_monitor	*screen;
	t_player	*player;

	ptr = ray->sprites;
	screen = ft_take_last_arg(prm->dlist, ID_RES)->content;
	player = ft_take_last_arg(prm->dlist, ID_PLAYER)->content;
	while (ptr != NULL)
	{
		ptr->sprite.x = ptr->pos.x - player->pos.x + 0.5;
		ptr->sprite.y = ptr->pos.y - player->pos.y + 0.5;
		ptr->inv_det = 1.0 / (player->plane.x * player->dir.y
				- player->dir.x * player->plane.y);
		ptr->transform.x = ptr->inv_det * (player->dir.y * ptr->sprite.x
				- player->dir.x * ptr->sprite.y);
		ptr->transform.y = ptr->inv_det * (-player->plane.y * ptr->sprite.x
				+ player->plane.x * ptr->sprite.y);
		ptr->sprite_screen_x = (int)(((double)screen->width / 2)
				* (1 + ptr->transform.x / ptr->transform.y));
		ptr->sprite_height = abs((int)((double)screen->height
					/ (ptr->transform.y)));
		ft_calc_sprite_draw_val(ptr, prm);
		ptr = ptr->next;
	}
}

void	ft_sprite_line_to_buff(t_sprite *ptr, t_ray *ray, t_param *prm)
{
	int			y;
	int			d;
	t_texture	*tx;
	t_monitor	*screen;

	y = ptr->draw_start.y;
	tx = ft_take_last_arg(prm->dlist, ID_TX_S)->content;
	screen = ft_take_last_arg(prm->dlist, ID_RES)->content;
	while (y < ptr->draw_end.y)
	{
		d = (y) * 256 - (screen->height - 1) * 128
			+ (ptr->sprite_height - 1) * 128;
		ptr->tex.y = (((d * (tx->height - 1))
					/ (ptr->sprite_height - 1)) / 256);
		if (ptr->tex.y < 0)
			ptr->tex.y = 0;
		if (ptr->tex.y >= tx->height)
			ptr->tex.y = tx->height - 1;
		ray->color = my_get_pixel_color(ptr->tex.x, ptr->tex.y,
				&tx->data);
		if ((ray->color & 0x00FFFFFF) != 0)
			ray->line_buff[y] = ray->color;
		y++;
	}
}

void	ft_ft_fill_line_sprite(int x, t_ray *ray, t_param *prm, t_sprite *ptr)
{
	t_texture	*tx;
	t_monitor	*screen;

	ptr = ray->sprites;
	tx = ft_take_last_arg(prm->dlist, ID_TX_S)->content;
	screen = ft_take_last_arg(prm->dlist, ID_RES)->content;
	while (ptr != NULL)
	{
		if (x >= ptr->draw_start.x && x <= ptr->draw_end.x)
		{
			ptr->tex.x = (int)((256 * (x - (-(double)ptr->sprite_width / 2
								+ (double)ptr->sprite_screen_x))
						* (double)(tx->width - 1)
						/ (double)(ptr->sprite_width - 1))
					/ 256);
			if (ptr->tex.x < 0)
				ptr->tex.x = 0;
			if (ptr->tex.x >= tx->height)
				ptr->tex.x = tx->height - 1;
			if (ptr->transform.y > 0 && x > 0 && x
				< screen->width && ptr->transform.y < ray->perp_wall_dist)
				ft_sprite_line_to_buff(ptr, ray, prm);
		}
		ptr = ptr->next;
	}
}
