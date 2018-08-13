/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_vm_header.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 19:02:00 by rnovodra          #+#    #+#             */
/*   Updated: 2018/07/30 19:02:01 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visual.h"

static inline void	ft_cmp_header(t_visual_data *d, char *str)
{
	char		*line;
	short int	i;

	line = NULL;
	if (get_next_line(0, &line) < 0)
		ft_visual_error(d, 1);
	i = 0;
	while (line[i] != '\0' && str[i])
	{
		if (line[i] != str[i])
		{
			free(line);
			ft_printf("line:\n%s\nmust be equil:\n%s\n", line, str);
			ft_visual_error(d, 2);
		}
		i++;
	}
	if (line[i] != '\0' || (str[i] && line[i] == '\0'))
	{
		free(line);
		ft_printf("line:\n%s\nmust be equil:\n%s\n", line, str);
		ft_visual_error(d, 2);
	}
	free(line);
}

void				ft_check_vm_header(t_visual_data *d)
{
	ft_cmp_header(d, "# -------------- VM  version 1.1 ------------- #");
	ft_cmp_header(d, "#                                              #");
	ft_cmp_header(d, "# 42 / filler VM Developped by: Hcao - Abanlin #");
	ft_cmp_header(d, "#                                              #");
	ft_cmp_header(d, "# -------------------------------------------- #");
}
