/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subsidiary.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 19:01:09 by nfedayki          #+#    #+#             */
/*   Updated: 2021/01/30 17:18:33 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_format.h"

size_t					ft_strlen(char *s)
{
	int					i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int						ft_ulen(unsigned long long nbr, unsigned long long base)
{
	int					count;
	unsigned long long	cpy_nbr;

	if (nbr == 0)
		return (1);
	count = 0;
	cpy_nbr = nbr;
	while (cpy_nbr > 0)
	{
		cpy_nbr /= base;
		count++;
	}
	return (count);
}

char					*ft_sub_itoa(int *len, unsigned long long n,
int base, int flag_p)
{
	char				*un_buf;

	*len = ft_ulen(n, base);
	if (flag_p == 1)
		*len = *len + 2;
	if (!(un_buf = (char *)malloc(sizeof(char) * (*len + 1))))
		return (NULL);
	un_buf[*len] = '\0';
	if (flag_p == 1)
	{
		un_buf[0] = '0';
		un_buf[1] = 'x';
	}
	*len = *len - 1;
	return (un_buf);
}

char					ft_hex_char(unsigned int digit, int big_flag)
{
	if (digit == 10 && !big_flag)
		return ('a');
	else if (digit == 11 && !big_flag)
		return ('b');
	else if (digit == 12 && !big_flag)
		return ('c');
	else if (digit == 13 && !big_flag)
		return ('d');
	else if (digit == 14 && !big_flag)
		return ('e');
	else if (digit == 15 && !big_flag)
		return ('f');
	if (digit == 10 && big_flag)
		return ('A');
	else if (digit == 11 && big_flag)
		return ('B');
	else if (digit == 12 && big_flag)
		return ('C');
	else if (digit == 13 && big_flag)
		return ('D');
	else if (digit == 14 && big_flag)
		return ('E');
	else if (digit == 15 && big_flag)
		return ('F');
	return (0);
}

char					*ft_itoa_for_printf(unsigned long long n,
unsigned long long base, int big_flag, int flag_p)
{
	unsigned int		dig;
	char				*un_buf;
	int					len;

	un_buf = ft_sub_itoa(&len, n, base, flag_p);
	while ((len >= 2 && flag_p == 1) || (len >= 0 && flag_p == 0))
	{
		dig = (n % base);
		if (dig >= 10)
			un_buf[len] = ft_hex_char(dig, big_flag);
		else
			un_buf[len] = dig + '0';
		n /= base;
		len--;
	}
	return (un_buf);
}
