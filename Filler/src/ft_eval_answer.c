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

float			ft_eval_grade(t_filler_data *d, char **piece, t_coord pre_answ)
{
	int		y;
	int		x;
	float	grade;

	y = 0;
	grade = 0;
	while (piece[y])
	{
		x = 0;
		while (piece[y][x])
		{
			if (piece[y][x] == '*')
			{
				if (d->heatmap[pre_answ.y + y][pre_answ.x + x] > 0.0)
					grade += d->heatmap[pre_answ.y + y][pre_answ.x + x];
			}
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
