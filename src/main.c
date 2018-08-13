/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 12:07:18 by rnovodra          #+#    #+#             */
/*   Updated: 2018/07/18 12:07:21 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_print_answer(t_coord answer)
{
	ft_putnbr(answer.y);
	ft_putchar(' ');
	ft_putnbr(answer.x);
	ft_putchar('\n');
}

int		main(void)
{
	t_filler_data	d;
	t_coord			answer;

	ft_bzero(&d, sizeof(d));
	ft_get_player_nbr(&d);
	while (42)
	{
		ft_bzero(&answer, sizeof(answer));
		d.best_grade = -1.0;
		ft_get_map_size(&d);
		ft_get_map(&d);
		ft_get_piece_size(&d);
		ft_get_piece(&d);
		ft_filler(&d, &answer);
		ft_print_answer(answer);
		ft_arrfree(&d.info[PIECE].pat);
		ft_arrfree(&d.info[MAP].pat);
	}
	return (0);
}
