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

void			ft_d(t_data *d)
{
	uintmax_t	nbr;

	if (d->data_arg != 0)
	{
		ft_get_arg(d, d->data_arg);
		d->pa_arg.pa_int = va_arg(d->param_arg, intmax_t);
	}
	else if (d->info.size == 0)
		d->pa_arg.pa_int = va_arg(d->argptr, int);
	else if (d->info.size == 1)
		d->pa_arg.pa_int = (signed char)va_arg(d->argptr, int);
	else if (d->info.size == 2)
		d->pa_arg.pa_int = (short)va_arg(d->argptr, int);
	else if (d->info.size == 3)
		d->pa_arg.pa_int = (long)va_arg(d->argptr, intmax_t);
	else if (d->info.size == 4)
		d->pa_arg.pa_int = (long long)va_arg(d->argptr, intmax_t);
	else if (d->info.size == 5)
		d->pa_arg.pa_int = (intmax_t)va_arg(d->argptr, intmax_t);
	else if (d->info.size == 6)
		d->pa_arg.pa_int = (ssize_t)va_arg(d->argptr, intmax_t);
	nbr = (d->pa_arg.pa_int > 0) ? d->pa_arg.pa_int : d->pa_arg.pa_int * -1;
	ft_printf_itoa(d, nbr, d->pa_arg.pa_int < 0);
}

