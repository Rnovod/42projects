/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 12:20:42 by rnovodra          #+#    #+#             */
/*   Updated: 2018/07/16 12:20:43 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/ft_printf.h"

int		ft_dprintf(const int fd, const char *restrict format, ...)
{
	va_list		arg;
	int			done;

	if (!format)
		return (-1);
	va_start(arg, format);
	done = ft_vdprintf(fd, format, &arg);
	va_end(arg);
	return (done);
}
