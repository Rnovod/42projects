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

inline	static	int		ft_count_prec(t_data *d, long double val)
{
	size_t		len;
	size_t		i;

	len = 0;
	i = 0;
	val = (val - (uintmax_t)val) * 10.0l;
	while ((long long)i++ < d->prec)
	{
		if ((uintmax_t)val)
			len = i;
		val = (val - (uintmax_t)val) * 10.0l;
	}
	return (len);
}

inline	static	void	ft_prepare_e(t_data *d, long double val)
{
	d->prec = ft_count_prec(d, val);
	ft_expo_form(d, val);
}

inline	static	void	ft_prepare_f(t_data *d, long double val)
{
	long double		tmp;
	long double		downpow;

	tmp = val + 0.5l * ft_ldpow(0.1l, d->prec);
	downpow = 1l;
	while ((tmp / downpow) >= 10l)
		downpow *= 10l;
	while (tmp >= 10l)
	{
		tmp -= ((uintmax_t)(tmp / downpow)) * downpow;
		if (d->prec)
			--d->prec;
		downpow /= 10l;
	}
	d->prec = ft_count_prec(d, val);
	ft_float(d, val);
}

void					ft_g_float(t_data *d, long double val)
{
	int				expo;

	if (val != val || val == INFINITY)
	{
		ft_handle_nan(d, val);
		return ;
	}
	if (d->prec == 0)
		d->prec = 1;
	if (d->prec == -1)
		d->prec = 6;
	expo = ft_calc_expo(d, &val);
	if (expo < -4 || expo >= d->prec)
		ft_prepare_e(d, val);
	else
		ft_prepare_f(d, val);
}
