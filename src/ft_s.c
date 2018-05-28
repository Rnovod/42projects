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
	va_list		*tmp;

	if (d->data_arg != 0)
	{
		ft_get_arg(d, d->data_arg);
		tmp = &d->param_arg;
	}
	else
		tmp = &d->argptr;
	if (d->info.size == 3)
		d->pa_arg.pa_wstr = va_arg(*tmp, wchar_t*);
	else
		d->pa_arg.pa_str = (char*)va_arg(*tmp, char*);
	if (d->pa_arg.pa_wstr == NULL && d->info.size == 3)
		ft_printf_putstr(d, NULL);
	else if (d->info.size == 3)
		ft_putstr_unicode(d, d->pa_arg.pa_wstr);
	else
		ft_printf_putstr(d, d->pa_arg.pa_str);
}
