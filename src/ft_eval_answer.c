/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_answer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 17:34:02 by rnovodra          #+#    #+#             */
/*   Updated: 2018/07/25 17:34:03 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

float			ft_eval_distance(t_filler_data *d, int pos_y, int pos_x)
{
	int			x;
	int			y;
	float		dis;
	float		ret;

	y = -1;
	ret = 0.0;
	while (d->info[MAP].pat[++y])
	{
		x = -1;
		while (d->info[MAP].pat[y][x + 4])
		{
			if (d->info[MAP].pat[y][++x + 4] == d->enemy_symb)
			{
				dis = ft_sqrtf(ft_powf(x - pos_x, 2) + ft_powf(y - pos_y, 2));
				if (dis < ret || ret == 0.0)
					ret = dis;
			}
		}
	}
	return (ret);
}

float			ft_eval_grade(t_filler_data *d, char **piece, t_coord pre_answ)
{
	int		y;
	int		x;
	float	grade;

	y = 0;
	grade = 0.0;
	while (piece[y])
	{
		x = 0;
		while (piece[y][x])
		{
			if (piece[y][x] == '*' && d->info[MAP].pat[pre_answ.y + y]
				[pre_answ.x + x + (pre_answ.y + y < 999 ? 3 + 1 :
				ft_count_digits(pre_answ.y + y) + 1)] != d->player_symb)
				grade += ft_eval_distance(d, pre_answ.y + y, pre_answ.x + x);
			++x;
		}
		++y;
	}
	return (grade);
}

int				ft_eval_answer(t_filler_data *d, t_coord pre_answ)
{
	float	grade;

	grade = ft_eval_grade(d, d->info[PIECE].pat, pre_answ);
	if (grade < d->best_grade || d->best_grade == -1.0)
	{
		d->best_grade = grade;
		return (1);
	}
	return (0);
}
