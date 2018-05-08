/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 18:24:27 by rnovodra          #+#    #+#             */
/*   Updated: 2018/05/03 18:24:28 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/ft_printf.h"

void			ft_conversion(t_data *d, const char *restrict format)
{
	if (format[d->form_i] == 'd' || format[d->form_i] == 'i')
		ft_d(d);
	// if (format[d->form_i] == 'c')
	// 	ft_c(d);
	++d->form_i;
}
