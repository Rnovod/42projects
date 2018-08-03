/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 16:31:16 by mpopovyc          #+#    #+#             */
/*   Updated: 2018/07/05 16:31:17 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static	void	element_creation(t_flr *p, t_coord *cr, int def)
{
	int			k;

	if (def == 0)
	{
		cr->h_m = ft_atoi(p->line + 8);
		k = ft_dig_count(cr->h_m);
		cr->w_m = ft_atoi(p->line + 8 + k);
		p->map = (char**)malloc(sizeof(char*) * (cr->h_m));
		k = -1;
		while (k++ < cr->h_m)
			p->map[k] = (char*)malloc(sizeof(char) * cr->w_m);
	}
	if (def == 1)
	{
		cr->h_p = ft_atoi(p->line + 6);
		k = ft_dig_count(cr->h_p);
		cr->w_p = ft_atoi(p->line + 7 + k);
		p->piece = (char **)malloc(sizeof(char*) * (cr->h_p));
	}
}

void			fill_map(t_flr *p, t_coord *cr)
{
	char		*line;
	int			m_height;

	cr->mi = 0;
	m_height = 0;
	if (p->map == NULL)
		element_creation(p, cr, 0);
	ft_strdel(&p->line);
	m_height += cr->h_m + 1;
	while (m_height > 0 && get_next_line(0, &line) > 0)
	{
		if (cr->mi < cr->h_m && m_height <= cr->h_m)
		{
			p->map[cr->mi] = ft_strcpy(p->map[cr->mi], line + 4);
			cr->mi++;
		}
		m_height--;
		ft_strdel(&line);
	}
}

void			fill_piece(t_flr *p, t_coord *cr)
{
	char		*line;

	cr->pi = 0;
	if (p->piece != NULL)
		ft_free_mass(p->piece, cr->h_p - 1);
	get_next_line(0, &p->line);
	element_creation(p, cr, 1);
	ft_strdel(&p->line);
	while (cr->pi < cr->h_p && get_next_line(0, &line) > 0)
	{
		p->piece[cr->pi] = ft_strdup(line);
		cr->pi++;
		ft_strdel(&line);
	}
}

void			read_data(t_flr *p)
{
	if (get_next_line(0, &p->line) > 0)
	{
		if (ft_atoi(&p->line[10]) == 1)
		{
			p->p = 'o';
			p->e = 'x';
		}
		else
		{
			p->p = 'x';
			p->e = 'o';
		}
		ft_strdel(&p->line);
	}
}
