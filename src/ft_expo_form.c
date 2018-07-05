/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expo_form.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 12:35:48 by rnovodra          #+#    #+#             */
/*   Updated: 2018/07/05 12:35:49 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/ft_printf.h"

inline	static	int				ft_calc_expo(t_data *d, long double *nbr)
{
	int		expo;
	int		check;

	expo = 0;
	while (*nbr >= 10.0l)
	{
		*nbr /= 10.0l;
		++expo;
	}
	check = 0;
	while (*nbr < 1.0l && ++check < 1000)
	{
		*nbr *= 10.0l;
		--expo;
	}
	while ((*nbr += 0.5l * ft_ldpow(0.1l, d->prec)) >= 10l)
	{
		*nbr /= 10l;
		++expo;
	}
	if (check == 1000)
		return (0);
	return (expo);
}

inline	static	void			ft_put_expo(t_data *d, int expo, int expo_len)
{
	int		i;

	if (FT_PRINTF_BUFF_SIZE <= d->buff_i + 3)
		ft_print_buff(d);
	d->buff[d->buff_i++] = (d->chr == 'E') ? 'E' : 'e';
	d->buff[d->buff_i++] = (expo >= 0) ? '+' : '-';
	if (expo < 0)
		expo = -expo;
	i = 0;
	if (expo < 10)
		d->buff[d->buff_i++] = '0';
	d->buff_i += expo_len;
	while (i++ < expo_len)
	{
		FT_PRINTF_BUFF_SIZE == d->buff_i ? ft_print_buff(d) :
			(d->buff[d->buff_i - i] = "0123456789"[expo % 10]);
		expo /= 10;
	}
}

void							ft_expo_form(t_data *d, va_list *arg)
{
	long double	val;
	int			expo;
	int			val_len;
	int			expo_len;

	val = ft_get_float_val(d, arg);
	if (val != val || val == INFINITY)
	{
		ft_handle_nan(d, val);
		return ;
	}
	expo = ft_calc_expo(d, &val);
	expo_len = ft_count_dig(d, expo < 0 ? -expo : expo, 10);
	val_len = ft_count_double(val);
	d->width -= 2 + (expo_len < 10 ? 2 : expo_len);
	if (!d->fl.minus && !d->fl.zero)
		ft_put_width(d, val_len);
	if (d->fl.plus || d->fl.minus || d->fl.space || d->fl.sign)
		ft_put_sign(d, 0, 0);
	if (!d->fl.minus && d->fl.zero)
		ft_put_width(d, val_len);
	ft_printf_dtoa(d, val, val_len);
	ft_put_expo(d, expo, expo_len);
	if (d->fl.minus)
		ft_put_width(d, val_len);
}
