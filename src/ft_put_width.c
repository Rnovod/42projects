/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 13:47:06 by rnovodra          #+#    #+#             */
/*   Updated: 2018/06/30 13:47:07 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/ft_printf.h"

void	ft_put_width(t_data *d, int val_len)
{
	char	c;
	int		width;
	int		prec;

	prec = d->prec - val_len;
	c = ' ';
	width = d->width;
	if (d->fl.zero && d->prec < 0 && !d->fl.minus)
		c = '0';
	if (prec < 0 || val_len == 0)
		prec = 0;
	width -= (val_len + prec);
	while (width-- > 0)
	{
		FT_PRINTF_BUFF_SIZE == d->buff_i ? ft_print_buff(d) :
		(d->buff[d->buff_i++] = c);
	}
	d->width = width;
}
