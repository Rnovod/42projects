/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 18:05:52 by rnovodra          #+#    #+#             */
/*   Updated: 2018/05/03 18:05:55 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/ft_printf.h"

int				ft_is_size(t_data *d, const char *restrict format)
{
	if (format[d->form_i] == 'h' || format[d->form_i] == 'l' ||
		format[d->form_i] == 'z' || format[d->form_i] == 'j')
		return (1);
	return (0);
}
