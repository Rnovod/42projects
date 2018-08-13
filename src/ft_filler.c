/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 18:03:48 by rnovodra          #+#    #+#             */
/*   Updated: 2018/07/19 18:03:49 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			ft_check_place(t_filler_data *d, t_coord *player,
			t_coord *star, t_coord *pos)
{
	t_coord	tmp;
	char	**map;

	map = d->info[MAP].pat;
	tmp.y = player->y + pos->y - star->y;
	tmp.x = player->x + pos->x - star->x;
	if (tmp.y < d->info[MAP].h && tmp.y >= 0 &&
		tmp.x - (tmp.y < 999 ? 3 + 1 :
		ft_count_digits(tmp.y) + 1) < d->info[MAP].w &&
		tmp.x - (tmp.y < 999 ? 3 + 1 : ft_count_digits(tmp.y) + 1) >= 0 &&
		map[tmp.y][tmp.x] != d->enemy_symb)
	{
		if (map[tmp.y][tmp.x] == d->player_symb)
			return (1);
	}
	else
		return (-1);
	return (0);
}

int			ft_place(t_filler_data *d, char **piece,
			t_coord *player, t_coord *star)
{
	int		touch;
	t_coord	pos;
	int		ret;

	touch = 0;
	pos.y = -1;
	while (piece[++pos.y])
	{
		pos.x = -1;
		while (piece[pos.y][++pos.x])
		{
			if (piece[pos.y][pos.x] == '*')
			{
				if ((ret = ft_check_place(d, player, star, &pos)) == -1)
					return (0);
				if ((touch += ret) > 1)
					return (0);
			}
		}
	}
	return (1);
}

int			ft_start_pos(char **pat, t_coord *who, char symb)
{
	int		x;
	int		y;

	y = who->y;
	x = who->x + 1;
	while (pat[y])
	{
		while (pat[y][x])
		{
			if (pat[y][x] == symb)
			{
				who->x = x;
				who->y = y;
				return (1);
			}
			++x;
		}
		x = 0;
		++y;
	}
	return (0);
}

void		ft_filler(t_filler_data *d, t_coord *answer)
{
	t_coord	player;
	t_coord	star;
	t_coord	pre_answ;

	player.x = -1;
	player.y = 0;
	while (ft_start_pos(d->info[MAP].pat, &player, d->player_symb))
	{
		star.y = 0;
		star.x = -1;
		while (ft_start_pos(d->info[PIECE].pat, &star, '*'))
		{
			if (ft_place(d, d->info[PIECE].pat, &player, &star))
			{
				pre_answ.y = player.y - star.y;
				pre_answ.x = player.x - star.x - (pre_answ.y < 999 ? 3 + 1 :
					ft_count_digits(pre_answ.y) + 1);
				if (ft_eval_answer(d, pre_answ))
				{
					answer->y = pre_answ.y;
					answer->x = pre_answ.x;
				}
			}
		}
	}
}
