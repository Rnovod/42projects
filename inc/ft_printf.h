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
# define BUFF_SIZE 4096
# include <stdarg.h>
# include <stdint.h>
# include <wchar.h>
# include <limits.h>
# include <unistd.h>
# include <locale.h>
# include <stdlib.h>
#include <stdio.h> ///////////// <-------------- DELETE
#include <wchar.h> /////// ,___________
#include <string.h>// ,<<<<<<<<<<<<<<<<<<

typedef	struct	s_info
{
	unsigned int	zero:1;
	unsigned int	minus:1;
	unsigned int	plus:1;
	unsigned int	sharp:1;
	unsigned int	space:1;
	unsigned int	up_case:1;
	unsigned int	adr:1;
	unsigned int	z:1;
	unsigned int	j:1;
	unsigned int	size:3;
	unsigned int	h:8;
	unsigned int	l:8;
	int				width;
	int				prec;
}				t_info;

typedef	union	u_printf_arg
{
	wchar_t			pa_wchar;
	uintmax_t		pa_uint;
	intmax_t		pa_int;
	char			*pa_str;
	wchar_t			*pa_wstr;
	float			pa_float;
	int				*pa_ptrint; 
}				t_printf_arg;

typedef	struct	s_data
{
	unsigned int	form_i;
	int				buff_i;
	t_printf_arg	pa_arg;
	t_info			info;
	unsigned char	buff[BUFF_SIZE + 1];
	unsigned int	error:1;
	unsigned int	ch;
	unsigned int	data_arg;
	va_list			argptr;
	va_list			begin;
	va_list			param_arg;
}				t_data;

int				ft_printf(const char *restrict format, ...);

void			ft_set_flags_null(t_data *d);

void			ft_print_buff(t_data *d);
void			ft_specification(t_data *d, const char *restrict format);
void			ft_conversion(t_data *d, const char *restrict format);

void			ft_printf_itoa(t_data *d, uintmax_t nbr, int sign, int base);
void			ft_printf_putchar(t_data *d, wchar_t charac);
void			ft_printf_putstr(t_data *d, char *str);
void			ft_putstr_unicode(t_data *d, wchar_t *str);
void			ft_itoa_float(t_data *d, float nbr, int sign);

int				ft_star(t_data *d, const char *restrict format);
void			ft_get_arg(t_data *d, int arg);

void			ft_u(t_data *d, int base);
void			ft_d(t_data *d);
void			ft_c(t_data *d);
void			ft_s(t_data *d);
void			ft_f(t_data *d);
void			ft_n(t_data *d);

#endif
