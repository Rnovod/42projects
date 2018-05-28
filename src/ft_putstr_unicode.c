/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_unicode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 20:24:44 by rnovodra          #+#    #+#             */
/*   Updated: 2018/05/16 20:24:46 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/ft_printf.h"

inline	static	uint_fast32_t	ft_size_wchar(wchar_t ch)
{
	if (ch <= 127)
		return (1);
	else if (ch <= 2047)
		return (2);
	else if (ch <= 65535)
		return (3);
	else if (ch <= 1114111)
		return (4);
	else
		return (0);
}

inline	static	void	ft_putchar_unicode(t_data *d, int_fast32_t len, wchar_t charac)
{
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

inline	static	uint_fast32_t		ft_pwcslen(t_data *d, wchar_t *str)
{
	uint_fast32_t	char_len;
	uint_fast32_t	str_len;

	char_len = 0;
	str_len = 0;
	while (*str && (str_len < (uint_fast32_t)d->info.prec || d->info.prec < 0))
	{
		char_len = ft_size_wchar(*str);
		if (char_len + str_len <= (uint_fast32_t)d->info.prec || d->info.prec < 0)
			str_len += char_len;
		else
			break ;
		str++;
	}
	return (str_len);
}

inline	static	void		ft_put_width(t_data *d, uint_fast32_t len)
{
	register int_fast32_t	width;
	int_fast32_t			prec;
	char					c;
	
	width = d->info.width;
	prec = d->info.prec;
	c = ' ';
	if (d->info.zero && prec <= 0 && !d->info.minus)
		c = '0';
	if (prec < 0 || len < (uint_fast32_t)prec)
		width -= len;
	else if (len >= (uint_fast32_t)prec)
		width -= prec;
	while (width-- > 0)
	{
		if (BUFF_SIZE <= d->buff_i)
			ft_print_buff(d);
		d->buff[d->buff_i++] = c;
	}
}

void						ft_putstr_unicode(t_data *d, wchar_t *str)
{
	uint_fast32_t		char_len;
	uint_fast32_t		printed_len;
	uint_fast32_t		str_len;
	wchar_t				*begin;

	str_len = ft_pwcslen(d, str);
	if (d->info.minus == 0)
		ft_put_width(d, str_len);
	printed_len = 0;
	begin = str;
	if (BUFF_SIZE <= d->buff_i + str_len)
		ft_print_buff(d);
	while (*str && ((int)printed_len < d->info.prec || d->info.prec == -1))
	{
		char_len = ft_size_wchar(*str);
		if ((int)(printed_len += char_len) <= d->info.prec || d->info.prec == -1)
			ft_putchar_unicode(d, char_len, *str++);
	}
	if (d->info.minus == 1)
		ft_put_width(d, str_len);
}
