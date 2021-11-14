/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 23:50:07 by nfedayki          #+#    #+#             */
/*   Updated: 2021/07/19 22:54:52 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

int	ft_strlen_arg_token(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
	{
		if (str[i] == '\\' && is_token(str[i + 1]))
			i++;
		i++;
	}
	return (i);
}

int	ft_strlen_arg(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '<' || str[i] == '>' || str[i] == '=' || str[i] == '|')
	{
		if (str[i] == '>' && str[i + 1] == '>')
			i = 2;
		else
			i = 1;
	}
	else
	{
		while (str[i] && !ft_isspace(str[i]) && str[i] != '<' && \
		str[i] != '>' && str[i] != '=' && str[i] != '|')
		{
			if (0 == strinwhile(str, &i))
				return (i);
			i++;
		}
		if (str[i] == '=')
			i++;
	}
	return (i);
}

int	count_args(char *str)
{
	int	n;

	n = 0;
	skip_spaces(&str);
	while (*str)
	{
		skip_spaces(&str);
		n++;
		str += ft_strlen_arg(str);
		skip_spaces(&str);
	}
	return (n);
}

void	set_args(char **argv, char *str, int argc)
{
	int	i;
	int	len;

	i = 0;
	skip_spaces(&str);
	while (i < argc)
	{
		skip_spaces(&str);
		len = ft_strlen_arg(str);
		argv[i] = ft_strldup(str, len);
		rm_token(&(argv[i]));
		i++;
		str += len;
		skip_spaces(&str);
	}
}

void	copy_args1(t_data *prm)
{
	int		i;
	int		j;
	char	**args;

	prm->argc -= count_redir(prm) * 2;
	args = (char **)ft_calloc(sizeof(char *), prm->argc + 1);
	i = 0;
	j = 0;
	while (j < prm->argc)
	{
		if (!ft_memcmp(prm->argv[i], ">", 2) || \
			!ft_memcmp(prm->argv[i], ">>", 3))
			i += 2;
		else
			args[j++] = ft_strdup(prm->argv[i++]);
	}
	free_matrix(prm->argv);
	prm->argv = args;
}
