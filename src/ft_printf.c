/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 17:26:02 by rnovodra          #+#    #+#             */
/*   Updated: 2018/04/28 17:26:03 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/ft_printf.h"

int			ft_printf(const char *restrict format, ...)
{
	t_data		d;

	d.buff_i = 0;
	d.form_i = 0;
	d.error = 0;
	d.ch = 0;
	va_start(d.argptr, format);
	va_copy(d.begin, d.argptr);
	while (format[d.form_i])
	{
		if (BUFF_SIZE <= d.buff_i)
			ft_print_buff(&d);
		if (format[d.form_i] == '%')
			ft_specification(&d, format);
		else
			d.buff[d.buff_i++] = format[d.form_i++];
		if (d.error == 1)
			return (-1);
	}
	if (d.buff_i != 0)
		ft_print_buff(&d);
	va_end(d.argptr);
	return (d.ch);
}
