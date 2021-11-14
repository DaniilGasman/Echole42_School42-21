/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 13:58:43 by nfedayki          #+#    #+#             */
/*   Updated: 2020/11/25 14:23:13 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dsts)
{
	size_t	i;
	size_t	dsize;

	dsize = 0;
	while (dst[dsize] != '\0' && dsize < dsts)
		dsize++;
	i = dsize;
	while (src[dsize - i] && dsize + 1 < dsts)
	{
		dst[dsize] = src[dsize - i];
		dsize++;
	}
	if (i < dsts)
		dst[dsize] = '\0';
	return (i + ft_strlen(src));
}
