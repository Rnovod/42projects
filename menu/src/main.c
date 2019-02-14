/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 19:26:28 by rnovodra          #+#    #+#             */
/*   Updated: 2018/07/27 19:26:29 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_menu.h"

int		main(int argc, char **argv)
{
	t_menu_data		d;
	GtkApplication	*app;

	ft_bzero(&d, sizeof(d));
	gtk_disable_setlocale();
	if (!(app = gtk_application_new("menu.rnovodra.filler",
		G_APPLICATION_FLAGS_NONE)))
		ft_menu_error(&d, 2, NULL);
	if (!g_signal_connect(app, "activate", G_CALLBACK(ft_main_window), &d))
	{
		g_object_unref(app);
		ft_menu_error(&d, 3, NULL);
	}
	if (g_application_run(G_APPLICATION(app), argc, argv))
	{
		g_object_unref(app);
		ft_menu_error(&d, 4, NULL);
	}
	g_object_unref(app);
	return (0);
}
