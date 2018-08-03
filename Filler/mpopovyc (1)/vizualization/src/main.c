/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vizualization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 19:18:09 by vnekhay           #+#    #+#             */
/*   Updated: 2018/07/18 19:18:10 by vnekhay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vizualization.h"

int		main(void)
{
	t_viz v;
	t_flr p;

	init_strctr(&v);
	init_sdl(&v);
	while (v.running)
	{
		if (!v.pause)
		{
			get_next_line(0, &p.line);
			if (ft_strrchr(p.line, '/') && p.line[0] == '$')
				draw_player(&v, p.line);
			if (ft_strstr(p.line, "Plateau"))
				draw_map(&p, &v);
			if (ft_strstr(p.line, "fin"))
				final_score(&v);
			SDL_UpdateWindowSurface(v.window);
			ft_strdel(&p.line);
		}
		if (SDL_PollEvent(&v.event))
			events(&v);
	}
	quit_sdl(&v);
	return (0);
}
