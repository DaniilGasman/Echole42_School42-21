/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 11:44:29 by nfedayki          #+#    #+#             */
/*   Updated: 2021/01/30 16:58:45 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_format.h"

t_format		ft_parse_0(t_format format_s, char format,
int *stage)
{
	if (*stage == 0)
	{
		if ((format >= 48 && format <= 57) || (format == '*'))
		{
			if (format == '*')
				format_s.star_width = 1;
			else
				format_s.flag_width = format_s.flag_width * 10 +
				(format - '0');
		}
	}
	if (format == '.')
		*stage = 1;
	return (format_s);
}

t_format		ft_parse_1(t_format format_s, char format,
char format1, int stage)
{
	if (stage == 1)
	{
		if (format1 == '*')
			format_s.star_precision = 1;
		if (format1 >= 48 && format1 <= 57)
			format_s.flag_precision = format_s.flag_precision *
			10 + (format1 - '0');
	}
	if (format == 's' || format == 'd' || format == 'u' ||
		format == 'i' || format == 'c' || format == 'p' ||
		format == 'x' || format == 'X' || format == '%')
		format_s.flag_arg = format;
	return (format_s);
}

t_format		ft_parse(char *format)
{
	t_format	format_s;
	int			i;
	int			stage;

	i = 0;
	stage = 0;
	format_s = init_format();
	if (format == NULL)
		return (format_s);
	if ((format[0] == '0') && (format[1] != '-'))
		format_s.flag_null = 1;
	if ((format[0] == '-') || (format[1] == '-'))
		format_s.flag_minus = 1;
	while (format[i] != '\0')
	{
		format_s = ft_parse_0(format_s, format[i], &stage);
		format_s = ft_parse_1(format_s, format[i], format[i + 1], stage);
		i++;
	}
	if (stage < 1)
		format_s.flag_precision = -1;
	return (format_s);
}

char			*ft_format_src(char **a_percent)
{
	char		*format;
	int			i;
	int			j;

	i = 1;
	j = -1;
	if ((*a_percent)[0] != '%')
		return (NULL);
	while ((*a_percent)[i] != 'd' && (*a_percent)[i] != 'i' &&
	(*a_percent)[i] != 'u' && (*a_percent)[i] != 'x' &&
	(*a_percent)[i] != 's' && (*a_percent)[i] != 'p' &&
	(*a_percent)[i] != 'c' && (*a_percent)[i] != 'X' &&
	(*a_percent)[i] != '%')
		i++;
	format = (char *)malloc(sizeof(char) * (i + 1));
	if (!format)
		return (NULL);
	(*a_percent)++;
	while (++j < i)
		format[j] = *((*a_percent)++);
	format[j] = '\0';
	return (format);
}

t_format		init_format(void)
{
	t_format	format_s;

	format_s.flag_null = 0;
	format_s.flag_minus = 0;
	format_s.flag_width = 0;
	format_s.star_width = 0;
	format_s.star_precision = 0;
	format_s.flag_precision = 0;
	format_s.flag_arg = '0';
	return (format_s);
}
