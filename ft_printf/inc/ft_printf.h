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
#include <stdio.h> ///////////// <-------------- DELETE

typedef	struct	s_info
{
	int				width;
	int				precision;
	unsigned int	zero:1;
	unsigned int	minus:1;
	unsigned int	plus:1;
	unsigned int	sharp:1;
	unsigned int	space:1;
	unsigned int	size:3;
}				t_info;

typedef	union	u_printf_arg
{
	wchar_t			pa_wchar;
	uintmax_t		pa_uint;
	intmax_t		pa_int;
}				t_printf_arg;

typedef	struct	s_data
{
	va_list			argptr;
	va_list			begin;
	va_list			param_arg;
	t_info			info;
	t_printf_arg	pa_arg;
	char			buff[BUFF_SIZE + 1];
	unsigned int	data_arg;
	unsigned int	form_i;
	unsigned int	buff_i;
	unsigned int	ch;
	unsigned int	error:1;
}				t_data;

int				ft_printf(const char *restrict format, ...);

void			ft_set_flags_null(t_data *d);

void			ft_print_buff(t_data *d);
void			ft_specification(t_data *d, const char *restrict format);
void			ft_conversion(t_data *d, const char *restrict format);

void			ft_printf_itoa(t_data *d, uintmax_t nbr, int sign);

int				ft_star(t_data *d, const char *restrict format);
void			ft_get_arg(t_data *d, int arg);

int				ft_is_size(t_data *d, const char *restrict format);

void			ft_manage_precision(t_data *d, const char *restrict format);
void			ft_manage_flags(t_data *d, const char *restrict format);
void			ft_manage_digits(t_data *d, const char *restrict format);
void			ft_manage_size(t_data *d, const char *restrict format);

void			ft_d(t_data *d);

#endif
