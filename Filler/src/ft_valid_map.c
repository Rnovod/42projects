/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 16:28:43 by rnovodra          #+#    #+#             */
/*   Updated: 2018/07/24 16:28:44 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		ft_valid_map(t_filler_data *d)
{
	char	**map;
	int		i;

	map = d->info[MAP].pat;
	i = 0;
	while ((((*map)[i] >= '0' && (*map)[i] <= '9') ||
		(*map)[i] == ' ') && (*map)[i])
		i++;
	if (!(*map)[i])
		ft_error(d, -6, NULL);
	while (*map != NULL)
	{
		if ((int)ft_strlen(*map) != i + d->info[MAP].w)
			ft_error(d, -6, NULL);
		map++;
	}
	d->start_map = i;
}
