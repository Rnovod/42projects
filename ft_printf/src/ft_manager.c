/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manager.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 18:16:55 by rnovodra          #+#    #+#             */
/*   Updated: 2018/05/02 18:16:56 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/ft_printf.h"

void			ft_manage_flags(t_data *d, const char *restrict format)
{
	while (format[d->form_i] && (format[d->form_i] == ' ' ||
		format[d->form_i] == '0' || format[d->form_i] == '-' ||
		format[d->form_i] == '#' || format[d->form_i] == '+'))
	{
		if (!d->info.space && !d->info.plus && format[d->form_i] == ' ')
			d->info.space = 1;
		else if (!d->info.zero && !d->info.minus && format[d->form_i] == '0')
			d->info.zero = 1;
		else if (!d->info.sharp && format[d->form_i] == '#')
			d->info.sharp = 1;
		else if (!d->info.minus && format[d->form_i] == '-')
			d->info.minus = 1;
		else if (!d->info.plus && format[d->form_i] == '+')
			d->info.plus = 1;
		else
			break ;
		++d->form_i;
	}
}

void			ft_manage_digits(t_data *d, const char *restrict format)
{
	int		digit;

	digit = 0;
	while (format[d->form_i] >= '0' && format[d->form_i] <= '9')
	{
		digit = digit * 10 + (format[d->form_i] - '0');
		++d->form_i;
	}
	if (format[d->form_i] == '$')
	{
		d->form_i++;
		d->data_arg = digit;
	}
	else
		d->info.width = digit;
}

void			ft_manage_precision(t_data *d, const char *restrict format)
{
	++d->form_i;
	d->info.precision = 0;
	if (format[d->form_i] == '*')
		d->info.precision = ft_star(d, format);
	else
		while (format[d->form_i] >= '0' && format[d->form_i] <= '9')
		{
			d->info.precision = d->info.precision * 10 + (format[d->form_i] - '0');
			++d->form_i;
		}
}

void			ft_manage_size(t_data *d, const char *restrict format)
{
	while (format[d->form_i] && (format[d->form_i] == 'h' ||
		format[d->form_i] == 'l' || format[d->form_i] == 'z' ||
		format[d->form_i] == 'j'))
	{
		if (d->info.size < 1 && format[d->form_i] == 'h' &&
			format[d->form_i + 1] == 'h')
			d->info.size = 1;
		else if (d->info.size < 2 && format[d->form_i] == 'h')
			d->info.size = 2;
		else if (d->info.size < 3 && format[d->form_i] == 'l')
			d->info.size = 3;
		else if (d->info.size < 4 && format[d->form_i] == 'l'
			&& format[d->form_i + 1] == 'l')
			d->info.size = 4;
		else if (d->info.size < 5 && format[d->form_i] == 'j')
			d->info.size = 5;
		else if (d->info.size < 6 && format[d->form_i] == 'z')
			d->info.size = 6;
		else
			break ;
		++d->form_i;
	}
}
