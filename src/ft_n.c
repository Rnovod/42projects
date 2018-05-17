/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_n.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 21:23:15 by rnovodra          #+#    #+#             */
/*   Updated: 2018/05/17 21:23:16 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/ft_printf.h"

void			ft_n(t_data *d)
{
	if (d->data_arg != 0)
	{
		ft_get_arg(d, d->data_arg);
		d->pa_arg.pa_ptrint = va_arg(d->param_arg, int*);
	}
	else
		d->pa_arg.pa_ptrint = va_arg(d->argptr, int*);
	if (d->ch)
		*(d->pa_arg.pa_ptrint) = d->ch;
	else
		*(d->pa_arg.pa_ptrint) = d->buff_i;
}

