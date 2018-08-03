/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 11:18:49 by rnovodra          #+#    #+#             */
/*   Updated: 2018/08/01 11:18:50 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visual.h"

void		ft_thread_error(t_visual_data *d, int error)
{
	if (error == -1)
		ft_printf("Error thread: %s\n", strerror(errno));
	else if (error == -2)
		ft_printf("Error: invalid map\n");
	else if (error == -3)
		ft_printf("Error: invalid piece\n");
	else if (error == -4)
		ft_printf("Error: invalid bot move\n");
	else if (error == -5)
		ft_printf("Error: invalid input\n");
	else if (error == -6)
		ft_printf("Error: invalid player1 score\n");
	else if (error == -7)
		ft_printf("Error: invalid player2 score\n");
	d->fl.thread_error = 1;
	pthread_exit(NULL);
}