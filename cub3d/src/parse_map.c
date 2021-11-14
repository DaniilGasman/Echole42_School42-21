/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 20:37:53 by nfedayki          #+#    #+#             */
/*   Updated: 2021/05/17 17:05:00 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "cub_utils.h"
#include "macroses.h"
#include "ft_utils.h"

static int	map_clean_exit(int ret, t_map *map)
{
	int	i;

	i = 0;
	if (map->grid != NULL)
	{
		while (map->grid[i])
		{
			free(map->grid[i]);
			map->grid[i] = NULL;
			i++;
		}
		free(map->grid);
		map->grid = NULL;
	}
	free(map);
	return (ret);
}

int	map_check_line(t_map *map, char *tmp)
{
	int	x;

	x = 0;
	if (ft_strlen(tmp) == 0)
		return (0);
	while (tmp[x])
	{
		if (ft_isset(tmp[x], MAP_VALID_CHAR))
			x++;
		else
			return (MAP_CHAR_INVALID);
	}
	if (x > map->size_x)
		map->size_x = x;
	return (1);
}

static int	gnl_map_alloc(t_map *map, char *tmp, int y)
{
	if (map->grid == NULL)
	{
		map->size_y = y;
		map->grid = malloc((map->size_y + 1) * sizeof(char *));
		if (map->grid == NULL)
			return (MAL_ERR_GRID);
		map->grid[y] = NULL;
		free(tmp);
		tmp = NULL;
		return (2);
	}
	else
		return (MAP_ALRD_SET);
}

int	gnl_map_extract(t_map *map, int fd, char *buff, int y)
{
	int		ret;
	char	*tmp;

	tmp = NULL;
	ret = map_check_line(map, buff);
	map->my = ret;
	if (foo(map, fd, buff, y) == 0)
		return (MAL_ERR_MAP_DUP);
	else
		ret = map->my;
	ret = ft_recurcive_gnl(fd, &tmp);
	if (ret >= 0 && y != 0)
	{
		ret = map_check_line(map, tmp);
		if (ret == 1)
			ret = gnl_map_extract(map, fd, buff, y + 1);
		if (foo2(map, tmp, y) == 0)
			return (MAL_ERR_MAP_DUP);
	}
	if (ret == 0)
		return (gnl_map_alloc(map, tmp, y));
	free(tmp);
	tmp = NULL;
	return (ret);
}

int	ft_parser_map(t_param *prm)
{
	int			ret;
	t_map		*map;
	t_parser	*tmp;

	if (prm->booleans & MAP_SET)
		return (MAP_ALRD_SET);
	tmp = ((t_parser *)(prm->ptr));
	map = malloc(sizeof(t_map));
	if (map == NULL)
		return (MAL_ERR_MAP);
	map->grid = NULL;
	map->size_x = 0;
	map->size_y = 0;
	ret = gnl_map_extract(map, tmp->fd, tmp->buff, 0);
	if (ret < 0)
		return (map_clean_exit(ret, map));
	free(tmp->buff);
	tmp->buff = NULL;
	ft_add_lst_back(&(prm->dlist), ft_lstnew(ID_MAP, map));
	if (ft_take_last_arg(prm->dlist, ID_MAP) == NULL)
		return (map_clean_exit(MAL_ERR_LIST, map));
	prm->booleans += MAP_SET;
	return (ft_map_control(prm, 0, 0));
}
