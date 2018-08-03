/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 20:40:45 by mpopovyc          #+#    #+#             */
/*   Updated: 2018/07/19 20:40:46 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vizualization.h"

static int	choose_color(char s, t_viz *v)
{
	if (s == v->pl1)
	{
		v->score1 += 1;
		return (0x4d75b7);
	}
	else if (s == v->pl1 - 32)
		return (0x204f9b);
	else if (s == v->pl2)
	{
		v->score2 += 1;
		return (0x5e9e6a);
	}
	else if (s == v->pl2 - 32)
		return (0x0e4418);
	else
		return (0x161616);
}

static void	draw_line(t_viz *v, char *line)
{
	int		i;
	int		cent_w;
	int		cent_h;

	cent_w = W_W / 2 - (v->width * (v->w_w + 3)) / 2;
	cent_h = W_H / 2 - (v->height * (v->w_w + 3)) / 2;
	v->y += v->w_w + 3;
	v->x = 0;
	i = 0;
	while (line[i] != '\0')
	{
		SDL_FillRect(v->surf,
			&(SDL_Rect){v->x + cent_w, v->y + cent_h + 50, v->w_w, v->w_w},
			choose_color(line[i], v));
		v->x += v->w_w + 3;
		i++;
	}
}

static void	def_size(t_viz *v, char *line)
{
	int		k;

	v->height = ft_atoi(line + 8);
	k = ft_dig_count(v->height);
	v->width = ft_atoi(line + 8 + k);
	if (v->height <= 15)
		v->w_w = 40;
	else if (v->height <= 24)
		v->w_w = 20;
	else if (v->height <= 100)
		v->w_w = 5;
	else if (v->height > 100)
		v->w_w = 4;
}

void		draw_map(t_flr *p, t_viz *v)
{
	int		tmp1;
	int		tmp2;

	tmp1 = v->score1;
	tmp2 = v->score2;
	v->y = 0;
	if (v->height == 0)
		def_size(v, p->line);
	ft_strdel(&p->line);
	get_next_line(0, &p->line);
	ft_strdel(&p->line);
	while (get_next_line(0, &p->line) > 0)
	{
		if (!(ft_strstr(p->line, "Piece")))
			draw_line(v, p->line + 4);
		else
		{
			draw_score(v);
			tmp1 < v->score1 ? v->score1 -= 1 : 0;
			tmp2 < v->score2 ? v->score2 -= 1 : 0;
			break ;
		}
		ft_strdel(&p->line);
	}
}
