/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 18:03:36 by rnovodra          #+#    #+#             */
/*   Updated: 2018/07/19 18:03:37 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		ft_get_map_size(t_filler_data *d)
{
	char		*line;
	uintmax_t	*ptr;
	char		*cp;
	int			ret;

	line = NULL;
	if ((ret = get_next_line(0, &line)) < 0)
		ft_error(d, -1, line);
	if (ret == 0)
		ft_filler_exit(d, 0);
	ptr = (uintmax_t*)line;
	if (*ptr != 0x2075616574616c50)
		ft_error(d, -3, line);
	cp = line;
	if (ft_getnbr(&cp, &d->info[MAP].h) < 0)
		ft_error(d, -3, line);
	if (ft_getnbr(&cp, &d->info[MAP].w) < 0)
		ft_error(d, -3, line);
	if (ft_getnbr(&cp, NULL) != 0)
		ft_error(d, -3, line);
	if (d->info[MAP].h <= 0 || d->info[MAP].w <= 0)
		ft_error(d, -6, line);
	free(line);
}

int			ft_first_line(t_filler_data *d, char *line)
{
	int		len;

	len = 0;
	while (((line[len] >= '0' && line[len] <= '9') ||
		line[len] == ' ') && line[len])
		len++;
	if (!line[len])
		ft_error(d, -6, NULL);
	d->start_map = len;
	return (len);
}

void		ft_get_map(t_filler_data *d)
{
	int		y;
	char	*line;
	int		len;

	line = NULL;
	if (!(d->info[MAP].pat = ft_arrnew(d->info[MAP].h)))
		ft_error(d, -4, line);
	if (get_next_line(0, &line) < 0)
		ft_error(d, -1, line);
	free(line);
	if (get_next_line(0, &line) < 0)
		ft_error(d, -1, line);
	y = 0;
	len = ft_first_line(d, line);
	d->info[MAP].pat[y++] = line;
	while (y < d->info[MAP].h)
	{
		if (get_next_line(0, &line) < 0)
			ft_error(d, -1, line);
		if ((int)ft_strlen(line) != len + d->info[MAP].w)
			ft_error(d, -6, line);
		d->info[MAP].pat[y++] = line;
	}
}
