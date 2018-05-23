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


inline	static	void		ft_put_width(t_data *d, char *str)
{
	register int_fast32_t	width;
	int_fast32_t			prec;
	char					c;
	uint_fast32_t					len;

	len = ft_strlen(str);
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
	while (width-- > 0)
	{
		if (BUFF_SIZE <= d->buff_i)
			ft_print_buff(d);
		d->buff[d->buff_i++] = c;
	}
}

void						ft_printf_putstr(t_data *d, char *str)
{
	char		*begin;

	if (!str)
		str = "(null)";
	begin = str;
	if (d->info.minus == 0 && d->info.width > 0)
		ft_put_width(d, begin);
	while (*str && (str - begin < d->info.prec || d->info.prec == -1))
	{
		if (BUFF_SIZE <= d->buff_i)
			ft_print_buff(d);
		d->buff[d->buff_i++] = *str++;
	}
	if (d->info.minus == 1 || d->info.width < 0)
		ft_put_width(d, begin);
}
