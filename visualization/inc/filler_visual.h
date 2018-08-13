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
# include <SDL2/SDL_image.h>
# include "ft_printf.h"
# include "libft.h"
# include <errno.h>
# include <pthread.h>
# define FPS 35
# define WIN_W 1200
# define WIN_H 800
# define WHITE 0xffffff
# define CLR 4
# define DBL (double)
# define FLT (float)
# define SDLK d->event.key.keysym.sym

typedef	struct		s_info_win
{
	SDL_Window		*ptr;
	SDL_Surface		*screen;
	int				h;
	int				w;
}					t_info_win;

typedef	struct		s_vis_map
{
	int					score_x;
	int					score_o;
	int					number;
	char				**map;
	struct s_vis_map	*next;
	struct s_vis_map	*prev;
}					t_vis_map;

typedef	struct		s_visual_flags
{
	unsigned int		stop_event:1;
	unsigned int		pause:1;
	unsigned int		thread_error:1;
	unsigned int		color:2;
	unsigned int		end_game:1;
	unsigned int		winner:1;
	unsigned int		win_hide:1;
}					t_visual_flags;

typedef	struct		s_visual_size
{
	int				start;
	int				w;
	int				h;
}					t_visual_size;

typedef	struct		s_game_info
{
	int				hex_clr[2][CLR];
	SDL_Color		rgb_clr[2][CLR];
	unsigned int	nbr_clr:2;
	char			*player_1;
	char			*player_2;
	int				start_y;
	int				start_x;
	int				centr_x;
	int				centr_y;
	int				dis;
	int				points;
}					t_game_info;

typedef	struct		s_font
{
	int				name_x[2];
	int				name_y;
	int				size;
}					t_font;

typedef	struct		s_visual_data
{
	t_info_win		win;
	SDL_Rect		rect_bar;
	SDL_Event		event;
	SDL_Cursor		*cursor;
	Mix_Music		*music;
	TTF_Font		*font_ttf[2];
	t_font			font;
	t_visual_flags	fl;
	t_vis_map		*step;
	t_vis_map		*begin;
	t_visual_size	info[2];
	t_game_info		game;
	int				size_rect;
	int				nbr_steps;
	pthread_t		thread_id;
}					t_visual_data;

enum				e_visual_size {MAP, PIECE};

void				ft_check_vm_header(t_visual_data *d);
void				ft_check_players(t_visual_data *d);

void				ft_music(t_visual_data *d);
void				ft_record_colors(t_visual_data *d);

void				ft_free_step(t_vis_map **step);
void				ft_visual_exit(t_visual_data *d, int status);
void				ft_visual_error(t_visual_data *d, int error);

void				ft_thread_error(t_visual_data *d, int error);
void				*ft_read_game(void *data);
int					ft_read_map_size(t_visual_data *d, char *line);
t_vis_map			*ft_create_step(t_visual_data *d, t_vis_map *prev);
void				ft_skip_piece(t_visual_data *d, char *line);

void				ft_create_win(t_visual_data *d);
void				ft_visual(t_visual_data *d);
void				ft_draw_game(t_visual_data *d);
void				ft_put_font(t_visual_data *d);
void				ft_put_bar(t_visual_data *d);
void				ft_put_winner(t_visual_data *d);

void				ft_key_pressed(t_visual_data *d);
void				ft_key_unpressed(t_visual_data *d);
void				ft_window_events(t_visual_data *d);

#endif
