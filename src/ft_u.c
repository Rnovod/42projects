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

void			ft_u(t_data *d, int_fast32_t base)
{
	va_list		*tmp;

	d->info.plus = 0;
	d->info.space = 0;
	if (d->data_arg != 0)
		ft_get_arg(d, d->data_arg);
	tmp = d->data_arg != 0 ? &d->param_arg : &d->argptr;
	if (d->info.size == 0)
		d->pa_arg.pa_uint = (unsigned int)va_arg(*tmp, unsigned int);
	else if (d->info.size == 1)
		d->pa_arg.pa_uint = (unsigned char)va_arg(*tmp, int);
	else if (d->info.size == 2)
		d->pa_arg.pa_uint = (unsigned short)va_arg(*tmp, int);
	else if (d->info.size == 3)
		d->pa_arg.pa_uint = (unsigned long)va_arg(*tmp, uint_fast64_t);
	else if (d->info.size == 4)
		d->pa_arg.pa_uint = (unsigned long long)va_arg(*tmp, uint_fast64_t);
	else if (d->info.size == 5)
		d->pa_arg.pa_uint = (uint_fast64_t)va_arg(*tmp, uint_fast64_t);
	else if (d->info.size == 6)
		d->pa_arg.pa_uint = (size_t)va_arg(*tmp, uint_fast64_t);
	ft_printf_itoa(d, d->pa_arg.pa_uint, 0, base);
}
