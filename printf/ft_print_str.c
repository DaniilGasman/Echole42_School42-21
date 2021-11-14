/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:45:02 by nfedayki          #+#    #+#             */
/*   Updated: 2021/01/30 17:15:50 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_format.h"

char		*ft_read_b_percent(char **str1)
{
	char	*b_percent;
	int		i;

	b_percent = (char *)malloc(sizeof(char) * (ft_strlen(*str1) + 1));
	if (!b_percent)
		return (NULL);
	i = 0;
	while (**str1 != '%' && **str1 != '\0')
	{
		b_percent[i] = **str1;
		(*str1)++;
		i++;
	}
	b_percent[i] = '\0';
	return (b_percent);
}

int			ft_print_str_util(char *str, int border)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && (border > 0 || border <= -1))
	{
		write(1, &str[i], 1);
		i++;
		border--;
	}
	return (i);
}

int			ft_print_char(char str, t_format sub_format)
{
	int		len;
	int		width;

	len = 1;
	width = 0;
	if (sub_format.flag_minus && (sub_format.flag_precision != 0))
		write(1, &str, 1);
	while ((sub_format.flag_width - len) > 0)
	{
		if (sub_format.flag_null && !sub_format.flag_minus)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		width++;
		len++;
	}
	if (!sub_format.flag_minus)
	{
		if (sub_format.flag_precision != 0)
			write(1, &str, 1);
	}
	return (1 + width);
}

int			ft_print_str(char *str, t_format sub_format)
{
	int		len;
	int		size;
	int		width;

	len = 0;
	size = 0;
	width = 0;
	while (str[len] != '\0')
		len++;
	if (sub_format.flag_width < 0)
	{
		sub_format.flag_width = sub_format.flag_width * (-1);
		sub_format.flag_minus = 1;
	}
	if (sub_format.flag_minus)
		size = ft_print_str_util(str, -1);
	while ((sub_format.flag_width - len++) > 0)
	{
		write(1, " ", 1);
		width++;
	}
	if (!sub_format.flag_minus)
		size = ft_print_str_util(str, -1);
	return (size + width);
}

char		*ft_trim_precision_str(char *str, int accuracy)
{
	char	*buf;
	int		len;
	int		i;
	int		buff_size;

	len = 0;
	i = -1;
	if (str == NULL)
		str = "(null)";
	while (str[len] != '\0')
		len++;
	if (len > accuracy && accuracy >= 0)
		buff_size = accuracy;
	else
		buff_size = len;
	if (!(buf = malloc(sizeof(char *) * (buff_size + 1))))
		return (NULL);
	while (++i < buff_size)
		buf[i] = str[i];
	buf[i] = '\0';
	return (buf);
}
