/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_star.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 15:48:11 by rnovodra          #+#    #+#             */
/*   Updated: 2018/06/28 15:48:12 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/ft_printf.h"

int			ft_star(t_data *d, const char *f, va_list *arg)
{
	int				value;
	register int	i;

	value = 0;
	i = ++d->form_i;
	while (f[i] >= '0' && f[i] <= '9')
	{
		value = value * 10 + (f[i] - '0');
		i++;
	}
	if (f[i] == '$')
	{
		d->form_i = ++i;
		if (value == 0)
			return (0);
		return (va_arg(*ft_count_arg(d, value), int));
	}
	else
		value = va_arg(*arg, int);
	return (value);
}
