/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 19:30:54 by mpopovyc          #+#    #+#             */
/*   Updated: 2018/07/19 19:30:55 by mpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vizualization.h"

void	events(t_viz *v)
{
	if (v->event.type == SDL_QUIT ||
		v->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
		v->running = 0;
	else if (v->event.key.type == SDL_KEYDOWN &&
		v->event.key.keysym.scancode == SDL_SCANCODE_SPACE)
	{
		if (v->pause == 0)
			v->pause = 1;
		else
			v->pause = 0;
	}
}
