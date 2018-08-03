/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 16:29:27 by rnovodra          #+#    #+#             */
/*   Updated: 2018/07/30 16:29:28 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visual.h"

void	ft_init(t_visual_data *d)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		ft_visual_error(d, 0);
	if (TTF_Init() < 0)
		ft_visual_error(d, 7);
	if (MIX_INIT_MP3 & Mix_Init(MIX_INIT_MP3))
		ft_visual_error(d, 6);
}

void	ft_run_visual(t_visual_data *d)
{
	pthread_create(&d->thread_id, NULL, &ft_read_game, d);
	ft_visual_events(d);
}

int		main(int ac, char **av)
{
	t_visual_data	d;

	ft_bzero(&d, sizeof(t_visual_data));
	ft_check_vm_header(&d);
	ft_check_players(&d);
	ft_init(&d);
	ft_music(&d);
	ft_create_win_rend(&d);
	ft_run_visual(&d);
	(void)ac;
	(void)av;
	ft_visual_exit(&d, EXIT_SUCCESS);
}
