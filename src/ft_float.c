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

inline	static	long double	ft_get_val(t_data *d, va_list *arg)
{
	long double	val;

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

inline	static	long double		ft_ldpow(long double val, size_t pow)
{
	long double		res;

	res = 1l;
	while (pow)
	{
		if (pow & 1)
			res *= val;
		val *= val;
		pow >>= 1;
	}
	return (res);
}

inline	static	void			ft_handle_nan(t_data *d, long double val)
{
	char	*str;

	if (const_inf == val)
		str = "inf";
	else
		str = "nan";
	if (!d->fl.minus)
		ft_put_width(d, 3);
	while (*str)
	{
		FT_PRINTF_BUFF_SIZE == d->buff_i ? ft_print_buff(d) :
		(d->buff[d->buff_i++] = *str++);
	}
	if (d->fl.minus)
		ft_put_width(d, 3);
}

inline	static	void			ft_put_sign(t_data *d)
{
	if (d->fl.plus && !d->fl.sign)
		d->buff[d->buff_i++] = '+';
	else if (d->fl.sign)
		d->buff[d->buff_i++] = '-';
	else if (d->fl.space && !d->fl.sign && !d->fl.plus)
		d->buff[d->buff_i++] = ' ';
}

void							ft_float(t_data *d, va_list *arg)
{
	const	long double	val = ft_get_val(d, arg);
	int					val_len;

	if (const_inf == val || val != val)
	{
		ft_handle_nan(d, val);
		return ;
	}
	if (d->prec < 0)
		d->prec = 6;
	if (d->prec > 0)
		--d->width;
	val_len = ft_count_double(val);
	if (!d->fl.minus && !d->fl.zero)
		ft_put_width(d, val_len);
	if (d->fl.plus || d->fl.minus || d->fl.space || d->fl.sign)
		ft_put_sign(d);
	if (!d->fl.minus && d->fl.zero)
		ft_put_width(d, val_len);
	ft_printf_dtoa(d, val + 0.5l *
			ft_ldpow(1.0l / 10l, d->prec), val_len);
	if (d->fl.minus)
		ft_put_width(d, val_len);
}
