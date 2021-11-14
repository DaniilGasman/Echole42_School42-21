/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 20:38:17 by nfedayki          #+#    #+#             */
/*   Updated: 2021/05/16 20:46:15 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "cub_utils.h"
#include "struct.h"
#include "macroses.h"
#include "ft_utils.h"

static int	player_clean_exit(int ret, t_player *player)
{
	free(player);
	return (ret);
}

static void	player_set_dir(t_player *player, int dir_x, int dir_y)
{
	player->view_angle = 32.5;
	player->dir.x = dir_x;
	player->dir.y = dir_y;
	player->plane.x = -player->dir.y * ((player->view_angle * M_PI) / 180);
	player->plane.y = player->dir.x * ((player->view_angle * M_PI) / 180);
}

static int	player_set_start(t_param *prm, int x, int y, t_player *player)
{
	t_map	*map;
	char	dir;

	map = (t_map *)(ft_take_last_arg(prm->dlist, ID_MAP)->content);
	dir = map->grid[y][x];
	if (prm->booleans & START_SET)
		return (START_ALRD_SET);
	if (dir == 'N')
		player_set_dir(player, 0.0, -1.0);
	if (dir == 'S')
		player_set_dir(player, 0.0, 1.0);
	if (dir == 'W')
		player_set_dir(player, -1.0, 0.0);
	if (dir == 'E')
		player_set_dir(player, 1.0, 0.0);
	player->pos.x = x + 0.5;
	player->pos.y = y + 0.5;
	prm->booleans += START_SET;
	return (0);
}

static int	create_player_dlist(t_param *prm, t_player *player)
{
	if (!(prm->booleans & START_SET))
		return (player_clean_exit(NO_START_POS, player));
	ft_add_lst_back(&(prm->dlist), ft_lstnew(ID_PLAYER, player));
	if (ft_take_last_arg(prm->dlist, ID_PLAYER) == NULL)
		return (player_clean_exit(MAL_ERR_LIST, player));
	return (0);
}

int	ft_player_init(t_param *prm)
{
	t_player	*player;
	t_map		*map;
	int			ret;
	int			x;
	int			y;

	player = malloc(sizeof(t_player));
	if (player == NULL)
		return (MAL_ERR_PLAYER);
	map = (t_map *)(ft_take_last_arg(prm->dlist, ID_MAP)->content);
	y = -1;
	while (map->grid[++y])
	{
		x = -1;
		while (map->grid[y][++x])
		{
			if (ft_isset(map->grid[y][x], MAP_START))
			{
				ret = player_set_start(prm, x, y, player);
				if (ret < 0)
					return (player_clean_exit(ret, player));
			}
		}
	}
	return (create_player_dlist(prm, player));
}
