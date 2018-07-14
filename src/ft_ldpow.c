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

long double		ft_ldpow(long double val, int pow)
{
	long double		res;

	res = 1l;
	if (pow < 0)
		return (0);
	while (pow > 0)
	{
		if (pow & 1)
			res *= val;
		val *= val;
		pow >>= 1;
	}
	return (res);
}
