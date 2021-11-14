/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 20:03:34 by nfedayki          #+#    #+#             */
/*   Updated: 2021/01/30 17:13:30 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_format.h"

char		*ft_print_int_0(unsigned long long str, t_format *sub_format,
int *width, t_dig_op dig_op)
{
	int		count_dig_str;
	char	*buf;

	*width = 0;
	count_dig_str = ft_ulen(str, dig_op.base);
	if (str == 0 && sub_format->flag_precision >= 0)
		count_dig_str--;
	buf = ft_itoa_for_printf(str, dig_op.base, dig_op.big_flag,
	dig_op.p_flag);
	if (sub_format->flag_width > sub_format->flag_precision ||
		sub_format->flag_width > count_dig_str)
	{
		if (sub_format->flag_precision > count_dig_str)
			*width = sub_format->flag_width - sub_format->flag_precision;
		else
			*width = sub_format->flag_width - count_dig_str;
		if (dig_op.znak == -1)
			*width = *width - 1;
		if (dig_op.p_flag == 1)
			*width = *width - 2;
	}
	return (buf);
}

int			ft_print_int_1(t_format sub_format, int count_dig_str,
int width)
{
	int		count_width;

	count_width = 0;
	if (sub_format.flag_width > sub_format.flag_precision &&
	sub_format.flag_precision > count_dig_str &&
	!sub_format.flag_minus)
	{
		while (width-- > 0)
		{
			write(1, " ", 1);
			count_width++;
		}
	}
	if (!((sub_format.flag_null == 1) &&
	(sub_format.flag_precision == -1)) && !sub_format.flag_minus)
	{
		while (width-- > 0)
		{
			write(1, " ", 1);
			count_width++;
		}
	}
	return (count_width);
}

int			ft_print_int_2(t_format sub_format, int accuracy,
int width, int sign)
{
	int		count_width;

	count_width = 0;
	if (sign == -1)
	{
		write(1, "-", 1);
		count_width++;
	}
	if ((sub_format.flag_null == 1) &&
		(sub_format.flag_precision == -1) &&
		!sub_format.flag_minus)
	{
		while (width-- > 0)
		{
			write(1, "0", 1);
			count_width++;
		}
	}
	while (accuracy-- > 0)
	{
		write(1, "0", 1);
		count_width++;
	}
	return (count_width);
}

int			ft_print_int_3(unsigned long long str, t_format sub_format,
char *buf, t_dig_op dig_op)
{
	int		count_width;

	count_width = 0;
	if (!(str == 0 && sub_format.flag_precision == 0))
		count_width += ft_print_str_util(buf, -1);
	if (str == 0 && sub_format.flag_precision == 0 && dig_op.p_flag)
		count_width += ft_print_str_util(buf, 2);
	return (count_width);
}

int			ft_print_int(unsigned long long str, t_format sub_format,
t_dig_op dig_op)
{
	char	*buf;
	int		width;
	int		count_width;
	int		accuracy;
	int		count_dig_str;

	count_width = 0;
	accuracy = 0;
	count_dig_str = ft_ulen(str, dig_op.base);
	buf = ft_print_int_0(str, &sub_format, &width, dig_op);
	if (sub_format.flag_precision > count_dig_str)
		accuracy = sub_format.flag_precision - count_dig_str;
	count_width += ft_print_int_1(sub_format, count_dig_str, width);
	count_width += ft_print_int_2(sub_format, accuracy, width,
	dig_op.znak);
	count_width += ft_print_int_3(str, sub_format, buf, dig_op);
	while (width-- > 0 && sub_format.flag_minus)
	{
		write(1, " ", 1);
		count_width++;
	}
	free(buf);
	return (count_width);
}
