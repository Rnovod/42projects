/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 17:26:39 by rnovodra          #+#    #+#             */
/*   Updated: 2018/04/28 17:26:40 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define FT_PRINTF_BUFF_SIZE 4096
# include <stdarg.h>
# include <stdint.h>
# include <wchar.h>
# include <limits.h>
# include <unistd.h>
# include <locale.h>
# include <stdlib.h>
# include <math.h>
# include <stdint.h>
#include <stdio.h> ///////////// <-------------- DELETE
#include <wchar.h> /////// ,___________
#include <string.h>// ,<<<<<<<<<<<<<<<<<<

typedef	struct	s_flags
{
	unsigned int	zero:1;
	unsigned int	minus:1;
	unsigned int	plus:1;
	unsigned int	sharp:1;
	unsigned int	space:1;
	unsigned int	long_db:1;
	unsigned int	apostr:1;
	unsigned int	sign:1;
	unsigned int	size:3;
}				t_flags;

typedef	struct	s_data
{
	unsigned char	buff[FT_PRINTF_BUFF_SIZE];
	size_t			buff_i;
	size_t			form_i;
	size_t			ret;
	char			chr;
	int				width;
	int				prec;
	t_flags			fl;
	va_list			begin;
	size_t			data_arg;
	unsigned int	error:1;
}				t_data;

int				ft_printf(const char *restrict format, ...);

void			ft_spec(t_data *d, const char *f, va_list *arg);

void			ft_print_buff(t_data *d);

void			ft_set_flags(t_data *d);

int				ft_star(t_data *d, const char *f, va_list *arg);

void			ft_conv(t_data *d, char chr, va_list *arg);

va_list			*ft_count_arg(t_data *d, int arg);

void			ft_int(t_data *d, va_list *arg, int base);

int				ft_count_dig(t_data *d, uintmax_t value, int base);
int				ft_count_double(long double val);

void			ft_printf_itoa(t_data *d, uintmax_t value, int base, int len);

void			ft_put_width(t_data *d, int val_len);
void			ft_put_prec(t_data *d, uintmax_t val, int len, int base);
void			ft_put_sign(t_data *d, uintmax_t val, int base);

void			ft_char(t_data *d, wchar_t value);

void			ft_string(t_data *d, char *value);
void			ft_wstring(t_data *d, wchar_t *value);

void			ft_write_chr(t_data *d, int *dest);

void			ft_float(t_data *d, long double val);
void			ft_expo_form(t_data *d, long double val);
void			ft_g_float(t_data *d, long double val);
void			ft_printf_dtoa(t_data *d, long double val, int val_len);

void			ft_handle_nan(t_data *d, long double val);

long double		ft_ldpow(long double val, size_t pow);

int				ft_calc_expo(t_data *d, long double *val);

long double		ft_get_float_val(t_data *d, va_list *arg);

#endif
