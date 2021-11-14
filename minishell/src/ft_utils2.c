/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 17:01:29 by nfedayki          #+#    #+#             */
/*   Updated: 2021/07/19 23:46:03 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

int	count_redir(t_data *prm)
{
	int	count;
	int	i;

	i = -1;
	count = 0;
	while (++i < prm->argc)
	{
		if (!ft_memcmp(prm->argv[i], ">", 2) || \
			!ft_memcmp(prm->argv[i], ">>", 3))
		{
			count++;
			i++;
		}
	}
	return (count);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return ;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}

int	check_builts(int fd, t_data *prm)
{
	char	*path;
	char	cwd[4097];

	path = 0;
	if (!ft_memcmp(prm->argv[0], "echo", 5))
		echo_command(prm, fd);
	else if (!ft_memcmp(prm->argv[0], "pwd", 4))
		ft_putstrs_fd(getcwd(cwd, 4096), "\n", 0, fd);
	else if (!ft_memcmp(prm->argv[0], "cd", 3))
	{
		path = ft_strdup(prm->argv[1]);
		cd_command(prm);
		if (path && !ft_strncmp(path, "-", 2))
			ft_putstrs_fd(getcwd(cwd, 4096), "\n", 0, fd);
		free(path);
	}
	else
		return (1);
	return (0);
}

int	check_builtins(int fd, t_data *prm)
{
	prm->ret = 0;
	if (!check_builts(fd, prm))
		return (prm->ret);
	else if (!ft_memcmp(prm->argv[0], "env", 4))
		env_command(prm, fd);
	else if (!ft_memcmp(prm->argv[0], "./", 2) || \
			!ft_memcmp(prm->argv[0], "../", 3) || \
			!ft_memcmp(prm->argv[0], "/", 1))
		bash_command(prm);
	else if (!ft_memcmp(prm->argv[0], "export", 7) || \
			!ft_memcmp(prm->argv[0], "unset", 6))
		prm->env = multiple_env(prm, fd, 1);
	else if (!ft_memcmp(prm->argv[0], "exit", 5) || \
			!ft_memcmp(prm->argv[0], "q", 2))
		exit_command(prm);
	else
		return (127);
	return (prm->ret);
}

void	echo_command(t_data *prm, int fd)
{
	int	i;

	if (prm->argc > 1 && !ft_memcmp(prm->argv[1], "-n", 3))
		i = 1;
	else
		i = 0;
	while (++i < prm->argc)
	{
		ft_putstr_fd(prm->argv[i], fd);
		if (i < prm->argc - 1 && ft_strlen(prm->argv[i + 1]))
			write(fd, " ", 1);
	}
	if (!(prm->argc > 1 && !ft_memcmp(prm->argv[1], "-n", 3)))
		write(fd, "\n", 1);
}
