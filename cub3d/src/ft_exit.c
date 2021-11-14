/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 20:27:44 by nfedayki          #+#    #+#             */
/*   Updated: 2021/05/12 19:30:21 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "cub_utils.h"
#include "macroses.h"
#include "ft_utils.h"

int	ft_parserr_clean(t_param *prm)
{
	t_parser	*tmp;
	int			i;

	if (prm->ptr != NULL)
	{
		tmp = ((t_parser *)(prm->ptr));
		if (tmp->buff != NULL)
			free(tmp->buff);
		i = 0;
		if (tmp->id_strings != NULL)
		{
			while (tmp->id_strings[i] != NULL)
			{
				free(tmp->id_strings[i]);
				i++;
			}
			free(tmp->id_strings);
		}
		free(prm->ptr);
		prm->ptr = NULL;
	}
	return (0);
}

int	ft_clean_render(t_param *prm)
{
	int			i;
	t_list		*ptr;
	t_render	*render;

	i = ID_TX_NO;
	if (prm->ptr != NULL)
	{
		render = ((t_render *)(prm->ptr));
		while (i <= ID_TX_S)
		{
			ptr = ft_take_last_arg(prm->dlist, i);
			my_mlx_destroy_tx(render->mlx, ptr);
			i++;
		}
		if (render->current.img != NULL)
			mlx_destroy_image(render->mlx, render->current.img);
		if (render->win != NULL)
			mlx_destroy_window(render->mlx, render->win);
		if (render->mlx != NULL)
			free(render->mlx);
		free(render);
	}
	return (0);
}

int	ft_exit(int err_code, t_param *prm)
{
	if (prm->booleans < PARSE_END)
		ft_parserr_clean(prm);
	else
		ft_clean_render(prm);
	ft_dlist_clear(&prm->dlist);
	if (err_code >= 0)
		exit(0);
	else
		return (ft_error(err_code));
}

int	ft_x_exit(t_param *prm)
{
	return (ft_exit(0, prm));
}
