/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 22:09:06 by nfedayki          #+#    #+#             */
/*   Updated: 2021/07/19 18:11:30 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		len;
	char	*str;

	if (s1 && s2)
	{
		len = ft_strlen(s1);
		str = (char *)malloc(1 * (len + ft_strlen(s2) + 1));
		if (!str)
			return (NULL);
		i = -1;
		while (s1[++i])
			str[i] = s1[i];
		i = -1;
		while (s2[++i])
		{
			str[len] = s2[i];
			len++;
		}
		str[len] = '\0';
		return (str);
	}
	else if (s1)
		return (ft_strdup(s1));
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len] != 0)
		len++;
	return (len);
}

void	ft_addchr(char **str, char c)
{
	char	*aux;

	aux = ft_calloc(sizeof(char), ft_strlen(*str) + 2);
	ft_memcpy(aux, *str, ft_strlen(*str));
	aux[ft_strlen(aux)] = c;
	if (*str)
		free(*str);
	*str = aux;
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)dest;
	str2 = (unsigned char *)src;
	if (!n || dest == src)
		return (dest);
	while (0 < n--)
		*(str1++) = *(str2++);
	return (dest);
}

char	*ft_strldup(const char *s, int len)
{
	char	*ptr;
	int		size;
	int		i;

	size = 0;
	while (s[size])
		size++;
	if (len < size)
		size = len;
	ptr = (char *)malloc(sizeof(char) * (size + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
