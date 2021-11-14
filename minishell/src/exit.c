/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dminerva <dminerva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 18:06:19 by nfedayki          #+#    #+#             */
/*   Updated: 2021/07/19 18:31:16 by dminerva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	free_param(t_data *prm)
{
	free(prm->str);
	free_matrix(prm->env);
	free_matrix(prm->export);
	free_matrix(prm->argv);
	free_matrix(prm->cmds);
	free(prm);
}

void	exit_command(t_data *prm)
{
	int	i;

	if (prm->argc > 2)
	{
		ft_putstrs_fd("exit\n", "bash8: exit: too many arguments\n", 0, 2);
		prm->ret = 1;
	}
	else
	{
		i = 0;
		while (prm->argc > 1 && ft_isdigit(prm->argv[1][i]))
			i++;
		if (prm->argc > 1 && prm->argv[1][i])
		{
			ft_putstrs_fd("exit\nbash9: exit: ",
				prm->argv[1], ": numeric argument required\n", 2);
			prm->ret = 2;
		}
		if (prm->argc > 1 && prm->ret != 2)
			i = ft_atoi(prm->argv[1]);
		free_param(prm);
		exit(i);
	}
}
