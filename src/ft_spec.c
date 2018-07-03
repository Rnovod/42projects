/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 14:20:32 by rnovodra          #+#    #+#             */
/*   Updated: 2018/06/28 14:20:33 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/ft_printf.h"

inline	static	void	ft_mng_flags(t_data *d, const char *f)
{
	while (f[d->form_i] && (f[d->form_i] == ' ' ||
		f[d->form_i] == '0' || f[d->form_i] == '-' ||
		f[d->form_i] == '#' || f[d->form_i] == '+' ||
		f[d->form_i] == 'L' || f[d->form_i] == '\''))
	{
		if (!d->fl.space && !d->fl.plus && f[d->form_i] == ' ')
			d->fl.space = 1;
		else if (!d->fl.zero && !d->fl.minus && f[d->form_i] == '0')
			d->fl.zero = 1;
		else if (!d->fl.sharp && f[d->form_i] == '#')
			d->fl.sharp = 1;
		else if (!d->fl.minus && f[d->form_i] == '-')
			d->fl.minus = 1;
		else if (!d->fl.plus && f[d->form_i] == '+')
			d->fl.plus = 1;
		else if (!d->fl.apostr && f[d->form_i] == '\'')
			d->fl.apostr = 1;
		else if (!d->fl.long_db && f[d->form_i] == 'L')
			d->fl.long_db = 1;
		d->form_i++;
	}
}

inline	static	void	ft_mng_dig(t_data *d, const char *f)
{
	int		digit;

	digit = 0;
	while (f[d->form_i] >= '0' && f[d->form_i] <= '9')
	{
		digit = digit * 10 + (f[d->form_i] - '0');
		d->form_i++;
	}
	if (f[d->form_i] == '$')
	{
		d->form_i++;
		d->data_arg = digit;
	}
	else
		d->width = digit;
}

inline	static	void	ft_mng_prec(t_data *d, const char *f, va_list *arg)
{
	int		prec;

	prec = 0;
	d->form_i++;
	if (f[d->form_i] == '*')
		prec = ft_star(d, f, arg);
	else
		while (f[d->form_i] >= '0' && f[d->form_i] <= '9')
		{
			prec = prec * 10 + (f[d->form_i] - '0');
			d->form_i++;
		}
	if (prec < 0)
		prec = -1;
	d->prec = prec;
}

inline	static	void	ft_mng_size(t_data *d, const char *f)
{
	while (f[d->form_i] && (f[d->form_i] == 'h' || f[d->form_i] == 'l' ||
		f[d->form_i] == 'j' || f[d->form_i] == 'z'))
	{
		if (d->fl.size == 2 && f[d->form_i] == 'h')
			d->fl.size = 1;
		else if (d->fl.size < 2 && f[d->form_i] == 'h')
			d->fl.size = 2;
		else if (d->fl.size < 4 && d->fl.size == 3 && f[d->form_i] == 'l')
			d->fl.size = 4;
		else if (d->fl.size < 5 && f[d->form_i] == 'l')
			d->fl.size = 3;
		else if (d->fl.size < 5 && f[d->form_i] == 'j')
			d->fl.size = 5;
		else if (d->fl.size < 6 && f[d->form_i] == 'z')
			d->fl.size = 6;
		d->form_i++;
	}
}

void					ft_spec(t_data *d, const char *f, va_list *arg)
{
	d->form_i++;
	ft_set_flags(d);
	while (f[d->form_i])
	{
		if (f[d->form_i] == ' ' || f[d->form_i] == '0' || f[d->form_i] == '-' ||
			f[d->form_i] == '#' || f[d->form_i] == '+' || f[d->form_i] == '\'' ||
			f[d->form_i] == 'L')
			ft_mng_flags(d, f);
		else if (f[d->form_i] >= '1' && f[d->form_i] <= '9')
			ft_mng_dig(d, f);
		else if (f[d->form_i] == '.')
			ft_mng_prec(d, f, arg);
		else if (f[d->form_i] == 'h' || f[d->form_i] == 'l' ||
			f[d->form_i] == 'z' || f[d->form_i] == 'j')
			ft_mng_size(d, f);
		else if (f[d->form_i] == '*')
			d->width = ft_star(d, f, arg);
		else
		{
			ft_conv(d, f[d->form_i++], arg);
			break ;
		}
	}
}
