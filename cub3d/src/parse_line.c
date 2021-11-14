/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 20:37:43 by nfedayki          #+#    #+#             */
/*   Updated: 2021/05/12 23:25:06 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "cub_utils.h"
#include "macroses.h"
#include "ft_utils.h"

static int	clear_buffer(char **tmp, int ret)
{
	int	i;

	i = 0;
	while (tmp[i] != NULL)
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
	tmp = NULL;
	return (ret);
}

static int	check_identifier(char *str, char **id_strings)
{
	int	i;

	i = 0;
	while (id_strings[i] != NULL)
	{
		if (ft_strcmp(str, id_strings[i]))
			return (i);
		i++;
	}
	return (-1);
}

int	ft_parser_line(t_param *prm)
{
	t_parser	*ptr;
	char		**tmp;
	int			id;

	ptr = ((t_parser *)(prm->ptr));
	tmp = ft_split(ptr->buff, "\t\n\v\f\r' '", 0, 0);
	if (prm->booleans & MAP_SET)
		return (clear_buffer(tmp, CONF_AFTER_MAP));
	id = check_identifier(tmp[0], ptr->id_strings);
	if (id < 0)
		return (clear_buffer(tmp, WRONG_ID_STR));
	if (id == ID_RES)
		return (clear_buffer(tmp, ft_id_res_filler(prm, tmp)));
	else if (id >= ID_TX_NO && id <= ID_TX_S)
		return (clear_buffer(tmp, ft_id_path_filler(prm, tmp, id)));
	else if (id >= ID_HCC_F && id <= ID_HCC_C)
		return (clear_buffer(tmp, ft_hcc_filler(prm, tmp, id)));
	return (clear_buffer(tmp, 0));
}
