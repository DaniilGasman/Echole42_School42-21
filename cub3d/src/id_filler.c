/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 20:29:12 by nfedayki          #+#    #+#             */
/*   Updated: 2021/05/16 20:39:32 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "cub_utils.h"
#include "macroses.h"
#include "ft_utils.h"

static int	elem_count(char **elem)
{
	int		i;

	i = 0;
	while (elem[i] != NULL)
		i++;
	return (i);
}

static int	id_clean_exit(int ret, void *elem)
{
	free(elem);
	return (ret);
}

int	ft_id_res_filler(t_param *prm, char **elem)
{
	t_monitor	*screen;

	if (prm->booleans & RES_SET)
		return (RES_ALRD_SET);
	if (elem_count(elem) != 3)
		return (WRONG_RES_ELEM);
	if (ft_contains_notset(elem[1], "0123456789")
		|| ft_contains_notset(elem[2], "0123456789"))
		return (WRONG_RES_CHAR);
	screen = malloc(sizeof(t_monitor));
	if (screen == NULL)
		return (MAL_ERR_SCREEN);
	screen->width = ft_atoi_base(elem[1], "0123456789");
	if (screen->width <= 0)
		return (RES_OVERFLOW);
	screen->height = ft_atoi_base(elem[2], "0123456789");
	if (screen->height <= 0)
		return (RES_OVERFLOW);
	ft_add_lst_back(&(prm->dlist), ft_lstnew(ID_RES, screen));
	if (ft_take_last_arg(prm->dlist, ID_RES) == NULL)
		return (id_clean_exit(MAL_ERR_LIST, screen));
	prm->booleans += RES_SET;
	return (0);
}

int	ft_id_path_filler(t_param *prm, char **elem, int id)
{
	int			fd;
	char		*path;
	char		tmp;
	const int	bitmask[] = {0, TX_NO_SET, TX_SO_SET, TX_WE_SET,
		TX_EA_SET, TX_S_SET};

	path = NULL;
	if (prm->booleans & bitmask[id])
		return (TX_ALRD_SET);
	if (elem_count(elem) != 2)
		return (WRONG_TX_ELEM);
	if (!ft_ext_check(elem[1], ".xpm"))
		return (WRONG_FILE_EXT);
	fd = open(elem[1], O_RDONLY);
	if (read(fd, &tmp, 0) < 0)
		return (id_clean_exit(WRONG_TX_PATH, path));
	path = ft_strdup(elem[1]);
	if (path == NULL)
		return (MAL_ERR_TX_PATH);
	ft_add_lst_back(&(prm->dlist), ft_lstnew(id, path));
	if (ft_take_last_arg(prm->dlist, id) == NULL)
		return (id_clean_exit(MAL_ERR_LIST, path));
	prm->booleans += bitmask[id];
	return (0);
}
