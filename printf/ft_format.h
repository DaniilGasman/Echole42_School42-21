/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfedayki <nfedayki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 12:22:29 by nfedayki          #+#    #+#             */
/*   Updated: 2021/01/30 17:19:55 by nfedayki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FORMAT_H
# define FT_FORMAT_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct	s_dig_op
{
	int		znak;
	int		base;
	int		p_flag;
	int		big_flag;
}				t_dig_op;

typedef struct	s_format
{
	int		flag_null;
	int		flag_minus;
	int		flag_width;
	int		star_width;
	int		flag_precision;
	int		star_precision;
	char	flag_arg;
}				t_format;

t_format		init_format();
t_format		ft_parse(char *format);
t_dig_op		ft_init_dig_op(int base_, int sign_, int p_flag_,
int big_flag_);
char			*ft_format_src(char **a_percent);
char			*ft_itoa_for_printf(unsigned long long n,
unsigned long long base, int big_flag, int flag_p);
char			*ft_read_b_percent(char **str1);
char			*ft_trim_precision_str(char *str, int accuracy);
int				ft_ulen(unsigned long long nbr, unsigned long long base);
int				ft_print_str_util(char *str, int border);
int				ft_print_str(char *str, t_format sub_format);
int				ft_print_asc(va_list ap, t_format sub_format);
int				ft_print_arg_dig(va_list ap, t_format sub_format);
int				ft_print_arg_hex(va_list ap, t_format sub_format);
int				ft_print_args(va_list ap, t_format sub_format);
int				ft_print_char(char str, t_format sub_format);
int				ft_print_int(unsigned long long str, t_format sub_format,
t_dig_op dig_op);
size_t			ft_strlen(char *s);

#endif
