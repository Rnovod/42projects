/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specification.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 13:39:27 by rnovodra          #+#    #+#             */
/*   Updated: 2018/05/02 13:39:28 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/ft_printf.h"

void			ft_specification(t_data *d, const char *restrict format)
{
	++d->form_i;
	ft_set_flags_null(d);
	while (format[d->form_i])
	{
		if (format[d->form_i] == ' ' || format[d->form_i] == '0' ||
			format[d->form_i] == '-' || format[d->form_i] == '#' || format[d->form_i] == '+')
			ft_manage_flags(d, format);
		else if (format[d->form_i] >= '1' && format[d->form_i] <= '9')
			ft_manage_digits(d, format);
		else if (format[d->form_i] == '.')
			ft_manage_precision(d, format);
		else if (ft_is_size(d, format))
			ft_manage_size(d, format);
		else if (format[d->form_i] == '*')
			d->info.width = ft_star(d, format);
		else
		{
			ft_conversion(d, format);
			break ;
		}
	}
}
