/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_player_nbr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 15:27:37 by rnovodra          #+#    #+#             */
/*   Updated: 2018/07/19 15:27:39 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		ft_get_player_nbr(t_filler_data *d)
{
	char		*line;
	t_bytes		*b;
	int			ret;

	line = NULL;
	if ((ret = get_next_line(0, &line)) <= 0)
		ft_error(d, -1, line);
	b = (t_bytes*)line;
	if (b->byte8 != 0x6365786520242424)
		ft_error(d, -2, line);
	++b;
	if (b->byte3 != 0x327020 && b->byte3 != 0x317020)
		ft_error(d, -2, line);
	if (line[10] == '1')
	{
		d->player_symb = 'O';
		d->enemy_symb = 'X';
	}
	else
	{
		d->player_symb = 'X';
		d->enemy_symb = 'O';
	}
	free(line);
}
