/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 16:51:43 by nfedayki          #+#    #+#             */
/*   Updated: 2021/07/19 21:22:37 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	switch_pipes(int *fds)
{
	close(fds[0]);
	close(fds[1]);
	fds[0] = fds[2];
	fds[1] = fds[3];
	pipe(fds + 2);
}

void	set_pipe_args(t_data *prm, int i)
{
	char	**aux;
	int		j;
	int		k;

	j = 0;
	while (prm->argv[i + j] && ft_memcmp(prm->argv[i + j], "|", 2))
		j++;
	aux = (char **)ft_calloc(sizeof(char *), j + 1);
	k = -1;
	while (++k < j)
		aux[k] = ft_strdup(prm->argv[i + k]);
	prm->argv = aux;
	prm->argc = j;
}

void	pipe_son(int *flag, int *fds, t_data *prm, int pos)
{
	int		i;
	int		argc;
	char	**argv;

	signal(SIGINT, child_sig_handler);
	if (!fork())
	{
		if (!flag[0])
			dup2(fds[0], 0);
		if (!flag[1])
			dup2(fds[3], 1);
		i = 0;
		while (i < 4)
			close(fds[i++]);
		argc = prm->argc;
		argv = prm->argv;
		set_pipe_args(prm, pos);
		check_command(prm->str, prm);
		free_matrix(prm->argv);
		prm->argc = argc;
		prm->argv = argv;
		exit(prm->ret);
	}
}

int	check_pipe(int *fds, t_data *prm, int j, int sons)
{
	int		flag[2];
	int		i;

	flag[0] = 1;
	flag[1] = 0;
	while (prm->argv[j])
	{
		i = 0;
		while (prm->argv[j + i]
			&& ft_memcmp(prm->argv[j + i], "|", 2))
			i++;
		if (!prm->argv[i + j])
			flag[1] = 1;
		else
			flag[1] = 0;
		pipe_son(flag, fds, prm, j);
		sons++;
		flag[0] = 0;
		switch_pipes(fds);
		if (!prm->argv[j + i])
			j += i;
		else
			j += i + 1;
	}
	return (sons);
}

void	command_or_pipe(t_data *prm, int j)
{
	int	fds[4];
	int	std_out;
	int	sons;
	int	i;

	std_out = dup(0);
	i = 0;
	while (prm->argv[i] && ft_memcmp(prm->argv[i], "|", 2))
		i++;
	if (!prm->argv[i])
		prm->env = check_command(prm->cmds[j], prm);
	else if (prm->cmds[j])
	{
		pipe(fds);
		pipe(fds + 2);
		sons = check_pipe(fds, prm, 0, 0);
		while (sons-- > 0)
			wait(&prm->ret);
		prm->ret /= 256;
		i = -1;
		while (++i < 4)
			close(fds[i]);
	}
	dup2(std_out, 0);
}
