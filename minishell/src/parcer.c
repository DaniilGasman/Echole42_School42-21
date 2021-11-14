/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 22:20:05 by nfedayki          #+#    #+#             */
/*   Updated: 2021/07/20 16:23:24 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

int	change_env(int i, int braces, char **str, t_data *prm)
{
	int		len;
	t_var	var;

	var.env = 0;
	if ((*str)[i + 1] == '{')
		braces = 1;
	else
		braces = 0;
	if (ft_strlen_char(*str + i + 1, ':') < ft_strlen_env(*str + i + 1))
		len = ft_strlen_char(*str + i + 1, ':') + 1;
	else
		len = ft_strlen_env(*str + i + 1) + 1 + braces;
	var.bef = ft_strldup(*str, i);
	var.aux = ft_strldup(*str + i + 1 + braces, len - 1 - braces * 2);
	if (!ft_memcmp(var.aux, "?", 2))
		var.env = ft_itoa(prm->ret, -1);
	var.aft = ft_strdup(*str + i + len);
	if (!var.env)
		var.env = ft_strdup(get_env(prm->env, var.aux));
	free(var.aux);
	len = ft_strlen(var.env);
	change_env2(&var, &*str);
	return (len);
}

int	check_quotes(char **str, int *i)
{
	(*i)++;
	while ((*str)[*i] && ((*str)[*i] != '\''))
		(*i)++;
	if (!(*str)[*i])
	{
		ft_putstr_fd("Non finished quotes\n", 2);
		return (1);
	}
	return (0);
}

int	check_env(char **str, t_data *prm)
{
	int	i;
	int	braces;

	i = 0;
	braces = 0;
	while ((*str) && (*str)[i])
	{
		if ((*str)[i] == '\'' && check_quotes(str, &i))
			return (1);
		if ((*str)[i] && (*str)[i] == '\\')
		{
			if ((*str)[i + 1] == '$')
				rm_char(str, i);
			if ((*str)[i + 1])
				i++;
		}
		else if ((*str)[i] == '$' && !(!(*str)[i + 1] ||
		ft_isspace((*str)[i + 1]) || (*str)[i + 1] == '\'' ||
		(*str)[i + 1] == '"' || (*str)[i + 1] == '/'))
			i += change_env(i, braces, str, prm) - 1;
		i++;
	}
	return (0);
}

int	check_semicolon(t_data *prm)
{
	int	i;

	i = exceptions(prm, ";");
	i = exceptions(prm, ";;");
	i = exceptions(prm, "&");
	i = exceptions(prm, "&&");
	i = exceptions(prm, "|");
	i = exceptions(prm, "||");
	return (i);
}

void	parser(t_data *prm)
{
	int	i;

	if (check_semicolon(prm))
		return ;
	prm->cmds = ft_split_case(prm->str, ';');
	i = 0;
	while (prm->cmds[i])
	{
		check_env(&(prm->cmds[i]), prm);
		prm->argc = count_args(prm->cmds[i]);
		prm->argv = (char **)ft_calloc(sizeof(char *), (prm->argc + 1));
		set_args(prm->argv, prm->cmds[i], prm->argc);
		command_or_pipe(prm, i);
		i++;
		free_matrix(prm->argv);
	}
	free(prm->str);
	prm->str = 0;
	free_matrix(prm->cmds);
}
