/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 18:23:47 by nfedayki          #+#    #+#             */
/*   Updated: 2021/07/20 15:31:41 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	set_in(char **argv)
{
	int		fd;
	int		i;

	i = 0;
	while (argv[i] && ft_memcmp(argv[i], "<", 2))
		i++;
	if (argv[i])
	{
		fd = open(argv[i + 1], O_RDONLY, 0666);
		if (fd < 0)
		{
			ft_putstr_fd("Couldn't read from file.\n", 2);
			exit(0);
		}
		dup2(fd, 0);
		close(fd);
	}
}

void	exec_bin(int fd, char *path, t_data *prm)
{
	char	**args;

	args = copy_args(prm);
	signal(SIGINT, child_sig_handler);
	if (!fork())
	{
		set_in(prm->argv);
		if (fd > 1)
			dup2(fd, 1);
		if ((execve(path, args, prm->env)) && errno == EACCES)
		{
			prm->ret = 126;
			ft_putstrs_fd("bash4: ", prm->argv[0], ": ", 2);
			ft_putstrs_fd(strerror(errno), "\n", 0, 2);
		}
		exit(prm->ret);
	}
	wait(&prm->ret);
	prm->ret /= 256;
	free(path);
	free_matrix(args);
}

char	**split_path(t_data *prm, char *str)
{
	char	*path;
	char	**paths;

	path = get_env(prm->env, "PATH");
	if (path)
		paths = ft_split_case(path, ':');
	else
	{
		ft_putstrs_fd("bash5: ", str, ": No such file or directory\n", 2);
		prm->ret = 127;
		return (NULL);
	}
	return (paths);
}

char	*search_bin(char *str, DIR **dir, struct dirent **d, t_data *prm)
{
	char		**paths;
	int			i;

	paths = split_path(prm, str);
	i = -1;
	while (paths[++i])
	{
		*dir = opendir(paths[i]);
		if (*dir)
		{
			while ((*dir) && errno != EACCES && reread(&*dir, &*d))
			{
				if (!paths[i])
					return (NULL);
				else if (!ft_memcmp(str, (*d)->d_name, ft_strlen(str) + 1))
					return (your_mom(&*paths, i));
			}
			closedir(*dir);
		}
		if (!paths[i])
			return (NULL);
	}
	free_matrix(paths);
	return (NULL);
}

int	check_bin(int fd, t_data *prm)
{
	DIR				*dir;
	struct dirent	*d;
	char			*pre_path;
	char			*path;

	prm->ret = 127;
	pre_path = search_bin(prm->argv[0], &dir, &d, prm);
	if (pre_path)
	{
		path = ft_strjoin(pre_path, d->d_name);
		exec_bin(fd, path, prm);
		closedir(dir);
	}
	free(pre_path);
	return (prm->ret);
}
