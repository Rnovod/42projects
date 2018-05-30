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

inline	static	void	ft_put_width(t_data *d, uint_fast32_t dig, int sign)
{
	register int	width;
	char			c;
	int				prec;

	prec = d->info.prec;
	width = d->info.width;
	c = ' ';
	if (d->info.zero && width > 0 && !d->info.minus)
		c = '0';
	width -= (dig + prec);
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

inline	static	void	ft_put_flags(t_data *d, uint_fast32_t dig, int_fast32_t sign)
{
	if (d->info.minus == 0 && !d->info.zero)
		ft_put_width(d, dig, sign);
	if (d->info.plus && !sign)
		d->buff[d->buff_i++] = '+';
	else if (sign)
		d->buff[d->buff_i++] = '-';
	else if (d->info.space && !sign && !d->info.plus)
		d->buff[d->buff_i++] = ' ';
	if (d->info.minus == 0 && d->info.zero)
		ft_put_width(d, dig, sign);
}

inline	static	uint_fast32_t	ft_count_double(long double nbr)
{
	uint_fast32_t		len;

	len = 1;
	while (nbr > 10.0l)
	{
		nbr /= 10.0l;
		++len;
	}
	return (len);
}

inline	static	void	ft_before_point(t_data *d, long double *nbr, uint_fast32_t dig)
{
	long double 		dec_size;

	dec_size = 1l;
	while (*nbr / dec_size >= 10.0l)
		dec_size *= 10.0l;
	while (dig--)
	{
		if (BUFF_SIZE <= d->buff_i)
			ft_print_buff(d);
		d->buff[d->buff_i++] = (unsigned char)(*nbr / dec_size) + '0';
		*nbr -= (uint_fast64_t)(*nbr / dec_size) * dec_size;
		dec_size /= 10.0l;
	}
}

inline	static	void	ft_after_point(t_data *d, long double nbr)
{
	int				prec;

	prec = d->info.prec;
	nbr = (nbr - (uint_fast64_t)(nbr)) * 10.0l;
	while (prec > 0)
	{
		if (BUFF_SIZE <= d->buff_i)
			ft_print_buff(d);
		d->buff[d->buff_i++] = (unsigned char)nbr + '0';
		nbr = (nbr - (uint_fast64_t)(nbr)) * 10.0l;
		--prec;
	}
}

void					ft_itoa_double(t_data *d, long double nbr,
						int_fast32_t sign)
{
	uint_fast32_t		dig;

	if (d->info.prec > 0)
		--d->info.width;
	dig = ft_count_double(nbr);
	ft_put_flags(d, dig, sign);
	ft_before_point(d, &nbr, dig);
	if (d->info.prec > 0 || d->info.sharp == 1)
	{
		d->buff[d->buff_i++] = '.';
		if (d->info.prec > 0)
			ft_after_point(d, nbr);
	}
	if (d->info.minus == 1)
		ft_put_width(d, dig, sign);
}
