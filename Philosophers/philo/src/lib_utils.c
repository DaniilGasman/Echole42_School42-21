/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 18:12:54 by nfedayki          #+#    #+#             */
/*   Updated: 2021/07/30 17:59:09 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	nbr;
	int	znak;

	i = 0;
	nbr = 0;
	znak = 0;
	while (str[i] != '\0' && (str[i] == 32 || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] != '\0' && str[i] == '-')
	{
		znak = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]))
		nbr = (nbr * 10) + (str[i++] - '0');
	if (znak == 1)
		return (-nbr);
	return (nbr);
}

char	*ft_strdup(char *s1)
{
	char	*s2;
	size_t	size;

	size = ft_strlen(s1) + 1;
	s2 = (char *)malloc(size);
	if (s2 == 0)
		return (0);
	ft_strlcpy(s2, (char *)s1, size);
	return (s2);
}

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	int		n;
	size_t	size_copy;

	if (!(dst) || !(src))
		return (0);
	size_copy = size;
	n = 0;
	while (src[n] != '\0' && size-- > 1)
	{
		dst[n] = src[n];
		n++;
	}
	if (size_copy > 0)
		dst[n] = '\0';
	return ((size_t)ft_strlen(src));
}

int	ft_strlen(char *s)
{
	int	size;

	size = 0;
	if (s)
		while (s[size] != '\0')
			size++;
	return (size);
}
