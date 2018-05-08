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

static	void	ft_put_precision(t_data *d, int *precision)
{
	while ((*precision)-- > 0)
	{
		if (BUFF_SIZE <= d->buff_i)
			ft_print_buff(d);
		d->buff[d->buff_i++] = '0';
	}
}

static	void	ft_put_width_precision(t_data *d, unsigned int *dig)
{
	char	c;
	int		precision;

	precision = d->info.precision;
	c = ' ';
	if (d->info.zero == 1 && precision == -1)
		c = '0';
	if (precision > 0)
		precision -= *dig;
	else
		precision = 0;
	if (d->info.width > 0 && d->info.minus == 0)
		d->info.width -= *dig;
	while (d->info.minus == 0 && d->info.width > precision)
	{
		if (BUFF_SIZE <= d->buff_i)
			ft_print_buff(d);
		d->buff[d->buff_i++] = c;
		d->info.width--;
	}
	ft_put_precision(d, &precision);
}

static	void	ft_put_width(t_data *d,  unsigned int *dig)
{
	if (d->info.precision > 0)
		d->info.precision -= *dig;
	else
		d->info.precision = 0;
	if (d->info.width < 0)
		d->info.width *= -1;
	d->info.width -= *dig + d->info.precision;
	while (d->info.width-- > 0)
	{
		if (BUFF_SIZE <= d->buff_i)
			ft_print_buff(d);
		d->buff[d->buff_i++] = ' ';
	}
}

static	void	ft_count_digits(uintmax_t nbr, unsigned int *dig)
{
	*dig = 1;
	while (nbr /= 10)
		++(*dig);
}

void			ft_printf_itoa(t_data *d, uintmax_t nbr, int sign)
{
	unsigned int	dig;
	unsigned int	tmp;
	unsigned int	cpy_dig;

	ft_count_digits(nbr, &dig);
	cpy_dig = dig;
	if ((d->info.width > 0 && d->info.minus == 0) || d->info.precision != -1)
		ft_put_width_precision(d, &dig);
	if (sign)
		d->buff[d->buff_i++] = '-';
	else if (d->info.plus == 1)
		d->buff[d->buff_i++] = '+';
	if (BUFF_SIZE <= d->buff_i + cpy_dig)
		ft_print_buff(d);
	d->buff_i += cpy_dig - 1;
	tmp = d->buff_i;
	while (cpy_dig--)
	{
		d->buff[d->buff_i--] = nbr % 10 + '0';
		nbr /= 10;
	}
	d->buff_i = ++tmp;
	if (d->info.width < 0 || d->info.minus == 1)
		ft_put_width(d, &dig);
}
