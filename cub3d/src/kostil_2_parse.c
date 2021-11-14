/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kostil_2_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 04:38:19 by nfedayki          #+#    #+#             */
/*   Updated: 2021/05/13 04:39:13 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "cub_utils.h"
#include "macroses.h"
#include "ft_utils.h"

int	foo(t_map *map, int fd, char *buff, int y)
{
	int	ret;

	ret = map->my;
	if (y == 0)
	{
		ret = map_check_line(map, buff);
		if (ret == 1)
			ret = gnl_map_extract(map, fd, buff, y + 1);
		if (map->grid != NULL)
		{
			map->grid[y] = ft_strdup(buff);
			if (map->grid[y] == NULL)
				return (0);
		}
	}
	map->my = ret;
	return (map->my);
}

int	foo2(t_map *map, char *tmp, int y)
{
	if (map->grid != NULL)
	{
		map->grid[y] = ft_strdup(tmp);
		if (map->grid[y] == NULL)
			return (0);
	}
	return (1);
}
