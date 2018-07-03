/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 12:15:38 by rnovodra          #+#    #+#             */
/*   Updated: 2018/06/28 12:15:39 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/ft_printf.h"

int			ft_printf(const char *restrict format, ...)
{
	t_data		d;
	va_list		arg;

	if (!format)
		return (-1);
	d.buff_i = 0;
	d.form_i = 0;
	d.ret = 0;
	d.error = 0;
	va_start(arg, format);
	va_copy(d.begin, arg);
	while (format[d.form_i])
	{
		if (format[d.form_i] == '%')
			ft_spec(&d, format, &arg);
		else
			FT_PRINTF_BUFF_SIZE == d.buff_i ? ft_print_buff(&d) :
			(d.buff[d.buff_i++] = format[d.form_i++]);
		if (d.error == 1)
			return (-1);
	}
	if (d.buff_i != 0)
		ft_print_buff(&d);
	return (d.ret);
}
