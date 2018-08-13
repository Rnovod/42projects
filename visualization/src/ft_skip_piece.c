/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_piece.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 17:25:53 by rnovodra          #+#    #+#             */
/*   Updated: 2018/07/31 17:25:54 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visual.h"

static inline int	ft_read_piece_size(t_visual_data *d, char *line)
{
	t_bytes		*ptr;
	char		*cp;

	ptr = (t_bytes*)line;
	if (ptr->byte6 != 0x206563656950)
		return (-2);
	cp = line;
	if (ft_getnbr(&cp, &d->info[PIECE].h) < 0 ||
		ft_getnbr(&cp, &d->info[PIECE].w) < 0 ||
		ft_getnbr(&cp, NULL) != 0 ||
		d->info[PIECE].h <= 0 || d->info[PIECE].w <= 0)
		return (-2);
	return (0);
}

static inline int	ft_read_piece(t_visual_data *d)
{
	int		count;
	char	*line;

	line = NULL;
	count = 0;
	while (count < d->info[PIECE].h)
	{
		if (get_next_line(0, &line) < 0)
			ft_thread_error(d, -1);
		free(line);
		line = NULL;
		count++;
	}
	return (0);
}

void				ft_skip_piece(t_visual_data *d, char *line)
{
	if (ft_read_piece_size(d, line) < 0)
	{
		free(line);
		ft_thread_error(d, -3);
	}
	free(line);
	if (ft_read_piece(d) < 0)
		ft_thread_error(d, -1);
}
