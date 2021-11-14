/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 20:29:46 by nfedayki          #+#    #+#             */
/*   Updated: 2021/05/17 17:03:38 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "macroses.h"
#include "cub_utils.h"
#include "ft_utils.h"

static int	ft_param_init(t_param *prm)
{
	t_parser	*parse_struct;

	prm->booleans = 0;
	prm->dlist = NULL;
	parse_struct = malloc(sizeof(t_parser));
	if (parse_struct == NULL)
	{
		prm->ptr = NULL;
		return (0);
	}
	parse_struct->buff = NULL;
	parse_struct->id_strings = NULL;
	prm->ptr = parse_struct;
	return (1);
}

int	main(int argc, char **argv)
{
	t_param	prm;

	if (!(ft_param_init(&prm)))
		return (ft_exit(MAL_ERR_PARSE_STRUCT, &prm));
	if (argc == 2 || argc == 3)
	{
		if (argc == 3)
		{
			if (!(ft_strcmp(argv[2], "--save")))
				return (ft_exit(BMP_FILED, &prm));
			prm.booleans += BMP_SAVE;
		}
		if (ft_ext_check(argv[1], ".cub"))
		{
			((t_parser *)(prm.ptr))->buff = ft_strdup(argv[1]);
			if (((t_parser *)(prm.ptr))->buff == NULL)
				return (ft_exit(MAL_ERR_FILENAME, &prm));
			ft_trigger_parse(&prm);
		}
		else
			return (ft_exit(WRONG_FILE_EXT, &prm));
	}
	else
		return (ft_exit(WRONG_ARG_NUM, &prm));
	return (1);
}
