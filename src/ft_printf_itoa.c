/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 18:34:30 by rnovodra          #+#    #+#             */
/*   Updated: 2018/06/28 18:34:32 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/ft_printf.h"

void			ft_printf_itoa(t_data *d, uintmax_t value, int base, int len)
{
	char	*str;
	int		i;

	d->buff_i += len;
	str = (d->chr == 'X' ? "0123456789ABCDEF" : "0123456789abcdef");
	i = 0;
	while (len > i++)
	{
		FT_PRINTF_BUFF_SIZE == d->buff_i ? ft_print_buff(d) :
			(d->buff[d->buff_i - i] = str[value % base]);
		value /= base;
	}
}
