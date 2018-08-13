/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 15:41:18 by rnovodra          #+#    #+#             */
/*   Updated: 2018/07/19 15:41:19 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		ft_error(t_filler_data *d, int error, char *line)
{
	int		fd;

	remove("rnovodra.trace");
	if ((fd = open("rnovodra.trace", O_RDWR | O_CREAT, 0666)) < 0)
		ft_dprintf(fd, "Error: %s\n", strerror(errno));
	else if (error == -1)
		ft_putendl_fd("Error: GNL error.", fd);
	else if (error == -2)
		ft_dprintf(fd, "Error: bad player info in line:\n[%s]\n", line);
	else if (error == -3)
		ft_dprintf(fd, "Error: bad map info in line:\n[%s]\n", line);
	else if (error == -4)
		ft_dprintf(fd, "Error: %s\n", strerror(errno));
	else if (error == -5)
		ft_dprintf(fd, "Error: bad piece info in line:\n[%s]\n", line);
	else if (error == -6)
		ft_dprintf(fd, "Error: invalid map\n");
	if (line)
		free(line);
	ft_filler_exit(d, 1);
}
