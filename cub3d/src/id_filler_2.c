/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_filler_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 20:28:32 by nfedayki          #+#    #+#             */
/*   Updated: 2021/05/17 17:56:48 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "cub_utils.h"
#include "macroses.h"
#include "ft_utils.h"

static int	hcc_clean_exit(int ret, void *elem)
{
	free(elem);
	return (ret);
}

static int	hcc_extract(unsigned int *hcc, int *j, char **buff)
{
	int		i;
	int		tmp;

	i = 0;
	while (buff[i] != NULL)
	{
		if (ft_strlen(buff[i]) != 0)
		{
			if (ft_contains_notset(buff[i], "0123456789"))
				return (WRONG_HCC_CHAR);
			tmp = ft_atoi_base(buff[i], "0123456789");
			if (tmp < 256 && tmp >= 0)
				*hcc += tmp << ((*j * 8) - 8);
			else
				return (WRONG_HCC_VAL);
			*j -= 1;
		}
		free(buff[i]);
		i++;
	}
	free(buff);
	if (*j < 0)
		return (WRONG_HCC_ELEM);
	else
		return (*j);
}

static int	create_hcc_list(t_param *prm, int id,
			t_hcc *hcc, const int *bitmask)
{
	ft_add_lst_back(&(prm->dlist), ft_lstnew(id, hcc));
	if (ft_take_last_arg(prm->dlist, id) == NULL)
		return (hcc_clean_exit(MAL_ERR_LIST, hcc));
	prm->booleans += bitmask[id - 6];
	return (0);
}

int	ft_hcc_filler(t_param *prm, char **elem, int id)
{
	int			i;
	int			j;
	t_hcc		*hcc;
	char		**buff;
	const int	bitmask[] = {HCC_F_SET, HCC_C_SET};

	if (prm->booleans & bitmask[id - 6])
		return (HCC_ALRD_SET);
	hcc = malloc(sizeof(t_hcc));
	if (hcc == NULL)
		return (MAL_ERR_HCC);
	i = 1;
	j = 3;
	hcc->hcc = 0;
	while (elem[i] != NULL)
	{
		buff = ft_split(elem[i], ",", 0, 0);
		j = hcc_extract(&(hcc->hcc), &j, buff);
		if (j < 0)
			return (hcc_clean_exit(j, hcc));
		i++;
	}
	if (j > 0)
		return (hcc_clean_exit(WRONG_HCC_ELEM, hcc));
	return (create_hcc_list(prm, id, hcc, bitmask));
}
