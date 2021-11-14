/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 19:33:28 by nfedayki          #+#    #+#             */
/*   Updated: 2020/11/25 19:33:31 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		num_size(int n, int sign)
{
	int digits;

	digits = 1;
	while (n > 9)
	{
		n = n / 10;
		digits++;
	}
	return (sign > 0 ? digits : digits + 1);
}

char			*ft_itoa(int n)
{
	char	*dest;
	int		digits;
	int		sign;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0\0"));
	sign = (n > 0 ? 1 : -1);
	if (sign < 0)
		n = n * -1;
	digits = num_size(n, sign);
	if (!(dest = (char*)malloc(digits + 1)))
		return (NULL);
	if (sign < 0)
		ft_memset(dest, '-', 1);
	dest[digits] = '\0';
	while (n != 0)
	{
		dest[digits - 1] = (n % 10) + '0';
		n = n / 10;
		digits--;
	}
	return (dest);
}
