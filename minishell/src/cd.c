/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dminerva <dminerva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 17:21:01 by nfedayki          #+#    #+#             */
/*   Updated: 2021/07/19 18:01:13 by dminerva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

char	**export_command(t_data *prm, int j)
{
	int		i;
	char	**cpy;

	i = 0;
	while (prm->env[i] && ft_memcmp(prm->env[i],
			prm->argv[j], ft_strlen(prm->argv[j])))
		i++;
	if (!prm->env[i])
	{
		cpy = env_cpy(prm->env, 1);
		cpy[i] = ft_strjoin(prm->argv[j], prm->argv[j + 1]);
		free_matrix(prm->env);
	}
	else
	{
		cpy = prm->env;
		free(prm->env[i]);
		prm->env[i] = ft_strjoin(prm->argv[j], prm->argv[j + 1]);
	}
	return (cpy);
}

void	change_dir(char *path, t_data *prm)
{
	char		cwd[4097];
	char		oldpwd[4097];

	getcwd(oldpwd, 4096);
	if (chdir(path) == 0)
	{
		prm->argc = 4;
		free_matrix(prm->argv);
		prm->argv = (char **)ft_calloc(sizeof(char *), 4);
		prm->argv[0] = ft_strdup("export");
		prm->argv[1] = ft_strdup("OLDPWD=");
		prm->argv[2] = ft_strdup(oldpwd);
		prm->env = export_command(prm, 1);
		free_matrix(prm->argv);
		prm->argv = (char **)ft_calloc(sizeof(char *), 4);
		prm->argv[0] = ft_strdup("export");
		prm->argv[1] = ft_strdup("PWD=");
		prm->argv[2] = ft_strdup(getcwd(cwd, 4096));
		prm->env = export_command(prm, 1);
	}
	else
		ft_putstrs_fd("bash6: cd: ", prm->argv[1], ": ", 2);
}

void	cd_command(t_data *prm)
{
	char	*path;

	errno = 0;
	if (prm->argc <= 2)
	{
		if (!prm->argv[1] || !ft_strncmp(prm->argv[1], "--", 3) || \
			!ft_strncmp(prm->argv[1], "~", 2))
			path = get_env(prm->env, "HOME");
		else if (!ft_strncmp(prm->argv[1], "-", 2))
			path = get_env(prm->env, "OLDPWD");
		else
			path = prm->argv[1];
		change_dir(path, prm);
		if (errno > 0)
		{
			ft_putstrs_fd(strerror(errno), "\n", 0, 2);
			prm->ret = 1;
		}
	}
	else
	{
		ft_putstr_fd("bash7: cd: too many arguments\n", 2);
		prm->ret = 1;
	}
	errno = 0;
}
