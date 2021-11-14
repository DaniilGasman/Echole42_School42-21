/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 18:49:03 by nfedayki          #+#    #+#             */
/*   Updated: 2021/07/19 22:59:50 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	rm_backslash(char **arg, int *i)
{
	while ((*arg)[*i])
	{
		if ((*arg)[*i] == '\\' && is_token((*arg)[*i + 1]))
			rm_char(arg, *i);
		else if ((*arg)[*i] == '"')
			break ;
		(*i)++;
	}
}

void	rm_token(char **arg)
{
	int		i;

	i = 0;
	while ((*arg)[i])
	{
		if ((*arg)[i] == '\'')
		{
			rm_char(arg, i);
			i += ft_strlen_char(*arg + i, '\'');
			rm_char(arg, i);
		}
		else if ((*arg)[i] == '"')
		{
			rm_char(arg, i);
			rm_backslash(arg, &i);
			rm_char(arg, i);
		}
		else if (((*arg)[i] == '\\')
			&& (is_token((*arg)[i + 1]) || (*arg)[i + 1] == '\''))
			rm_char(arg, i++);
		else
			i++;
	}
}

int	check_export_error(char **argv, int *i)
{
	int	j;

	j = 0;
	while (ft_isalnum(argv[*i][j]) || argv[*i][j] == '_' ||
			argv[*i][j] == '#' || argv[*i][j] == '=' || argv[*i][j] == '$')
		j++;
	if (ft_isdigit(argv[*i][0]) || argv[*i][j])
	{
		if (ft_strchr(argv[*i], '='))
		{
			ft_putstrs_fd("bash10: ", argv[0], ": `", 2);
			ft_putstrs_fd(argv[*i], argv[(*i) + 1],
				"': not a valid identifier\n", 2);
			(*i)++;
		}
		else
		{
			ft_putstrs_fd("bash11: ", argv[0], ": `", 2);
			ft_putstrs_fd(argv[*i], "': not a valid identifier\n", 0, 2);
		}
		(*i)++;
		return (1);
	}
	return (0);
}

void	helper(t_data *prm, int *i)
{
	prm->env = export_command(prm, *i);
	if (prm->argv[*i + 1])
		*i += 2;
	else
		*i += 1;
}

void	export_value(t_data *prm, int *i)
{
	char	**aux;
	int		j;

	if (!ft_strchr(prm->argv[*i], '='))
	{
		j = 0;
		while (prm->export[j] && ft_memcmp(prm->export[j],
				prm->argv[*i], ft_strlen(prm->argv[*i])))
			j++;
		if (!prm->export[j])
		{
			aux = env_cpy(prm->export, 1);
			aux[j] = ft_strdup(prm->argv[*i]);
			aux[j + 1] = 0;
			free_matrix(prm->export);
			prm->export = aux;
		}
		(*i)++;
	}
	else
		helper(prm, i);
}
