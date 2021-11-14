/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 20:42:27 by nfedayki          #+#    #+#             */
/*   Updated: 2021/05/16 20:49:20 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_utils.h"
#include "macroses.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*cpy;

	i = 0;
	while (s1[i])
		i++;
	cpy = malloc((i + 1) * sizeof(char));
	if (cpy == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

static int	ft_isbase(char c, char *base)
{
	int		i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int		i;
	int		nbr;
	int		tmp;
	int		base_size;

	i = 0;
	nbr = 0;
	base_size = ft_strlen(base);
	tmp = ft_isbase(str[i], base);
	while (str[i] && (tmp >= 0))
	{
		nbr *= base_size;
		nbr += tmp;
		i++;
	}
	return (nbr);
}

int	ft_ext_check(char *file_name, char *ext)
{
	int		i;
	int		j;

	j = 3;
	i = ft_strlen(file_name) - 1;
	while (i > -1 && j > -1)
	{
		if (file_name[i] != ext[j])
			return (0);
		i--;
		j--;
	}
	return (1);
}

int	ft_contains_notset(char *str, char *set)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!(ft_isset(str[i], set)))
			return (1);
		i++;
	}
	return (0);
}
