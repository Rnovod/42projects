/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vizualization.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 12:43:48 by mpopovyc          #+#    #+#             */
/*   Updated: 2018/07/22 12:43:49 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIZUALIZATION_H
# define VIZUALIZATION_H

# include "filler.h"
# include "SDL.h"
# include "SDL_ttf.h"

# define W_W 1000
# define W_H 1000

typedef struct		s_viz
{
	SDL_Window		*window;
	SDL_Surface		*surf;
	SDL_Surface		*text;
	SDL_Event		event;
	TTF_Font		*font;
	TTF_Font		*font_score;
	char			pl1;
	char			pl2;
	char			*p1;
	char			*p2;
	int				running;
	int				pause;
	int				width;
	int				height;
	int				w_w;
	int				score1;
	int				score2;
	int				x;
	int				y;
}					t_viz;

void				init_sdl(t_viz *v);
void				quit_sdl(t_viz *v);
void				events(t_viz *v);
void				draw_map(t_flr *p, t_viz *v);
void				draw_player(t_viz *v, char *line);
void				draw_score(t_viz *v);
void				final_score(t_viz *v);
void				init_strctr(t_viz *v);
void				draw_score(t_viz *v);

#endif
