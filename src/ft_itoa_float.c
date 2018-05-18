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

inline	static	void	ft_put_width(t_data *d, int dig, int sign)
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

inline	static	void	ft_put_width_prec(t_data *d, int dig, int sign)
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

inline	static	size_t	ft_count_double(uintmax_t nbr)
{
	size_t	len;

	len = 1;
	while (nbr /= 10)
		len++;
	return (len);
}

void					ft_itoa_double(t_data *d, long double nbr, int sign)
{
	size_t				dig;
	uintmax_t			integer;
	register int		tmp;
	int					calc;

	integer = nbr;
	dig = ft_count_double(integer);
	nbr -= (long double)integer;
	if (d->info.prec < 0)
		d->info.prec = 6;
	ft_put_width_prec(d, dig, sign);
	d->buff_i += dig - 1;
	tmp = d->buff_i++;
	calc = d->buff_i - dig - 1;
	while (calc < tmp)
	{
		d->buff[tmp--] = "0123456789"[integer % 10];
		integer /= 10;
	}
	if (d->info.prec != 0)
	{
		d->buff[d->buff_i++] = '.';
		nbr *= pow(10, d->info.prec);
		integer = round(nbr);
		dig = ft_count_double(integer);
		d->buff_i += dig - 1;
		tmp = d->buff_i++;
		calc = d->buff_i - dig - 1;
		while (calc < tmp)
		{
			d->buff[tmp--] = "0123456789"[integer % 10];
			integer /= 10;
		}
	}
	if (d->info.minus == 1 || d->info.width < 0)
		ft_put_width(d, dig, sign);
}
