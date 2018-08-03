/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pbits_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 15:04:25 by rnovodra          #+#    #+#             */
/*   Updated: 2018/03/14 15:04:26 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_pbits_char(unsigned char octet)
{
	size_t	bits;
	int		i;
	char	c;

	bits = sizeof(octet) * 8;
	i = bits - 1;
	while (i >= 0)
	{
		c = (octet & (1 << i)) ? '1' : '0';
		ft_putchar(c);
		if (i % 4 == 0 && i)
			ft_putchar(' ');
		--i;
	}
}
