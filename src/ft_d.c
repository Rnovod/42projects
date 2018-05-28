/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 18:45:08 by rnovodra          #+#    #+#             */
/*   Updated: 2018/05/03 18:45:09 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/ft_printf.h"

void					ft_d(t_data *d)
{
	va_list			*tmp;

	if (d->data_arg != 0)
	{
		ft_get_arg(d, d->data_arg);
		tmp = &d->param_arg;
	}
	else
		tmp = &d->argptr;
	if (d->info.size == 0)
		d->pa_arg.pa_int = va_arg(*tmp, int);
	else if (d->info.size == 1)
		d->pa_arg.pa_int = (signed char)va_arg(*tmp, int);
	else if (d->info.size == 2)
		d->pa_arg.pa_int = (short)va_arg(*tmp, int);
	else if (d->info.size == 3)
		d->pa_arg.pa_int = (long)va_arg(*tmp, int_fast64_t);
	else if (d->info.size == 4)
		d->pa_arg.pa_int = (long long)va_arg(*tmp, int_fast64_t);
	else if (d->info.size == 5)
		d->pa_arg.pa_int = (int_fast64_t)va_arg(*tmp, int_fast64_t);
	else if (d->info.size == 6)
		d->pa_arg.pa_int = (ssize_t)va_arg(*tmp, int_fast64_t);
	ft_printf_itoa(d, ((d->pa_arg.pa_int > 0) ? d->pa_arg.pa_int : -d->pa_arg.pa_int),
		d->pa_arg.pa_int < 0, 10);
}
