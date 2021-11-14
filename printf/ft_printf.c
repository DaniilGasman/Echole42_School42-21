/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 19:05:32 by nfedayki          #+#    #+#             */
/*   Updated: 2021/01/30 17:16:27 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_format.h"

int				ft_printf(char *str, ...)
{
	char		*b_percent;
	char		*format;
	t_format	sub_format;
	int			lenght;
	va_list		ap;

	va_start(ap, str);
	if (!*str)
		return (0);
	lenght = 0;
	while (*str != '\0')
	{
		b_percent = ft_read_b_percent(&str);
		lenght += ft_print_str_util(b_percent, -1);
		free(b_percent);
		format = ft_format_src(&str);
		sub_format = ft_parse(format);
		free(format);
		lenght += ft_print_args(ap, sub_format);
	}
	va_end(ap);
	return (lenght);
}
