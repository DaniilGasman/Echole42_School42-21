/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_trigger.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 20:38:08 by nfedayki          #+#    #+#             */
/*   Updated: 2021/05/16 20:07:17 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "cub_utils.h"
#include "macroses.h"
#include "ft_utils.h"

static int	ft_open_path(t_parser *tmp)
{
	tmp->id_strings = ft_split(ID_STRINGS, "/", 0, 0);
	if (tmp->id_strings == NULL)
		return (ID_SPLIT_ERR);
	tmp->fd = open(tmp->buff, O_RDONLY);
	free(tmp->buff);
	tmp->buff = 0;
	if (read(tmp->fd, &tmp->buff, 0) < 0)
		return (WRONG_FILE_PATH);
	return (1);
}

static int	ft_conf_check(t_param *prm)
{
	int			e;

	if ((prm->booleans & CONF_SET) != CONF_SET)
		return (ft_exit(MISS_CONF_INFO, prm));
	if (!(prm->booleans & MAP_SET))
		return (ft_exit(NO_MAP_FOUND, prm));
	e = ft_player_init(prm);
	if (e < 0)
		return (ft_exit(e, prm));
	ft_parserr_clean(prm);
	return (ft_game_struct_init(prm, 0, 0, 0));
}

int	all_4_new_norme(t_parser *tmp, t_param *prm, int ret)
{
	while (ft_recurcive_gnl(tmp->fd, &tmp->buff) >= 1)
	{
		if (ft_isset(tmp->buff[0], "RNSWEFC"))
		{
			ret = ft_parser_line(prm);
			if (ret < 0)
				return (ft_exit(ret, prm));
		}
		else if (ft_isset(tmp->buff[0], MAP_VALID_CHAR)
			|| ft_isset(tmp->buff[0], "\t\n\v\f\r' '"))
		{
			ret = ft_parser_map(prm);
			if (ret < 0)
				return (ft_exit(ret, prm));
		}
		else if (ft_strlen(tmp->buff) > 0)
			return (ft_exit(NOT_ID_CHAR, prm));
		free(tmp->buff);
		tmp->buff = NULL;
	}
	return (ft_conf_check(prm));
}

int	ft_trigger_parse(t_param *prm)
{
	t_parser	*tmp;
	int			ret;

	tmp = ((t_parser *)(prm->ptr));
	ret = ft_open_path(tmp);
	if (ret < 0)
		return (ft_exit(ret, prm));
	all_4_new_norme(tmp, prm, ret);
	return (0);
}
