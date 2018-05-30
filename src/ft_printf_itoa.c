/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 02:22:23 by rnovodra          #+#    #+#             */
/*   Updated: 2018/05/08 02:22:24 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/ft_printf.h"

inline	static	void	ft_put_prec(t_data *d, int_fast32_t dig, int_fast32_t base)
{
	register int_fast32_t		prec;

	prec = d->info.prec - dig;
	if (d->info.sharp == 1 && base == 8 && d->pa_arg.pa_uint != 0)
		--prec;
	while (prec-- > 0)
	{
		if (BUFF_SIZE <= d->buff_i)
			ft_print_buff(d);
		d->buff[d->buff_i++] = '0';
	}
}

inline	static	void	ft_put_width(t_data *d, int_fast32_t dig,
					int_fast32_t sign, int_fast32_t base)
{
	register int_fast32_t	width;
	char					c;
	int_fast32_t			prec;

	prec = d->info.prec - dig - (d->info.sharp == 1 && base == 8);
	width = d->info.width;
	c = ' ';
	if (d->info.zero && d->info.prec == -1 && !d->info.minus)
		c = '0';
	if (prec < 0)
		prec = 0;
	width -= (dig + prec);
	if (sign || d->info.plus || (d->info.sharp == 1 &&
		(base == 8 || base == 16)) ||
		(d->info.space && !sign && !d->info.plus))
		--width;
	if (base == 16 && d->info.sharp == 1)
		--width;
	while (width-- > 0)
	{
		if (BUFF_SIZE <= d->buff_i)
			ft_print_buff(d);
		d->buff[d->buff_i++] = c;
	}
}

inline	static	int_fast32_t	ft_count_digits(t_data *d, uint_fast64_t nbr, int_fast32_t base)
{
	register uint_fast32_t	dig;

	if ((nbr == 0 && d->info.prec == 0 && base != 8) ||
		(base == 8 && d->info.sharp == 0 && nbr == 0 &&
			d->info.prec == 0))
		return (0);
	dig = 1;
	while (nbr /= base)
		++dig;
	return (dig);
}

inline	static	void	ft_put_width_prec(t_data *d, int dig, int sign, int base)
{
	if (d->info.minus == 0 && !d->info.zero)
		ft_put_width(d, dig, sign, base);
	if (d->info.plus && !sign)
		d->buff[d->buff_i++] = '+';
	else if (sign)
		d->buff[d->buff_i++] = '-';
	else if (d->info.space && !sign && !d->info.plus)
		d->buff[d->buff_i++] = ' ';
	if (d->info.sharp == 1 && (base == 8 || base == 16) &&
		(d->pa_arg.pa_uint != 0 || d->info.adr == 1))
	{
		d->buff[d->buff_i++] = '0';
		if (base == 16 && d->info.up_case == 0)
			d->buff[d->buff_i++] = 'x';
		else if (base != 8)
			d->buff[d->buff_i++] = 'X';
	}
	if (d->info.minus == 0 && d->info.zero)
		ft_put_width(d, dig, sign, base);
	if (d->info.prec > 0 && d->info.prec > dig)
		ft_put_prec(d, dig, base);
}

void					ft_printf_itoa(t_data *d, uint_fast64_t nbr,
						int_fast32_t sign, int_fast32_t base)
{
	register int_fast32_t	tmp;
	int_fast32_t			dig;
	char					*str;

	str = ((d->info.up_case == 1 && base == 16) ?
		"0123456789ABCDEF" : "0123456789abcdef");
	dig = ft_count_digits(d, nbr, base);
	ft_put_width_prec(d, dig, sign, base);
	if (BUFF_SIZE <= d->buff_i + dig)
		ft_print_buff(d);
	tmp = dig;
	while (tmp--)
	{
		d->buff[d->buff_i + tmp] = str[nbr % base];
		nbr /= base;
	}
	d->buff_i += dig;
	if (d->info.minus == 1)
		ft_put_width(d, dig, sign, base);
}
