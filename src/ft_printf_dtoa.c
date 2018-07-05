/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dtoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 13:33:41 by rnovodra          #+#    #+#             */
/*   Updated: 2018/07/04 13:33:41 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/ft_printf.h"

inline	static	void	ft_pre_point(t_data *d, long double *val, int val_len)
{
	long double		dec_size;

	dec_size = 1l;
	while (*val / dec_size >= 10.0l)
		dec_size *= 10.0l;
	while (val_len--)
	{
		FT_PRINTF_BUFF_SIZE == d->buff_i ? ft_print_buff(d) :
		(d->buff[d->buff_i++] = (unsigned char)(*val / dec_size) + '0');
		*val -= (unsigned long int)(*val / dec_size) * dec_size;
		dec_size /= 10.0l;
	}
}

inline	static	void	ft_aft_point(t_data *d, long double val)
{
	int				prec;

	prec = d->prec;
	val = (val - (unsigned long int)(val)) * 10.0l;
	while (prec > 0)
	{
		FT_PRINTF_BUFF_SIZE == d->buff_i ? ft_print_buff(d) :
		(d->buff[d->buff_i++] = (unsigned char)val + '0');
		val = (val - (unsigned long int)(val)) * 10.0l;
		--prec;
	}
}

void					ft_printf_dtoa(t_data *d, long double val, int val_len)
{
	ft_pre_point(d, &val, val_len);
	if (d->prec > 0 || d->fl.sharp == 1)
	{
		d->buff[d->buff_i++] = '.';
		if (d->prec > 0)
			ft_aft_point(d, val);
	}
}
