/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 13:14:30 by rnovodra          #+#    #+#             */
/*   Updated: 2018/07/31 13:14:31 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visual.h"

static inline void		ft_create_begin(t_visual_data *d)
{
	char	*line;

	if (get_next_line(0, &line) < 0)
		ft_thread_error(d, -1);
	if (ft_read_map_size(d, line) < 0)
		ft_thread_error(d, -2);
	d->begin = ft_create_step(d, NULL);
	if (get_next_line(0, &line) < 0)
		ft_thread_error(d, -1);
	ft_skip_piece(d, line);
	if (get_next_line(0, &line) < 0)
		ft_thread_error(d, -1);
	if (ft_strncmp(line, "<got ", 5) &&
		ft_strncmp(line, "Player with", 11))
	{
		free(line);
		ft_thread_error(d, -4);
	}
	free(line);
}

static inline void		ft_get_score(t_visual_data *d,
						char *line, t_vis_map *ptr)
{
	char	*cp;

	cp = line;
	if (ft_strncmp(line, "== O fin:", 9) ||
		ft_getnbr(&cp, NULL) < 0)
	{
		free(line);
		ft_thread_error(d, -6);
	}
	free(line);
	if (get_next_line(0, &line) < 0)
		ft_thread_error(d, -1);
	cp = line;
	if (ft_strncmp(line, "== X fin:", 9) ||
		ft_getnbr(&cp, NULL) < 0)
	{
		free(line);
		ft_thread_error(d, -7);
	}
	free(line);
	d->nbr_steps = ptr->number;
	pthread_exit(NULL);
}

static inline t_vis_map	*ft_step(t_visual_data *d, t_vis_map *ptr, char *line)
{
	if (ft_read_map_size(d, line) < 0)
	{
		free(line);
		ft_thread_error(d, -2);
	}
	ptr->next = ft_create_step(d, ptr);
	ptr = ptr->next;
	return (ptr);
}

static inline void		ft_read_data(t_visual_data *d)
{
	char		*line;
	t_vis_map	*ptr;

	ptr = d->begin;
	while (42)
	{
		pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
		if (get_next_line(0, &line) < 0)
			ft_thread_error(d, -1);
		if (!ft_strncmp(line, "Plateau ", 8))
			ptr = ft_step(d, ptr, line);
		else if (!ft_strncmp(line, "Piece", 5))
			ft_skip_piece(d, line);
		else if (!ft_strncmp(line, "<got ", 5) ||
			!ft_strncmp(line, "Player with", 11))
			free(line);
		else if (!ft_strncmp(line, "== O fin:", 9))
			ft_get_score(d, line, ptr);
		else
		{
			free(line);
			ft_thread_error(d, -5);
		}
		pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
	}
}

void					*ft_read_game(void *data)
{
	t_visual_data	*d;

	d = (t_visual_data*)data;
	pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
	ft_create_begin(d);
	pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
	ft_read_data(d);
	pthread_exit(NULL);
}
