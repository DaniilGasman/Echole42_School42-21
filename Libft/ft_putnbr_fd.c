/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 19:15:59 by nfedayki          #+#    #+#             */
/*   Updated: 2020/11/28 21:02:08 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	m;
	int				z;

	z = 0;
	if (n < 0)
	{
		m = n * (-1);
		z = 1;
	}
	else
		m = n;
	if (z == 1)
		ft_putchar_fd('-', fd);
	if (m > 9)
		ft_putnbr_fd(m / 10, fd);
	ft_putchar_fd(m % 10 + 48, fd);
}
