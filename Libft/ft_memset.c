/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 15:21:46 by nfedayki          #+#    #+#             */
/*   Updated: 2020/11/25 14:20:32 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*ptr;
	char	sym;

	ptr = (char *)b;
	sym = (char)c;
	while (len > 0)
	{
		*ptr = sym;
		ptr++;
		len--;
	}
	return (b);
}
