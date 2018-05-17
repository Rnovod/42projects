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

inline	static	void	ft_choose_size(t_data *d)
{
	if (d->info.z)
		d->info.size = 6;
	else if (d->info.j)
		d->info.size = 5;
	else if (d->info.l && !(d->info.l % 2))
		d->info.size = 4;
	else if (d->info.l && d->info.l % 2)
		d->info.size = 3;
	else if (d->info.h && (d->info.h % 2))
		d->info.size = 2;
	else if (d->info.h && !(d->info.h % 2))
		d->info.size = 1;
}

inline	static	void	ft_conv_anoth(t_data *d, const char *restrict form)
{
	if (form[d->form_i] == 'X')
		d->info.up_case = 1;
	else if (form[d->form_i] == 'p')
	{
		d->info.adr = 1;
		d->info.sharp = 1;
	}
	if (form[d->form_i] == 'o' || form[d->form_i] == 'O')
		ft_u(d, 8);
	else if (form[d->form_i] == 'x' || form[d->form_i] == 'X' ||
		form[d->form_i] == 'p')
		ft_u(d, 16);
	else if (form[d->form_i] == 'b')
		ft_u(d, 2);
	else if (form[d->form_i] == 'f' || form[d->form_i] == 'F')
		ft_f(d);
	else if (form[d->form_i] == 'n')
		ft_n(d);
	else
		ft_printf_putchar(d, (wchar_t)form[d->form_i]);
}

void					ft_conversion(t_data *d, const char *restrict form)
{
	if (d->info.size != 0)
		ft_choose_size(d);
	if (form[d->form_i] == 'D' || form[d->form_i] == 'U' ||
		form[d->form_i] == 'S' || form[d->form_i] == 'O' ||
		form[d->form_i] == 'p' || form[d->form_i] == 'C')
		d->info.size = 3;
	if (form[d->form_i] == 'd' || form[d->form_i] == 'i' ||
		form[d->form_i] == 'D')
		ft_d(d);
	else if (form[d->form_i] == 'c' || form[d->form_i] == 'C')
		ft_c(d);
	else if (form[d->form_i] == 'u' || form[d->form_i] == 'U')
		ft_u(d, 10);
	else if (form[d->form_i] == 's' || form[d->form_i] == 'S')
		ft_s(d);
	else
		ft_conv_anoth(d, form);
	++d->form_i;
}
