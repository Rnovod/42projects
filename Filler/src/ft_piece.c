/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_piece.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 18:03:43 by rnovodra          #+#    #+#             */
/*   Updated: 2018/07/19 18:03:44 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		ft_get_piece_size(t_filler_data *d)
{
	char		*line;
	t_bytes		*ptr;
	char		*cp;

	line = NULL;
	if (get_next_line(0, &line) < 0)
		ft_error(d, -1, line);
	ptr = (t_bytes*)line;
	if (ptr->byte6 != 0x206563656950)
		ft_error(d, -5, line);
	cp = line;
	if (ft_getnbr(&cp, &d->info[PIECE].h) < 0)
		ft_error(d, -5, line);
	if (ft_getnbr(&cp, &d->info[PIECE].w) < 0)
		ft_error(d, -5, line);
	if (ft_getnbr(&cp, NULL) != 0)
		ft_error(d, -5, line);
	free(line);
}

void		ft_get_piece(t_filler_data *d)
{
	int		count;
	char	*line;
	int		ret;

	line = NULL;
	count = 0;
	if (!(d->info[PIECE].pat = ft_arrnew(d->info[PIECE].h)))
		ft_error(d, -4, line);
	while (count < d->info[PIECE].h)
	{
		if ((ret = get_next_line(0, &line)) < 0)
			ft_error(d, -1, line);
		d->info[PIECE].pat[count++] = line;
	}
}
