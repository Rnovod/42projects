/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_place.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 09:36:44 by mpopovyc          #+#    #+#             */
/*   Updated: 2018/07/15 09:36:45 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	check_place(t_flr *p, t_coord *cr)
{
	int		c;

	c = 0;
	cr->pi = -1;
	while (++cr->pi < cr->h_p)
	{
		cr->pj = -1;
		while (++cr->pj < cr->w_p)
		{
			if (p->piece[cr->pi][cr->pj] == '*')
			{
				if (p->map[cr->mi + cr->pi][cr->mj + cr->pj] == p->e ||
					p->map[cr->mi + cr->pi][cr->mj + cr->pj] == (p->e - 32))
					return (0);
				else if (p->map[cr->mi + cr->pi][cr->mj + cr->pj] == p->p ||
					p->map[cr->mi + cr->pi][cr->mj + cr->pj] == (p->p - 32))
					c++;
			}
		}
	}
	return (c == 1) ? 1 : 0;
}

static int	check_stars(t_flr *p, t_coord *cr)
{
	cr->pi = -1;
	while (++cr->pi < cr->h_p)
	{
		cr->pj = -1;
		while (++cr->pj < cr->w_p)
		{
			if (p->piece[cr->pi][cr->pj] == '*')
			{
				if (cr->mi + cr->pi < 0 || cr->mi + cr->pi >= cr->h_m ||
					cr->mj + cr->pj < 0 || cr->mj + cr->pj >= cr->w_m)
					return (0);
			}
		}
	}
	return (1);
}

int			calculate_sum(t_flr *p, t_coord *cr)
{
	int		s;
	int		tmp_s;
	int		i;
	int		j;

	s = 0;
	tmp_s = 0;
	i = -1;
	while (++i < cr->h_m)
	{
		j = -1;
		while (++j < cr->w_m)
		{
			if (p->map[i][j] == p->e || p->map[i][j] == p->e - 32)
			{
				tmp_s = (ft_abs(cr->px - j) + ft_abs(cr->py - i));
				s == 0 ? s = tmp_s : 0;
				tmp_s < s ? s = tmp_s : 0;
			}
		}
	}
	return (s);
}

int			best_position(t_flr *p, t_coord *cr)
{
	int		s;

	s = 0;
	cr->pi = -1;
	while (++cr->pi < cr->h_p)
	{
		cr->pj = -1;
		while (++cr->pj < cr->w_p)
		{
			if (p->piece[cr->pi][cr->pj] == '*')
			{
				cr->px += cr->pj;
				cr->py += cr->pi;
				s = calculate_sum(p, cr);
				if (s <= cr->sum || cr->sum == 0)
				{
					cr->sum = s;
					return (1);
				}
				else
					return (0);
			}
		}
	}
	return (0);
}

int			get_coord(t_flr *p, t_coord *cr)
{
	cr->mi = -(cr->h_p) - 1;
	while (++cr->mi < cr->h_m)
	{
		cr->mj = -(cr->w_p) - 1;
		while (++cr->mj < cr->w_m)
		{
			if (check_stars(p, cr))
			{
				if (check_place(p, cr))
				{
					cr->px = cr->mj;
					cr->py = cr->mi;
					if (best_position(p, cr))
					{
						cr->x = cr->mj;
						cr->y = cr->mi;
					}
				}
			}
		}
	}
	return (1);
}
