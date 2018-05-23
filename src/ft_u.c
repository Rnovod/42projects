/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 06:38:06 by rnovodra          #+#    #+#             */
/*   Updated: 2018/05/08 06:38:07 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/ft_printf.h"

inline	static void		ft_u_arg(t_data *d)
{
	ft_get_arg(d, d->data_arg);
	if (d->info.size == 0)
		d->pa_arg.pa_uint = (unsigned int)va_arg(d->param_arg, int);
	else if (d->info.size == 1)
		d->pa_arg.pa_uint = (unsigned char)va_arg(d->param_arg, int);
	else if (d->info.size == 2)
		d->pa_arg.pa_uint = (unsigned short)va_arg(d->param_arg, int);
	else if (d->info.size == 3)
		d->pa_arg.pa_uint = (unsigned long)va_arg(d->param_arg, uint_fast64_t);
	else if (d->info.size == 4)
		d->pa_arg.pa_uint = (unsigned long long)va_arg(d->param_arg, uint_fast64_t);
	else if (d->info.size == 5)
		d->pa_arg.pa_uint = (uint_fast64_t)va_arg(d->param_arg, uint_fast64_t);
	else if (d->info.size == 6)
		d->pa_arg.pa_uint = (size_t)va_arg(d->param_arg, uint_fast64_t);
}

void			ft_u(t_data *d, int_fast32_t base)
{
	d->info.plus = 0;
	d->info.space = 0;
	if (d->data_arg != 0)
		ft_u_arg(d);
	else if (d->info.size == 0)
		d->pa_arg.pa_uint = (unsigned int)va_arg(d->argptr, unsigned int);
	else if (d->info.size == 1)
		d->pa_arg.pa_uint = (unsigned char)va_arg(d->argptr, int);
	else if (d->info.size == 2)
		d->pa_arg.pa_uint = (unsigned short)va_arg(d->argptr, int);
	else if (d->info.size == 3)
		d->pa_arg.pa_uint = (unsigned long)va_arg(d->argptr, uint_fast64_t);
	else if (d->info.size == 4)
		d->pa_arg.pa_uint = (unsigned long long)va_arg(d->argptr, uint_fast64_t);
	else if (d->info.size == 5)
		d->pa_arg.pa_uint = (uint_fast64_t)va_arg(d->argptr, uint_fast64_t);
	else if (d->info.size == 6)
		d->pa_arg.pa_uint = (size_t)va_arg(d->argptr, uint_fast64_t);
	ft_printf_itoa(d, d->pa_arg.pa_uint, 0, base);
}
