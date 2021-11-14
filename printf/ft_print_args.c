/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 16:30:04 by nfedayki          #+#    #+#             */
/*   Updated: 2021/01/30 17:21:21 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_format.h"

int						ft_print_arg_hex(va_list ap, t_format sub_format)
{
	unsigned long long	a;
	t_dig_op			dig_op;

	if (sub_format.flag_arg == 'x')
	{
		a = va_arg(ap, unsigned int);
		dig_op = ft_init_dig_op(16, 1, 0, 0);
		return (ft_print_int(a, sub_format, dig_op));
	}
	if (sub_format.flag_arg == 'X')
	{
		a = va_arg(ap, unsigned int);
		dig_op = ft_init_dig_op(16, 1, 0, 1);
		return (ft_print_int(a, sub_format, dig_op));
	}
	if (sub_format.flag_arg == 'p')
	{
		a = (unsigned long)va_arg(ap, void *);
		dig_op = ft_init_dig_op(16, 1, 1, 0);
		return (ft_print_int(a, sub_format, dig_op));
	}
	return (0);
}

int						ft_print_arg_dig(va_list ap, t_format sub_format)
{
	int					a;
	unsigned int		b;
	t_dig_op			dig_op;

	if (sub_format.flag_arg == 'd' || sub_format.flag_arg == 'i')
	{
		a = va_arg(ap, int);
		dig_op = ft_init_dig_op(10, a >= 0 ? 1 : -1, 0, 0);
		return (ft_print_int(a >= 0 ? (unsigned)a : (unsigned)(-a), sub_format,
		dig_op));
	}
	if (sub_format.flag_arg == 'u')
	{
		b = va_arg(ap, unsigned int);
		dig_op = ft_init_dig_op(10, 1, 0, 0);
		return (ft_print_int(b, sub_format, dig_op));
	}
	return (0);
}

int						ft_print_asc(va_list ap, t_format sub_format)
{
	char				*a;
	char				b;
	int					len;

	if (sub_format.flag_arg == 's')
	{
		a = ft_trim_precision_str(va_arg(ap, char*),
		sub_format.flag_precision);
		len = ft_print_str(a, sub_format);
		free(a);
		return (len);
	}
	if (sub_format.flag_arg == 'c')
	{
		b = va_arg(ap, int);
		return (ft_print_char(b, sub_format));
	}
	if (sub_format.flag_arg == '%')
		return (ft_print_char('%', sub_format));
	return (0);
}

int						ft_print_args(va_list ap, t_format sub_format)
{
	int					len;

	len = 0;
	if (sub_format.star_width == 1)
		sub_format.flag_width = va_arg(ap, int);
	if (sub_format.flag_width < 0)
	{
		sub_format.flag_width = sub_format.flag_width * (-1);
		sub_format.flag_minus = 1;
	}
	if (sub_format.star_precision == 1)
	{
		sub_format.flag_precision = va_arg(ap, int);
		sub_format.flag_precision = sub_format.flag_precision >= 0 ?
									sub_format.flag_precision : -1;
	}
	len += ft_print_asc(ap, sub_format);
	len += ft_print_arg_dig(ap, sub_format);
	len += ft_print_arg_hex(ap, sub_format);
	return (len);
}

t_dig_op				ft_init_dig_op(int base_, int sign_, int p_flag_,
int big_flag_)
{
	t_dig_op			dig_op;

	dig_op.base = base_;
	dig_op.znak = sign_;
	dig_op.p_flag = p_flag_;
	dig_op.big_flag = big_flag_;
	return (dig_op);
}
