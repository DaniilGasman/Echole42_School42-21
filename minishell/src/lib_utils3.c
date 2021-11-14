/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 23:35:44 by nfedayki          #+#    #+#             */
/*   Updated: 2021/07/19 22:36:50 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

int	ft_isspace(int c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_isalnum(int c)
{
	if ((('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
		|| ('0' <= c && c <= '9'))
		return (8);
	else
		return (0);
}

void	itoa_isnegative(long long int *n, int *negative)
{
	if (*n < 0)
	{
		*n *= -1;
		*negative = 1;
	}
}

char	*ft_itoa(int n, int sign)
{
	char	*dest;
	int		digits;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0\0"));
	if (n > 0)
		sign = 1;
	if (sign < 0)
		n = n * -1;
	digits = ft_num_size(n, sign);
	dest = (char *)malloc(digits + 1);
	if (!dest)
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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	while (0 < n--)
	{
		if (*(c1++) != *(c2++))
			return (*(--c1) - *(--c2));
		else if (!(*c1) || !(*c2))
			return (*(c1) - *(c2));
	}
	return (0);
}
