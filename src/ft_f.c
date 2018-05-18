/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 16:21:59 by rnovodra          #+#    #+#             */
/*   Updated: 2018/05/17 16:22:00 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/ft_printf.h"

void			ft_f(t_data *d)
{
	long double		nbr;

	if (d->data_arg != 0)
	{
		ft_get_arg(d, d->data_arg);
		d->pa_arg.pa_ldouble = va_arg(d->param_arg, double);
	}
	else
		d->pa_arg.pa_ldouble = va_arg(d->argptr, double);
	nbr = (d->pa_arg.pa_ldouble > 0) ? d->pa_arg.pa_ldouble : d->pa_arg.pa_ldouble * -1;
	ft_itoa_double(d, nbr, d->pa_arg.pa_ldouble < 0);
}

