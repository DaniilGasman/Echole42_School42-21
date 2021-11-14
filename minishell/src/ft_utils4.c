/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 19:14:44 by nfedayki          #+#    #+#             */
/*   Updated: 2021/07/19 22:55:48 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

char	**unset_command(t_data *prm, int j)
{
	int		i;
	int		len;
	char	*envm;
	char	**cpy;

	if (prm->argc < 2)
		return (prm->env);
	len = strlen(prm->argv[j]);
	envm = ft_strjoin(prm->argv[j], "=");
	i = 0;
	while (prm->env[i] && ft_memcmp(envm, prm->env[i], len + 1))
		i++;
	if (prm->env[i])
		cpy = erase_env(prm->env, i);
	else
		cpy = prm->env;
	free(envm);
	return (cpy);
}

int	chek_stat(int fd, char c)
{	
	int	ret;

	ret = read(fd, &c, 1);
	if (ret == -1)
		write(2, "Couldn't read file\n", 19);
	return (ret);
}

int	redirect(t_data *prm, int i, int fd)
{
	int		ret;
	char	c;

	while (prm->argv[i])
	{
		if (!ft_memcmp(prm->argv[i], ">", 2))
			fd = open(prm->argv[i + 1], O_RDWR | O_CREAT | O_TRUNC, 0666);
		else if (!ft_memcmp(prm->argv[i], ">>", 3))
		{
			fd = open(prm->argv[i + 1], O_RDWR | O_CREAT | O_APPEND, 0666);
			ret = 0;
			while (read(fd, &c, 1))
			{
				if (chek_stat(fd, c) == -1)
					break ;
			}
		}
		i++;
		if (prm->argv[i] && (!ft_memcmp(prm->argv[i], ">>", 3)
				|| !ft_memcmp(prm->argv[i], ">", 2)))
			close(fd);
	}
	return (fd);
}

int	set_fd(t_data *prm)
{
	int		i;
	int		fd;

	i = 0;
	fd = 1;
	while (prm->argv[i] && ft_memcmp(prm->argv[i], ">", 2)
		&& ft_memcmp(prm->argv[i], ">>", 3))
		i++;
	if (!prm->argv[i])
		return (1);
	return (redirect(prm, i, fd));
}

int	strinwhile(char *str, int *i)
{
	if (str[*i] == '\'' || str[*i] == '"')
	{
		i++;
		*i += ft_strlen_arg_token(str + *i, str[*i - 1]);
		if (!(str[*i]))
			return (0);
	}
	return (1);
}
