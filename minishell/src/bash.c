/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 17:54:25 by nfedayki          #+#    #+#             */
/*   Updated: 2021/07/19 23:47:52 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

int	check_errno(t_data *prm, char *str)
{
	if (errno == ENOENT || errno == EACCES)
	{
		ft_putstrs_fd("bash2: ", str, ": ", 2);
		ft_putstrs_fd(strerror(errno), "\n", 0, 2);
		if (errno == ENOENT)
			prm->ret = 126;
		else
			prm->ret = 126;
		return (1);
	}
	return (0);
}

void	check_type(t_data *prm, char *str, char *path, int fd)
{
	DIR			*dir;
	char		**cmds;

	prm->err = 0;
	if (check_errno(prm, str))
		return ;
	dir = opendir(path);
	if (!dir)
	{
		fd = open(path, O_RDONLY, 0666);
		free(prm->str);
		while (get_next_line(fd, &(prm->str)))
		{
			cmds = prm->cmds;
			parser(prm);
			prm->cmds = cmds;
		}
		close(fd);
	}
	else
	{
		ft_putstrs_fd("-bash3: ", str, ": Is a directory\n", 2);
		prm->ret = 126;
		closedir(dir);
	}
}

void	set_filename(int len, char **new, char *str)
{
	int		i;
	char	*filename;
	char	*aux;

	i = 0;
	while (!ft_memcmp(str + i, "../", 3))
		i += 3;
	filename = ft_strdup(str + i);
	i /= 3;
	while (i-- > 0)
	{
		while ((*new)[len] != '/')
			len--;
		len--;
	}
	aux = ft_strldup(*new, len);
	free(*new);
	*new = ft_strjoin(aux, "/");
	free(aux);
	aux = ft_strjoin(*new, filename);
	free(*new);
	*new = aux;
	free(filename);
}

void	set_path(char *str, char **path)
{
	int		len;
	char	*new;

	new = ft_strdup(*path);
	len = ft_strlen(*path);
	if (!ft_memcmp(str, "/", 1))
		*path = ft_strdup(str);
	else
	{
		set_filename(len, &new, str);
		*path = new;
		return ;
	}
	free(new);
}

void	bash_command(t_data *prm)
{
	char	buff[4097];
	char	*path;
	char	*start;

	start = prm->argv[0];
	if (ft_memcmp(prm->argv[0], "/", 1))
	{
		if (!ft_memcmp(prm->argv[0], "./", 2))
			prm->argv[0] += 2;
		else
			prm->argv[0] += 0;
	}
	path = getcwd(buff, 4096);
	set_path(prm->argv[0], &path);
	if (!fork())
	{
		signal(SIGINT, child_sig_handler_bash);
		if (execve(path, prm->argv, prm->env))
			check_type(prm, start, path, 0);
		exit(prm->ret);
	}
	wait(&prm->ret);
	prm->ret /= 256;
	free(path);
	prm->argv[0] = start;
}
