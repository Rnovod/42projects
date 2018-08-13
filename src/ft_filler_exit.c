/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 13:53:13 by rnovodra          #+#    #+#             */
/*   Updated: 2018/08/01 13:53:14 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		ft_free_data(t_filler_data *d)
{
	if (d->info[MAP].pat)
		ft_arrfree(&d->info[MAP].pat);
	if (d->info[PIECE].pat)
		ft_arrfree(&d->info[PIECE].pat);
}

void		ft_filler_exit(t_filler_data *d, int status)
{
	ft_free_data(d);
	exit(status);
}
