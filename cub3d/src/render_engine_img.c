/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_engine_img.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 20:39:31 by nfedayki          #+#    #+#             */
/*   Updated: 2021/05/13 05:36:12 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "mlx.h"
#include "cub_utils.h"
#include "ft_utils.h"
#include "macroses.h"
#include "struct.h"

void	ft_img_update(t_ray *ray, t_param *prm)
{
	t_render	*render;

	render = prm->ptr;
	if (prm->booleans & IMG_SET)
	{
		mlx_destroy_image(render->mlx, render->current.img);
		render->current.addr = NULL;
	}
	else
		prm->booleans += IMG_SET;
	free(ray->line_buff);
	render->current = ray->img;
	mlx_put_image_to_window(render->mlx, render->win,
		render->current.img, 0, 0);
}

int	kak_nadoelo(t_ray *ray, int y)
{
	while (++y <= ray->draw_end)
	{
		if (ray->tex_pos < 0)
			ray->tex.y = 0;
		else
			ray->tex.y = (int)ray->tex_pos;
		if (ray->tex.y >= ray->tx_ptr->height)
			ray->tex.y = ray->tx_ptr->height - 1;
		ray->tex_pos += ray->tex_step;
		ray->color = my_get_pixel_color(ray->tex.x, ray->tex.y,
				&ray->tx_ptr->data);
		ray->line_buff[y] = ray->color;
	}
	return (y);
}

void	ft_fill_buff(t_ray *ray, t_param *prm)
{
	int			y;
	t_hcc		*hcc;
	t_monitor	*screen;

	y = -1;
	screen = ft_take_last_arg(prm->dlist, ID_RES)->content;
	hcc = ft_take_last_arg(prm->dlist, ID_HCC_C)->content;
	while (++y < ray->draw_start)
		ray->line_buff[y] = hcc->hcc;
	y -= 1;
	hcc = ft_take_last_arg(prm->dlist, ID_HCC_F)->content;
	y = kak_nadoelo(ray, y) - 1;
	while (++y < screen->height)
		ray->line_buff[y] = hcc->hcc;
}

void	ft_fill_line(int x, t_ray *ray, t_param *prm)
{
	int			y;
	t_monitor	*screen;

	y = 0;
	screen = ft_take_last_arg(prm->dlist, ID_RES)->content;
	while (y < screen->height)
	{
		my_mlx_pixel_put(&ray->img, x, y, ray->line_buff[y]);
		y++;
	}
}
