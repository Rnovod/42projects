/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 11:40:14 by rnovodra          #+#    #+#             */
/*   Updated: 2018/07/28 11:40:14 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_menu.h"

void		ft_menu_error(t_menu_data *d, int error, char *str)
{
	if (str)
		free(str);
	if (error == 0)
		ft_printf("Error: %s\n", strerror(errno));
	else if (error == 1)
		ft_printf("Error: fall gtk init\n");
	else if (error == 2)
		ft_printf("Error: Can't create new application\n");
	else if (error == 3)
		ft_printf("Error: Can't connect signal\n");
	else if (error == 4)
		ft_printf("Error: Can't run the application\n");
	else if (error == 5)
		ft_printf("Error: Can't create a new window\n");
	(void)d;
	exit(1);
}
