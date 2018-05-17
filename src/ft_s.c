/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 12:36:35 by rnovodra          #+#    #+#             */
/*   Updated: 2018/05/11 12:36:38 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/ft_printf.h"

void			ft_s(t_data *d)
{
	if (d->data_arg != 0)
	{
		ft_get_arg(d, d->data_arg);
		if (d->info.size == 3)
			d->pa_arg.pa_wstr = va_arg(d->param_arg, wchar_t*);
		else
			d->pa_arg.pa_str = (char*)va_arg(d->param_arg, char*);
	}
	else if (d->info.size == 3)
		d->pa_arg.pa_wstr = va_arg(d->argptr, wchar_t*);
	else
		d->pa_arg.pa_str = (char*)va_arg(d->argptr, char*);
	if (d->pa_arg.pa_wstr == NULL && d->info.size == 3)
		ft_printf_putstr(d, NULL);
	else if (d->info.size == 3)
		ft_putstr_unicode(d, d->pa_arg.pa_wstr);
	else
		ft_printf_putstr(d, d->pa_arg.pa_str);
}
