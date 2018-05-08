/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_default.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 17:45:34 by rnovodra          #+#    #+#             */
/*   Updated: 2018/05/07 17:45:35 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/ft_printf.h"

void		ft_set_flags_null(t_data *d)
{
	d->info.zero = 0;
	d->info.minus = 0;
	d->info.plus = 0;
	d->info.space = 0;
	d->info.sharp = 0;
	d->info.precision = -1;
	d->info.width = 0;
	d->info.size = 0;
	d->data_arg = 0;
}
