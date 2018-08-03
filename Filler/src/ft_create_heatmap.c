/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_heatmap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 19:44:56 by rnovodra          #+#    #+#             */
/*   Updated: 2018/07/25 19:44:58 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			ft_eval_distance(t_filler_data *d, float **heatmap,
				int pos_y, int pos_x)
{
	int			x;
	int			y;
	float		dis;

	y = -1;
	while (++y < d->info[MAP].h)
	{
		x = -1;
		while (++x < d->info[MAP].w)
		{
			if (heatmap[y][x] == -2)
			{
				dis = ft_sqrtf(ft_powf(x - pos_x, 2) + ft_powf(y - pos_y, 2));
				if (dis < heatmap[pos_y][pos_x] || heatmap[pos_y][pos_x] == 0)
					heatmap[pos_y][pos_x] = dis;
			}
		}
	}
}

void			ft_creat_heatmap(t_filler_data *d)
{
	int		y;
	int		x;
	float	**heatmap;

	heatmap = d->heatmap;
	y = 0;
	while (y < d->info[MAP].h)
	{
		x = 0;
		while (x < d->info[MAP].w)
		{
			if (heatmap[y][x] != -1 && heatmap[y][x] != -2.0)
				ft_eval_distance(d, heatmap, y, x);
			++x;
		}
		++y;
	}
}

void			ft_malloc_heatmap(t_filler_data *d)
{
	int		y;
	int		x;

	if (!(d->heatmap = (float**)malloc(sizeof(float*) * d->info[MAP].h)))
		ft_error(d, -4, NULL);
	y = -1;
	while (++y < d->info[MAP].h)
	{
		if (!(d->heatmap[y] = (float*)malloc(sizeof(float) * d->info[MAP].w)))
		{
			ft_arrnfree(&d->heatmap, (size_t)y);
			ft_error(d, -4, NULL);
		}
		x = -1;
		while (++x < d->info[MAP].w)
		{
			if (d->info[MAP].pat[y][x + d->start_map] == d->player_symb)
				d->heatmap[y][x] = -1.0;
			else if (d->info[MAP].pat[y][x + d->start_map] == d->enemy_symb)
				d->heatmap[y][x] = -2.0;
			else
				d->heatmap[y][x] = 0.0;
		}
	}
}

void			ft_heatmap(t_filler_data *d)
{
	ft_malloc_heatmap(d);
	ft_creat_heatmap(d);
}
