/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 18:11:47 by nfedayki          #+#    #+#             */
/*   Updated: 2021/07/19 23:25:47 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	put_env(char **aux, int fd)
{
	int	i;

	i = -1;
	while (aux[++i])
	{
		ft_putstr_fd("declare -x ", fd);
		ft_putstrlen_fd(aux[i], ft_strlen_char(aux[i], '=') + 1, fd);
		if (ft_strchr(aux[i], '='))
			ft_putstrs_fd("\"", ft_strchr(aux[i], '=') + 1, "\"", fd);
		write(fd, "\n", 1);
	}
	free_matrix(aux);
}

void	sort_env(char **env, int fd, char c)
{
	int		i;
	int		len;
	char	**aux;
	char	*tmp;

	aux = env_cpy(env, 0);
	i = 0;
	while (aux[i] && aux[i + 1])
	{
		len = ft_strlen_char(aux[i], c);
		if (len > ft_strlen_char(aux[i + 1], c))
			ft_strlen_char(aux[i], c);
		else
			ft_strlen_char(aux[i + 1], c);
		if (ft_memcmp(aux[i], aux[i + 1], len) > 0)
		{
			tmp = aux[i];
			aux[i] = aux[i + 1];
			aux[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
	put_env(aux, fd);
}

char	**erase_env(char **env, int i)
{
	int		j;
	int		len;
	char	**cpy;

	len = 0;
	while (env[len])
		len++;
	cpy = (char **)ft_calloc(sizeof(char *), len);
	if (!(cpy))
		return (NULL);
	j = -1;
	while (++j < i)
		cpy[j] = ft_strdup(env[j]);
	i++;
	while (env[i])
		cpy[j++] = ft_strdup(env[i++]);
	free_matrix(env);
	return (cpy);
}

void	change_env2(t_var	*var, char **str)
{
	var->aux = ft_strjoin(var->bef, var->env);
	free(var->bef);
	free(var->env);
	free(*str);
	*str = ft_strjoin(var->aux, var->aft);
	free(var->aux);
	free(var->aft);
}
