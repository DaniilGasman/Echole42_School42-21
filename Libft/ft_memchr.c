/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:40:30 by nfedayki          #+#    #+#             */
/*   Updated: 2020/11/25 14:19:28 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char	*s;
	unsigned char	d;
	int				m;

	m = 0;
	d = (unsigned char)c;
	s = (unsigned char *)arr;
	while (n-- && m == 0)
	{
		if (*s == d)
			return (s);
		s++;
	}
	return (NULL);
}
