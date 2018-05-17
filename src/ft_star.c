/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_star.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 12:46:45 by rnovodra          #+#    #+#             */
/*   Updated: 2018/05/04 12:46:46 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/ft_printf.h"

int				ft_star(t_data *d, const char *restrict format)
{
	int		i;
	int		nbr;

	nbr = 0;
	i = ++d->form_i;
	while (format[i] >= '0' && format[i] <= '9')
		nbr = nbr * 10 + (format[i++] - '0');
	if (format[i] == '$')
	{
		d->form_i = ++i;
		if (nbr == 0)
			return (0);
		ft_get_arg(d, nbr);
		return (va_arg(d->param_arg, int));
	}
	else
		return (va_arg(d->argptr, int));
}
