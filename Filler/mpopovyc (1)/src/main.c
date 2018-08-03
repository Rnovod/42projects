/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 15:45:36 by mpopovyc          #+#    #+#             */
/*   Updated: 2018/07/02 15:57:15 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	t_flr	p;
	t_coord cr;

	read_data(&p);
	p.map = NULL;
	p.piece = NULL;
	while (get_next_line(0, &p.line) > 0)
	{
		init_str(&cr);
		fill_map(&p, &cr);
		fill_piece(&p, &cr);
		if (get_coord(&p, &cr))
		{
			ft_putnbr(cr.y);
			ft_putstr(" ");
			ft_putnbr(cr.x);
		}
		else
		{
			ft_putnbr(0);
			ft_putstr(" ");
			ft_putnbr(0);
		}
		ft_putstr("\n");
	}
}
