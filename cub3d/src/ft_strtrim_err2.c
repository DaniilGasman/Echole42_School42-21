/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_err2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 20:28:02 by nfedayki          #+#    #+#             */
/*   Updated: 2021/05/17 17:08:00 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "macroses.h"
#include <stdlib.h>

static int	ft_mlx_error(int err_code)
{
	ft_putstr("MLX_ERROR : ");
	if (err_code == MAL_ERR_PARSE_STRUCT)
		ft_putstr("Parsing structure allocation failed\n");
	if (err_code == TX_IMPORT_FAIL)
		ft_putstr("Failed importing textures to mlx.\n");
	if (err_code == MAL_ERR_CONF)
		ft_putstr("Error creating configuration data structure\n");
	if (err_code == MAL_ERR_BUFF)
		ft_putstr("Error creating configuration vertical line buffer\n");
	if (err_code == IMPORT_FAILURE)
		ft_putstr("Texture file is corrupted or invalid\n");
	exit(0);
}

int	ft_render_errors(int err_code)
{
	if (err_code >= -80)
		return (ft_mlx_error(err_code));
	exit(0);
}
