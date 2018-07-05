/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_nan.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 12:02:57 by rnovodra          #+#    #+#             */
/*   Updated: 2018/07/05 12:02:58 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/ft_printf.h"

void			ft_handle_nan(t_data *d, long double val)
{
	char	*str;
	char	flag;

	flag = d->chr == 'f' || d->chr == 'e';
	if (d->fl.sign)
		d->width--;
	if (INFINITY == val)
		str = flag ? "inf" : "INF";
	else
		str = flag ? "nan" : "NAN";
	if (!d->fl.minus)
		ft_put_width(d, 3);
	if (d->fl.sign)
		d->buff[d->buff_i++] = '-';
	while (*str)
	{
		FT_PRINTF_BUFF_SIZE == d->buff_i ? ft_print_buff(d) :
		(d->buff[d->buff_i++] = *str++);
	}
	if (d->fl.minus)
		ft_put_width(d, 3);
}
