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

int							ft_count_dig(t_data *d, uintmax_t value, int base)
{
	register int	dig;

	if ((value == 0 && d->prec == 0 && base != 8) ||
		(base == 8 && d->fl.sharp == 0 && value == 0 &&
			d->prec == 0))
		return (0);
	dig = 1;
	while (value /= base)
		++dig;
	return (dig);
}
