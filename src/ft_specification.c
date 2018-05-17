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

inline static	void ft_manage_flags(t_data *d, const char *restrict format)
{
	register unsigned int	i;

	i = d->form_i;
	while (format[i] && (format[i] == ' ' ||
		format[i] == '0' || format[i] == '-' ||
		format[i] == '#' || format[i] == '+'))
	{
		if (!d->info.space && !d->info.plus && format[i] == ' ')
			d->info.space = 1;
		else if (!d->info.zero && !d->info.minus && format[i] == '0')
			d->info.zero = 1;
		else if (!d->info.sharp && format[i] == '#')
			d->info.sharp = 1;
		else if (!d->info.minus && format[i] == '-')
			d->info.minus = 1;
		else if (!d->info.plus && format[i] == '+')
			d->info.plus = 1;
		++i;
	}
	d->form_i = i;
}

inline static	void ft_manage_digits(t_data *d, const char *restrict format)
{
	int						digit;
	register unsigned int	i;

	i = d->form_i;
	digit = 0;
	while (format[i] >= '0' && format[i] <= '9')
	{
		digit = digit * 10 + (format[i] - '0');
		++i;
	}
	if (format[i] == '$')
	{
		i++;
		d->data_arg = digit;
	}
	else
		d->info.width = digit;
	d->form_i = i;
}

inline static	void ft_manage_precision(t_data *d, const char *restrict format)
{
	register unsigned int	i;
	int						prec;

	i = ++d->form_i;
	prec = 0;
	if (format[i] == '*')
	{
		prec = ft_star(d, format);
		++i;
	}
	else
		while (format[i] >= '0' && format[i] <= '9')
		{
			prec = prec * 10 + (format[i] - '0');
			++i;
		}
	d->form_i = i;
	if (prec < 0)
		prec = -1;
	d->info.prec = prec;
}

inline static	void ft_manage_size(t_data *d, const char *restrict format)
{
	if (!d->info.z && !d->info.j && format[d->form_i] == 'h')
		d->info.h++;
	else if (!d->info.z && !d->info.j && format[d->form_i] == 'l')
		d->info.l++;
	else if (!d->info.z && format[d->form_i] == 'j')
		d->info.j = 1;
	else if (format[d->form_i] == 'z')
		d->info.z = 1;
	if (d->info.size == 0)
		d->info.size = 7;
	++d->form_i;
}

void			ft_specification(t_data *d, const char *restrict format)
{
	ft_set_flags_null(d);
	++d->form_i;
	while (format[d->form_i])
	{
		if (format[d->form_i] == ' ' || format[d->form_i] == '0' ||
			format[d->form_i] == '-' || format[d->form_i] == '#' ||
			format[d->form_i] == '+')
			ft_manage_flags(d, format);
		else if (format[d->form_i] >= '1' && format[d->form_i] <= '9')
			ft_manage_digits(d, format);
		else if (format[d->form_i] == '.')
			ft_manage_precision(d, format);
		else if (format[d->form_i] == 'h' || format[d->form_i] == 'l' ||
			format[d->form_i] == 'z' || format[d->form_i] == 'j')
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
