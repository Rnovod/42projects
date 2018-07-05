/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_float_val.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 12:40:07 by rnovodra          #+#    #+#             */
/*   Updated: 2018/07/05 12:40:10 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/ft_printf.h"

long double		ft_get_float_val(t_data *d, va_list *arg)
{
	long double	val;

	d->fl.zero = 0;
	d->fl.sharp = 0;
	if (d->fl.long_db)
		val = va_arg(*arg, long double);
	else
		val = va_arg(*arg, double);
	if (val < 0)
	{
		d->fl.sign = 1;
		return (-val);
	}
	return (val);
}
