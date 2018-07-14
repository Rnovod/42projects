/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_dig.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 13:25:35 by rnovodra          #+#    #+#             */
/*   Updated: 2018/06/30 13:25:36 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/ft_printf.h"

int		ft_count_dig(t_data *d, uintmax_t value, int base)
{
	int		len;

	if (d && ((value == 0 && d->prec == 0 && base != 8) ||
		(base == 8 && d->fl.sharp == 0 && value == 0 &&
			d->prec == 0)))
		return (0);
	len = 1;
	while (value /= base)
		++len;
	if (d && d->fl.apostr && base != 16)
		return (len + (len - 1) / 3);
	return (len);
}

int		ft_count_double(long double val, char apostr)
{
	int		len;

	val /= 10.0l;
	len = 1;
	while (val >= 1)
	{
		val /= 10.0l;
		++len;
	}
	if (apostr)
		return (len + (len - 1) / 3);
	return (len);
}
