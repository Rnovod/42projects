/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 12:08:03 by rnovodra          #+#    #+#             */
/*   Updated: 2018/07/18 12:08:04 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "ft_printf.h"
# include "libft.h"
# include <errno.h>
# include <stdio.h>

typedef	struct	s_info
{
	int				h;
	int				w;
	char			**pat;
}				t_info;

typedef	struct	s_coord
{
	int				x;
	int				y;
}				t_coord;

typedef	struct	s_filler_data
{
	t_info			info[2];
	float			**heatmap;
	int				start_map;
	float			best_grade;
	unsigned char	player_symb;
	unsigned char	enemy_symb;
}				t_filler_data;

enum			e_info {MAP, PIECE};

void			ft_get_player_nbr(t_filler_data *d);

void			ft_get_map_size(t_filler_data *d);
void			ft_get_map(t_filler_data *d);

void			ft_get_piece_size(t_filler_data *d);
void			ft_get_piece(t_filler_data *d);

void			ft_filler(t_filler_data *d, t_coord *answer);
int				ft_eval_answer(t_filler_data *d, t_coord pre_answ);
void			ft_heatmap(t_filler_data *d);

void			ft_valid_map(t_filler_data *d);

void			ft_filler_exit(t_filler_data *d, int status);
void			ft_error(t_filler_data *d, int error, char *line);

#endif
