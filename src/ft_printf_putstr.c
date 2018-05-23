/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 12:45:02 by rnovodra          #+#    #+#             */
/*   Updated: 2018/05/11 12:45:03 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/ft_printf.h"

inline static	uint_fast32_t		ft_strlen(const char *str)
{
	char				*cp;
	
	cp = (char*)str;
	while (*cp++)
		;
	return (cp - str - 1);
}


inline	static	void		ft_put_width(t_data *d, uint_fast32_t len)
{
	register int_fast32_t	width;
	int_fast32_t			prec;
	char					c;

	width = d->info.width;
	prec = d->info.prec;
	c = ' ';
	if (d->info.zero && prec <= 0 && width > 0 && !d->info.minus)
		c = '0';
	if (width < 0)
		width = width * -1;
	if (prec < 0 || len < (uint_fast32_t)prec)
		width -= len;
	else if (len > (uint_fast32_t)prec)
		width -= prec;
	if (BUFF_SIZE <= d->buff_i + width)
		ft_print_buff(d);
	while (width-- > 0)
		d->buff[d->buff_i++] = c;
}

void						ft_printf_putstr(t_data *d, char *str)
{
	char			*begin;
	uint_fast32_t	len;

	if (!str)
	{
		str = "(null)";
		len = 6;
	}
	else
		len = ft_strlen(str);
	begin = str;
	if (d->info.minus == 0 && d->info.width > 0)
		ft_put_width(d, len);
	if (BUFF_SIZE <= d->buff_i + len)
		ft_print_buff(d);
	while (*str && (str - begin < d->info.prec || d->info.prec == -1))
		d->buff[d->buff_i++] = *str++;
	if (d->info.minus == 1 || d->info.width < 0)
		ft_put_width(d, len);
}
