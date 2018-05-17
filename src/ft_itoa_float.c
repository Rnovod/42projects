/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 17:34:26 by rnovodra          #+#    #+#             */
/*   Updated: 2018/05/17 17:34:28 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/ft_printf.h"

inline	static	size_t	ft_count_float(float nbr)
{
	size_t	len;

	len = 1;
	while (nbr /= 10)
		len++;
	return (len);
}

void					ft_itoa_float(t_data *d, float nbr, int sign)
{
	size_t	len;

	len = ft_count_float(nbr);
	printf("len==========%zu\n", len);
	(void)sign;
	(void)d;
}
