/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 17:34:26 by rnovodra          #+#    #+#             */
/*   Updated: 2018/05/17 17:34:28 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/ft_printf.h"

long double		ft_ldpow(long double val, size_t pow)
{
	long double		res;

	res = 1l;
	while (pow)
	{
		if (pow & 1)
		{
			res *= val;
		}
		val *= val;
		pow >>= 1;
	}
	return (res);
}

inline	static	void	ft_put_width(t_data *d, uint_fast32_t dig, int sign)
{
	register int	width;
	char			c;
	int				prec;

	prec = d->info.prec - dig;
	width = d->info.width;
	c = ' ';
	if (d->info.zero && width > 0 && !d->info.minus)
		c = '0';
	width = width < 0 ? width * -1 - (dig + prec) :
		width - (dig + prec);
	if (sign || d->info.plus ||
		(d->info.space && !sign && !d->info.plus))
		--width;
	while (width-- > 0)
	{
		if (BUFF_SIZE <= d->buff_i)
			ft_print_buff(d);
		d->buff[d->buff_i++] = c;
	}
}

inline	static	void	ft_put_width_prec(t_data *d, uint_fast32_t dig, int_fast32_t sign)
{
	if (d->info.minus == 0 && d->info.width > 0 && !d->info.zero)
		ft_put_width(d, dig, sign);
	if (d->info.plus && !sign)
		d->buff[d->buff_i++] = '+';
	else if (sign)
		d->buff[d->buff_i++] = '-';
	else if (d->info.space && !sign && !d->info.plus)
		d->buff[d->buff_i++] = ' ';
	if (d->info.minus == 0 && d->info.width > 0 && d->info.zero)
		ft_put_width(d, dig, sign);
}

inline	static	size_t	ft_count_double(long double nbr)
{
	size_t			len;

	len = 1;
	while (nbr > 10.0l)
	{
		nbr /= 10.0l;
		++len;
	}
	return (len);
}

void					ft_itoa_double(t_data *d, long double nbr, int_fast32_t sign)
{
	long double 		len_nbr;
	uint_fast32_t		dig;
	uint_fast32_t		cp_dig;

	len_nbr = 1l;
	dig = ft_count_double(nbr);
	cp_dig = dig;
	if (d->info.prec < 0)
		d->info.prec = 6;
	ft_put_width_prec(d, dig, sign);
	nbr = nbr + 0.5l * ft_ldpow(1.0l / 10l, d->info.prec);
	while (nbr / len_nbr >= 10.0l)
		len_nbr *= 10.0l;
	if (BUFF_SIZE <= d->buff_i + nbr)
		ft_print_buff(d);
	while (dig--)
	{
		d->buff[d->buff_i++] = (nbr / len_nbr) + '0';
		nbr -= (uint_fast64_t)(nbr / len_nbr) * len_nbr;
		len_nbr /= 10.0l;
	}
	d->buff[d->buff_i++] = '.';
	nbr = (nbr - (uint_fast64_t)(nbr)) * 10.0l;
	if (BUFF_SIZE <= d->buff_i + d->info.prec)
		ft_print_buff(d);
	while (d->info.prec > 0)
	{
		d->buff[d->buff_i++] = (unsigned char)nbr + '0';
		nbr = (nbr - (uint_fast64_t)(nbr)) * 10.0l;
		--d->info.prec;
	}
	if (d->info.minus == 1 || d->info.width < 0)
		ft_put_width(d, cp_dig, sign);
}
