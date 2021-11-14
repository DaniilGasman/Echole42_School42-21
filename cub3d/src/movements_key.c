/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_key.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 20:48:34 by nfedayki          #+#    #+#             */
/*   Updated: 2021/05/13 06:12:53 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub_utils.h"
#include "macroses.h"
#include "struct.h"
#include "ft_utils.h"

int	ft_key_press(int keycode, t_param *prm)
{
	if (keycode == INPUT_ESC)
		return (ft_exit(0, prm));
	if (keycode == INPUT_UP && !(prm->booleans & FLAG_UP))
		prm->booleans += FLAG_UP;
	if (keycode == INPUT_DOWN && !(prm->booleans & FLAG_DOWN))
		prm->booleans += FLAG_DOWN;
	if (keycode == INPUT_LSTRAFE && !(prm->booleans & FLAG_LSTRAFE))
		prm->booleans += FLAG_LSTRAFE;
	if (keycode == INPUT_RSTRAFE && !(prm->booleans & FLAG_RSTRAFE))
		prm->booleans += FLAG_RSTRAFE;
	if (keycode == INPUT_LEFT && !(prm->booleans & FLAG_LEFT))
		prm->booleans += FLAG_LEFT;
	if (keycode == INPUT_RIGHT && !(prm->booleans & FLAG_RIGHT))
		prm->booleans += FLAG_RIGHT;
	return (0);
}

int	ft_key_release(int keycode, t_param *prm)
{
	if (keycode == INPUT_UP && prm->booleans & FLAG_UP)
		prm->booleans -= FLAG_UP;
	if (keycode == INPUT_DOWN && prm->booleans & FLAG_DOWN)
		prm->booleans -= FLAG_DOWN;
	if (keycode == INPUT_LSTRAFE && prm->booleans & FLAG_LSTRAFE)
		prm->booleans -= FLAG_LSTRAFE;
	if (keycode == INPUT_RSTRAFE && prm->booleans & FLAG_RSTRAFE)
		prm->booleans -= FLAG_RSTRAFE;
	if (keycode == INPUT_LEFT && prm->booleans & FLAG_LEFT)
		prm->booleans -= FLAG_LEFT;
	if (keycode == INPUT_RIGHT && prm->booleans & FLAG_RIGHT)
		prm->booleans -= FLAG_RIGHT;
	return (0);
}

int	ft_move(t_param *prm)
{
	if (prm->booleans & FLAG_UP)
		ft_forward(prm);
	if (prm->booleans & FLAG_DOWN)
		ft_backward(prm);
	if (prm->booleans & FLAG_LSTRAFE)
		ft_strafe_left(prm);
	if (prm->booleans & FLAG_RSTRAFE)
		ft_strafe_right(prm);
	if (prm->booleans & FLAG_LEFT)
		ft_rotate_left(prm);
	if (prm->booleans & FLAG_RIGHT)
		ft_rotate_right(prm);
	return (0);
}

void	ft_rotate_right(t_param *prm)
{
	double		old_dir_x;
	t_player	*player;
	t_config	*conf;

	conf = ft_take_last_arg(prm->dlist, ID_CONF)->content;
	player = ft_take_last_arg(prm->dlist, ID_PLAYER)->content;
	old_dir_x = player->dir.x;
	player->dir.x = (player->dir.x * cos(conf->rot_speed))
		- (player->dir.y * sin(conf->rot_speed));
	player->dir.y = (old_dir_x * sin(conf->rot_speed))
		+ (player->dir.y * cos(conf->rot_speed));
	player->plane.x = -player->dir.y * ((player->view_angle * M_PI) / 180.0);
	player->plane.y = player->dir.x * ((player->view_angle * M_PI) / 180.0);
}
