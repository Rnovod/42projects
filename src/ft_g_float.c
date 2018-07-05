/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_g_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 15:15:29 by rnovodra          #+#    #+#             */
/*   Updated: 2018/07/05 15:15:30 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/ft_printf.h"

void			ft_g_float(t_data *d, long double val)
{
	int				expo;
	long double		tmp;

	if (val != val || val == INFINITY)
	{
		ft_handle_nan(d, val);
		return ;
	}
	if (d->prec == -1)
		d->prec = 0;
	tmp = val;
	expo = ft_calc_expo(d, &tmp);
	if (expo < -4 || expo >= d->prec)
		ft_float(d, val);
	else
		ft_expo_form(d, val);
}
