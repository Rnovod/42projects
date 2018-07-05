/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldpow.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 12:18:32 by rnovodra          #+#    #+#             */
/*   Updated: 2018/07/05 12:18:33 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/ft_printf.h"

long double		ft_ldpow(long double val, size_t pow)
{
	long double		res;

	res = 1l;
	while (pow)
	{
		if (pow & 1)
			res *= val;
		val *= val;
		pow >>= 1;
	}
	return (res);
}
