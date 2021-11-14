/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 18:28:57 by nfedayki          #+#    #+#             */
/*   Updated: 2021/07/20 16:23:12 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

char	**copy_args(t_data *prm)
{
	int		i;
	char	**args;

	i = 0;
	while (prm->argv[i] && ft_memcmp(prm->argv[i], "<", 2))
		i++;
	args = ft_calloc(sizeof(char *), i + 1);
	i = 0;
	while (prm->argv[i] && ft_memcmp(prm->argv[i], "<", 2))
	{
		args[i] = ft_strdup(prm->argv[i]);
		i++;
	}
	return (args);
}

char	*your_mom(char **paths, int i)
{
	char	*path;

	path = ft_strjoin(paths[i], "/");
	free_matrix(paths);
	return (path);
}

int	reread(DIR **dir, struct dirent **d)
{
	*d = readdir(*dir);
	if (*d)
		return (1);
	return (0);
}

int	exceptions(t_data *prm, char *c)
{
	if (!prm->str || !ft_memcmp(prm->str, c, 2))
	{
		if (prm->str)
		{
			printf("-bash12; syntax error near unexpected token ` %s'\n", c);
			prm->ret = 2;
		}
		free(prm->str);
		prm->str = 0;
		return (1);
	}
	return (0);
}
