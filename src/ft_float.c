/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 13:04:29 by rnovodra          #+#    #+#             */
/*   Updated: 2018/07/04 13:04:30 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/ft_printf.h"

void			ft_float(t_data *d, long double val)
{
	int					val_len;

	if (val != val || val == INFINITY)
	{
		ft_handle_nan(d, val);
		return ;
	}
	if (d->prec < 0)
		d->prec = 6;
	if (d->prec > 0)
		d->width -= 2;
	val_len = ft_count_double(val);
	if (!d->fl.minus && !d->fl.zero)
		ft_put_width(d, val_len);
	if (d->fl.plus || d->fl.minus || d->fl.space || d->fl.sign)
		ft_put_sign(d, 0, 0);
	if (!d->fl.minus && d->fl.zero)
		ft_put_width(d, val_len);
	ft_printf_dtoa(d, val + 0.5l *
			ft_ldpow(0.1l, d->prec), val_len);
	if (d->fl.minus)
		ft_put_width(d, val_len);
}
