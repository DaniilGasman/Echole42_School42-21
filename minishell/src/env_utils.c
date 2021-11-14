/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 23:46:28 by nfedayki          #+#    #+#             */
/*   Updated: 2021/07/19 23:30:39 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

int	ft_strlen_env(char *str)
{
	int		len;

	len = 0;
	while (*str && \
	(ft_isalnum(*str) || *str == '{' || *str == '?' || *str == '_'))
	{
		len++;
		str++;
	}
	if (*str == '=')
		len++;
	return (len);
}

char	*get_env(char **envp, char *env)
{
	int		i;
	int		len;
	char	*tmp;

	env = ft_strjoin(env, "=");
	len = ft_strlen(env);
	i = 0;
	while (envp[i] && ft_memcmp(env, envp[i], len))
		i++;
	if (envp[i])
		tmp = envp[i] + len;
	else
		tmp = 0;
	free(env);
	return (tmp);
}

char	**env_cpy(char **env, int add)
{
	int		len;
	int		i;
	char	**cpy;

	len = 0;
	while (env[len])
		len++;
	cpy = (char **)ft_calloc(sizeof(char *), (len + add + 1));
	if (!cpy)
		return (0);
	i = -1;
	while (++i < len)
		cpy[i] = ft_strdup(env[i]);
	return (cpy);
}

void	env_command(t_data *prm, int fd)
{
	int	i;

	i = 0;
	if (prm->argc != 1)
	{
		ft_putstrs_fd("env: ‘", prm->argv[1], "’: Permission denied\n", 2);
		prm->ret = 126;
		return ;
	}
	while (prm->env[i])
		ft_putstrs_fd(prm->env[i++], "\n", 0, fd);
}

char	**multiple_env(t_data *prm, int fd, int i)
{
	prm->ret = 0;
	if (!ft_memcmp(prm->argv[0], "export", 7) && prm->argc == 1 && \
		!ft_strlen(prm->argv[1]))
	{
		sort_env(prm->env, fd, '=');
		sort_env(prm->export, fd, 0);
	}
	while (prm->argv[i])
	{
		if (check_export_error(prm->argv, &i))
			(prm->ret)++;
		else
		{
			if (!ft_memcmp(prm->argv[0], "export", 7))
				export_value(prm, &i);
			else if (!ft_memcmp(prm->argv[0], "unset", 6))
				prm->env = unset_command(prm, i++);
		}
	}
	if (prm->ret)
		prm->ret = 1;
	else
		prm->ret = 0;
	return (prm->env);
}
