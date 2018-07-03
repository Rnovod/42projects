/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 15:52:10 by rnovodra          #+#    #+#             */
/*   Updated: 2018/06/28 15:52:13 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/ft_printf.h"

va_list			*ft_count_arg(t_data *d, int arg)
{
	va_list		param_arg;
	va_list		*ret;

	va_copy(param_arg, d->begin);
	while (--arg)
		va_arg(param_arg, long int);
	ret = &param_arg;
	return (ret);
}
