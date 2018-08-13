/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_music.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 14:10:51 by rnovodra          #+#    #+#             */
/*   Updated: 2018/08/02 14:10:52 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visual.h"

void		ft_music(t_visual_data *d)
{
	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 4096) < 0)
		ft_visual_error(d, 0);
	if (!(d->music = Mix_LoadMUS("./music/MK.mp3")))
		ft_visual_error(d, 0);
}
