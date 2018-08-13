/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_players.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 12:27:23 by rnovodra          #+#    #+#             */
/*   Updated: 2018/07/31 12:27:24 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visual.h"

static inline int	ft_get_name(t_visual_data *d, char *line, char **player)
{
	char	*cp;
	int		len;

	len = 0;
	cp = line;
	if (!(cp = ft_strstr(line, ".filler")))
		return (1);
	while (cp - line > 0 && *cp != '/')
	{
		++len;
		--cp;
	}
	if (!(cp - line))
		return (1);
	++cp;
	if (!(*player = ft_strnew(--len)))
	{
		free(line);
		ft_visual_error(d, 1);
	}
	ft_strncpy(*player, cp, len);
	return (0);
}

static inline int	ft_get_player_name(t_visual_data *d, char **player)
{
	char	*line;

	line = NULL;
	if (get_next_line(0, &line) < 0)
		ft_visual_error(d, 1);
	if (!ft_strncmp(line, "$$$ exec p1 : ", 14) ||
		!ft_strncmp(line, "$$$ exec p2 : ", 14))
	{
		if (ft_get_name(d, line, player))
		{
			free(line);
			return (1);
		}
	}
	else
	{
		free(line);
		return (1);
	}
	free(line);
	return (0);
}

void				ft_check_players(t_visual_data *d)
{
	char	*line;

	line = NULL;
	if (get_next_line(0, &line) < 0)
		ft_visual_error(d, 1);
	if (ft_strncmp("launched ", line, 9))
		ft_visual_error(d, 3);
	free(line);
	if (ft_get_player_name(d, &d->game.player_1))
		ft_visual_error(d, 4);
	if (get_next_line(0, &line) < 0)
		ft_visual_error(d, 1);
	if (ft_strncmp("launched ", line, 9))
		ft_visual_error(d, 3);
	free(line);
	if (ft_get_player_name(d, &d->game.player_2))
		ft_visual_error(d, 5);
}
