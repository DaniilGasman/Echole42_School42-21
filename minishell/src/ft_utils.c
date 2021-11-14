/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dminerva <dminerva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 19:55:08 by nfedayki          #+#    #+#             */
/*   Updated: 2021/07/19 18:40:18 by dminerva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	rm_char(char **str, int j)
{
	char	*bef;
	char	*aux;

	bef = ft_strldup(*str, j);
	aux = ft_strdup(*str + j + 1);
	free(*str);
	*str = ft_strjoin(bef, aux);
	free(aux);
	free(bef);
}

int	ft_strlen_char(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

void	skip_spaces(char **str)
{
	while (**str == ' ' || (9 <= **str && **str <= 13))
		(*str)++;
}

int	is_token(char c)
{
	if (c == '"' || c == '\\')
		return (1);
	return (0);
}

char	**check_command(char *str, t_data *prm)
{
	int		fd;

	if (prm->argv[0] && *(prm->argv[0]))
	{
		fd = set_fd(prm);
		copy_args1(prm);
		prm->ret = check_builtins(fd, prm);
		if (prm->ret == 127)
		{
			prm->ret = check_bin(fd, prm);
			if (prm->ret == 127)
			{
				ft_putstrs_fd(0, str, ": command not found.\n", 0);
				prm->ret = 127;
			}
		}
		if (fd != 1)
			close(fd);
	}
	return (prm->env);
}
