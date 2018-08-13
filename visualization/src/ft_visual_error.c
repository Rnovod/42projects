/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 16:40:16 by rnovodra          #+#    #+#             */
/*   Updated: 2018/07/30 16:40:17 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visual.h"

void		ft_visual_error(t_visual_data *d, int error)
{
	pthread_cancel(d->thread_id);
	if (d->fl.thread_error == 1)
		ft_printf("Error: thread failed\n");
	else if (error == 0)
		ft_printf("Error initializing SDL: %s\n", SDL_GetError());
	else if (error == 1)
		ft_printf("Error: %s\n", strerror(errno));
	else if (error == 2)
		ft_printf("Bad vm header.\n");
	else if (error == 3)
		ft_printf("Bad launched.\n");
	else if (error == 4)
		ft_printf("Bad player1.\n");
	else if (error == 5)
		ft_printf("Bad player2.\n");
	else if (error == 6)
		ft_printf("Mix_Init: %s\n", Mix_GetError());
	else if (error == 7)
		ft_printf("TTF_Init: %s\n", TTF_GetError());
	else if (error == 8)
		ft_printf("IMG_Init: %s\n", IMG_GetError());
	ft_visual_exit(d, EXIT_FAILURE);
}
