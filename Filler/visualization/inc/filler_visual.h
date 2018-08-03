/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_visual.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 16:02:44 by rnovodra          #+#    #+#             */
/*   Updated: 2018/07/30 16:02:45 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_VISUAL_H
# define FILLER_VISUAL_H

# include <SDL2/SDL.h>
# include <SDL2/SDL_mixer.h>
# include <SDL2/SDL_ttf.h>
# include "ft_printf.h"
# include "libft.h"
# include <errno.h>
# include <pthread.h>

typedef	struct		s_info_win
{
	SDL_Window		*ptr;
	SDL_Surface		*screen;
	int				w;
	int				h;
}					t_info_win;

typedef	struct		s_vis_map
{
	int					number;
	char				**map;
	struct	s_vis_map	*next;
	struct	s_vis_map	*prev;
}					t_vis_map;

typedef	struct		s_visual_flags
{
	unsigned int		stop_event:1;
	unsigned int		pause:1;
	unsigned int		thread_error:1;
}					t_visual_flags;

typedef	struct		s_visual_size
{
	int				w;
	int				h;
}					t_visual_size;

typedef	struct		s_game_info
{
	int				score_x;
	int				score_o;
	char			*player_1;
	char			*player_2;
}					t_game_info;

typedef	struct		s_visual_data
{
	t_info_win		window;
	SDL_Surface		*pixels;
	SDL_Event		event;
	Mix_Music		*music;
	t_visual_flags	fl;
	t_vis_map		*step;
	t_vis_map		*begin;
	t_visual_size	size[2];
	t_game_info		game_info;
	int				nbr_steps;
	pthread_t		thread_id;
}					t_visual_data;

enum		e_visual_size {MAP, PIECE};

void		ft_visual_exit(t_visual_data *d, int status);
void		ft_create_win_rend(t_visual_data *d);

void		ft_visual_error(t_visual_data *d, int error);
void		ft_thread_error(t_visual_data *d, int error);

void		ft_visual_events(t_visual_data *d);
void		ft_key_pressed(t_visual_data *d);
void		ft_check_vm_header(t_visual_data *d);
void		*ft_read_game(void *data);
void		ft_check_players(t_visual_data *d);
void		ft_music(t_visual_data *d);

int			ft_read_map_size(t_visual_data *d, char *line);
t_vis_map	*ft_create_step(t_visual_data *d, t_vis_map *prev);
void		ft_skip_piece(t_visual_data *d, char *line);

void		ft_free_step(t_vis_map **step);

#endif
