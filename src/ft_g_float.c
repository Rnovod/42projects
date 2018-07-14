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
	long double		tmp;

	tmp = val;
	ft_calc_expo(d, &tmp);
	if ((uintmax_t)val)
		d->prec--;
	if (!d->fl.sharp)
		d->prec = ft_count_prec(d, tmp);
	ft_expo_form(d, val);
}

inline	static	void	ft_prepare_f(t_data *d, long double val)
{
	long double		tmp;
	long double		downpow;
	const int		val_len = ft_count_double(val, 0);

	tmp = val + 0.5l * ft_ldpow(0.1l, d->prec - val_len);
	downpow = 1l;
	while ((tmp / downpow) >= 10.0l)
		downpow *= 10.0l;
	while (tmp >= 10.0l)
	{
		tmp -= ((uintmax_t)(tmp / downpow)) * downpow;
		downpow /= 10.0l;
	}
	d->prec -= val_len;
	if (!d->fl.sharp)
		d->prec = ft_count_prec(d, tmp);
	ft_float(d, val);
}

void					ft_g_float(t_data *d, long double val)
{
	int				expo;
	long double		tmp;

	if (val != val || val == INFINITY)
	{
		ft_handle_nan(d, val);
		return ;
	}
	if (d->prec == 0)
		d->prec = 1;
	tmp = val;
	expo = ft_calc_expo(d, &tmp);
	if (expo < -4 || expo >= d->prec)
		ft_prepare_e(d, val);
	else
		ft_prepare_f(d, val);
}
