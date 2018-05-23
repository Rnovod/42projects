/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 05:54:54 by rnovodra          #+#    #+#             */
/*   Updated: 2018/05/08 05:54:55 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/ft_printf.h"

inline	static	void	ft_uni_putchar(t_data *d, int_fast32_t len, wchar_t charac)
{
	if (BUFF_SIZE <= (d->buff_i + len))
		ft_print_buff(d);
	if (len == 1 || MB_CUR_MAX == 1)
		d->buff[d->buff_i++] = (char)charac;
	else if (len == 2)
	{
		d->buff[d->buff_i++] = ((charac & 0xFC0) >> 6) | (0xC080 >> 8);
		d->buff[d->buff_i++] = ((charac & 0x3F) | (0xC080));
	}
	else if (len == 3)
	{
		d->buff[d->buff_i++] = ((charac & 0x3F000) >> 12) | (0xE08080 >> 16);
		d->buff[d->buff_i++] = ((charac & 0xFC0) >> 6) | (0xE08080 >> 8);
		d->buff[d->buff_i++] = ((charac & 0x3F) | (0xE08080));
	}
	else
	{
		d->buff[d->buff_i++] = (charac >> 18) | (0xF0808080 >> 24);
		d->buff[d->buff_i++] = ((charac & 0x3F000) >> 12) | (0xF0808080 >> 16);
		d->buff[d->buff_i++] = ((charac & 0xFC0) >> 6) | (0xF0808080 >> 8);
		d->buff[d->buff_i++] = ((charac & 0x3F) | (0xF0808080));
	}
}

inline	static	void	ft_put_width(t_data *d, int_fast32_t len)
{
	register int_fast32_t	width;
	char					c;

	width = d->info.width;
	c = ' ';
	if (d->info.zero == 1 && d->info.prec <= 0 &&
		width > 0 && !d->info.minus)
		c = '0';
	if (width < 0)
		width *= -1;
	width -= len;
	while (width-- > 0)
	{
		if (BUFF_SIZE <= d->buff_i)
			ft_print_buff(d);
		d->buff[d->buff_i++] = c;
	}
}

void					ft_printf_putchar(t_data *d, wchar_t charac)
{
	int_fast32_t	len;

	if (charac <= 127 || d->info.size != 3)
		len = 1;
	else if (charac <= 2047)
		len = 2;
	else if (charac <= 65535)
		len = 3;
	else if (charac <= 1114111)
		len = 4;
	else
		len = 0;
	if (d->info.width > 0 && !d->info.minus)
		ft_put_width(d, len);
	ft_uni_putchar(d, len, charac);
	if (d->info.width < 0 || d->info.minus)
		ft_put_width(d, len);
}
