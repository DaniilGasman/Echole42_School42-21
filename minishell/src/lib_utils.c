/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 22:01:30 by nfedayki          #+#    #+#             */
/*   Updated: 2021/07/19 18:12:06 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, nmemb * size);
	return ((void *)ptr);
}

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)str;
	while (0 < n--)
		*(ptr++) = (unsigned char)c;
	return (str);
}

char	*ft_strdup(char *s)
{
	char	*ptr;
	int		size;
	int		i;

	if (!s)
		return (NULL);
	size = 0;
	while (s[size])
		size++;
	ptr = (char *)malloc(sizeof(char) * (size + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

int	ft_putstrs_fd(char *before, char *str, char *after, int fd)
{	
	if (before)
		write(fd, before, ft_strlen(before));
	if (str)
		write(fd, str, ft_strlen(str));
	if (after)
		write(fd, after, ft_strlen(after));
	return (1);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*v1;
	unsigned char	*v2;

	v1 = (unsigned char *)s1;
	v2 = (unsigned char *)s2;
	while (0 < n--)
		if (*(v1++) != *(v2++))
			return (*(--v1) - *(--v2));
	return (0);
}
