/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 16:25:20 by rnovodra          #+#    #+#             */
/*   Updated: 2018/06/30 16:25:21 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/ft_printf.h"

void					ft_string(t_data *d, char *value)
{
	int		val_len;
	char	*begin;

	if (!value)
	{
		value = "(null)";
		val_len = 6;
	}
	else
		val_len = ft_strlen(value);
	if (d->prec >= 0 && d->prec < val_len)
		val_len = d->prec;
	d->prec = -1;
	if (d->fl.minus == 0)
		ft_put_width(d, val_len);
	begin = value;
	while (*value && value - begin < val_len)
	{
		FT_PRINTF_BUFF_SIZE == d->buff_i ? ft_print_buff(d) :
		(d->buff[d->buff_i++] = *value++);
	}
	if (d->fl.minus == 1)
		ft_put_width(d, val_len);
}
