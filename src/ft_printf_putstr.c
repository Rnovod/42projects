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

inline static	int_fast32_t		ft_strlen(char *str)
{
	unsigned char	*cp;
	
	cp = (unsigned char*)str;
	while (*cp++)
		;
	return (cp - (unsigned char*)str - 1);
}


inline	static	void		ft_put_width(t_data *d, int_fast32_t len)
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
	if (prec < 0 || len < prec)
		width -= len;
	else if (len > prec)
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
	char			*begin;
	int_fast32_t	len;

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
	while (*str && (str - begin < d->info.prec || d->info.prec == -1))
	{
		if (BUFF_SIZE <= d->buff_i)
			ft_print_buff(d);
		d->buff[d->buff_i++] = *str++;
	}
	if (d->info.minus == 1 || d->info.width < 0)
		ft_put_width(d, len);
}
