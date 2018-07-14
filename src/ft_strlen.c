/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 14:35:50 by rnovodra          #+#    #+#             */
/*   Updated: 2018/07/11 14:35:51 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/ft_printf.h"

static	inline	int	ft_calc_len(char *cp, char *str)
{
	if (cp[0] == 0)
		return (cp - str);
	if (cp[1] == 0)
		return (cp - str + 1);
	if (cp[2] == 0)
		return (cp - str + 2);
	if (cp[3] == 0)
		return (cp - str + 3);
	if (cp[4] == 0)
		return (cp - str + 4);
	if (cp[5] == 0)
		return (cp - str + 5);
	if (cp[6] == 0)
		return (cp - str + 6);
	else
		return (cp - str + 7);
}

int					ft_strlen(char *str)
{
	char		*cp;
	uintmax_t	*longword_ptr;
	uintmax_t	longword;

	longword_ptr = (uintmax_t *)str;
	if (!str)
		return (0);
	while (1)
	{
		longword = *longword_ptr++;
		if (((longword - 0x101010101010101L)
			& ~longword & 0x8080808080808080L) != 0)
		{
			cp = (char *)(longword_ptr - 1);
			return (ft_calc_len(cp, str));
		}
	}
}
