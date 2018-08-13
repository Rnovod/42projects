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

int		main(void)
{
	t_visual_data	d;

	ft_bzero(&d, sizeof(t_visual_data));
	ft_check_vm_header(&d);
	ft_check_players(&d);
	d.nbr_steps = -1;
	pthread_create(&d.thread_id, NULL, &ft_read_game, &d);
	ft_record_colors(&d);
	ft_visual(&d);
	ft_visual_exit(&d, EXIT_SUCCESS);
}
