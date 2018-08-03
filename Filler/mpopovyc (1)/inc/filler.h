/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 15:57:07 by mpopovyc          #+#    #+#             */
/*   Updated: 2018/07/02 15:57:09 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"

typedef struct		s_coord
{
	int				w_m;
	int				h_m;
	int				w_p;
	int				h_p;
	int				mi;
	int				mj;
	int				pi;
	int				pj;
	int				px;
	int				py;
	int				y;
	int				sum;
	int				x;
}					t_coord;

typedef struct		s_flr
{
	char			p;
	char			e;
	char			*line;
	char			**map;
	char			**piece;
	int				fd;
}					t_flr;

void				init_str(t_coord *cr);
void				fill_map(t_flr *p, t_coord *crd);
void				fill_piece(t_flr *p, t_coord *crd);
void				read_data(t_flr *p);
int					get_coord(t_flr *p, t_coord *cr);

#endif
