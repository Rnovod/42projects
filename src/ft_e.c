/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_e.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 17:08:47 by rnovodra          #+#    #+#             */
/*   Updated: 2018/05/29 17:08:47 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/ft_printf.h"

inline	static	long double		ft_ldpow(long double nbr, size_t pow)
{
	long double		res;

	res = 1l;
	while (pow)
	{
		if (pow & 1)
			res *= nbr;
		nbr *= nbr;
		pow >>= 1;
	}
	return (res);
}

inline	static	void		ft_put_width(t_data *d, int_fast32_t len)
{
	register int_fast32_t	width;
	char					c;

	width = d->info.width - len;
	c = ' ';
	while (width-- > 0)
	{
		if (BUFF_SIZE <= d->buff_i + width)
			ft_print_buff(d);
		d->buff[d->buff_i++] = c;
	}
}

inline	static	void			ft_handle_nan(t_data *d, long double nbr)
{
	char	*str;

	if (const_inf == nbr)
		str = "inf";
	else
		str = "nan";
	if (!d->info.minus)
		ft_put_width(d, 3);
	while (*str)
	{
		if (BUFF_SIZE <= d->buff_i)
			ft_print_buff(d);
		d->buff[d->buff_i++] = *str++;
	}
	if (d->info.minus)
		ft_put_width(d, 3);
}

inline	static	int_fast32_t	ft_calc_expo(t_data *d, long double *nbr)
{
	int_fast32_t	expo;

	expo = 0;
	while (*nbr >= 10.0l)
	{
		*nbr /= 10.0l;
		++expo;
	}
	while (*nbr < 1.0l)
	{
		*nbr *= 10.0l;
		--expo;
	}
	while ((*nbr += 0.5l * ft_ldpow(1.0l / 10l, d->info.prec)) >= 10l)
	{
		*nbr /= 10l;
		++expo;
	}
	return (expo);
}

inline	static	void			ft_put_expo(t_data *d, int_fast32_t expo)
{
	if (BUFF_SIZE <= d->buff_i + 3)
		ft_print_buff(d);
	d->buff[d->buff_i++] = (d->info.up_case == 1) ? 'E' : 'e';
	d->buff[d->buff_i++] = (expo > 0) ?  '+' : '-';
	if (expo < 0)
		expo = -expo;
	if (expo < 10)
		d->buff[d->buff_i++] = '0';
	while (expo != 0)
	{
		if (BUFF_SIZE <= d->buff_i)
			ft_print_buff(d);
		d->buff[d->buff_i++] = expo % 10 + '0';
		expo /= 10;
	}
}

void							ft_e(t_data *d)
{
	long double		nbr;
	int_fast32_t	expo;
	va_list			*tmp;

	if (d->data_arg != 0)
	{
		ft_get_arg(d, d->data_arg);
		tmp = &d->param_arg;
	}
	else
		tmp = &d->argptr;
	if (d->info.Ld == 0)
		d->pa_arg.pa_ldouble = va_arg(*tmp, double);
	else
		d->pa_arg.pa_ldouble = va_arg(*tmp, long double);
	nbr = (d->pa_arg.pa_ldouble > 0) ? d->pa_arg.pa_ldouble : -d->pa_arg.pa_ldouble;
	if (d->info.prec < 0)
		d->info.prec = 6;
	if (const_inf == nbr || nbr != nbr)
		ft_handle_nan(d, nbr);
	else
	{
		expo = ft_calc_expo(d, &nbr);
		ft_itoa_double(d, nbr, d->pa_arg.pa_ldouble < 0);
		ft_put_expo(d, expo);
	}
}

