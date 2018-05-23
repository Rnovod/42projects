/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 18:19:12 by rnovodra          #+#    #+#             */
/*   Updated: 2018/05/07 18:19:13 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/ft_printf.h"

void			ft_get_arg(t_data *d, int_fast32_t arg)
{
	int_fast32_t			i;

	va_copy(d->param_arg, d->begin);
	i = 0;
	while (++i < arg)
		va_arg(d->param_arg, int_fast32_t);
}
