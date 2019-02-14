/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 18:53:04 by rnovodra          #+#    #+#             */
/*   Updated: 2018/08/08 18:53:05 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_menu.h"

static inline void		ft_create_window(GtkApplication *app, t_menu_data *d)
{
	if (!(d->win = gtk_application_window_new(app)))
		ft_menu_error(d, 5, NULL);
	gtk_window_set_position(GTK_WINDOW(d->win), GTK_WIN_POS_CENTER);
	gtk_window_set_title(GTK_WINDOW(d->win), "FILLER");
	gtk_window_set_default_size(GTK_WINDOW(d->win), 600, 650);
	gtk_window_set_resizable(GTK_WINDOW(d->win), FALSE);
	gtk_widget_set_name(d->win, "win");
}

static inline void		ft_load_css(t_menu_data *d)
{
	d->provider = gtk_css_provider_new();
	d->display = gdk_display_get_default();
	d->screen = gdk_display_get_default_screen(d->display);
	gtk_style_context_add_provider_for_screen(d->screen,
		GTK_STYLE_PROVIDER(d->provider),
		GTK_STYLE_PROVIDER_PRIORITY_USER);
	gtk_css_provider_load_from_path(d->provider, "./styles/styles.css", NULL);
}

static inline GtkWidget	*ft_create_grid(t_menu_data *d)
{
	GtkWidget		*grid;

	grid = gtk_grid_new();
	gtk_container_add(GTK_CONTAINER(d->win), grid);
	gtk_widget_set_hexpand(grid, FALSE);
	gtk_widget_set_vexpand(grid, FALSE);
	gtk_widget_set_halign(grid, GTK_ALIGN_CENTER);
	gtk_container_set_border_width(GTK_CONTAINER(grid), 50);
	return (grid);
}

void					ft_main_window(GtkApplication *app, t_menu_data *d)
{
	ft_create_window(app, d);
	ft_load_css(d);
	d->wid[GRID] = ft_create_grid(d);
	d->wid[IMAGE] = gtk_image_new_from_file("./img/42.png");
	gtk_grid_attach(GTK_GRID(d->wid[GRID]), d->wid[IMAGE], 0, 0, 2, 1);
	d->wid[BUTTON_1] = gtk_button_new_with_label("Start the game");
	gtk_grid_attach(GTK_GRID(d->wid[GRID]), d->wid[BUTTON_1], 0, 1, 2, 1);
	g_signal_connect(d->wid[BUTTON_1], "clicked", G_CALLBACK(ft_start_game), d);
	d->wid[BUTTON_2] = gtk_button_new_with_label("First fighter");
	gtk_grid_attach(GTK_GRID(d->wid[GRID]), d->wid[BUTTON_2], 0, 2, 1, 1);
	g_signal_connect(d->wid[BUTTON_2], "clicked", G_CALLBACK(ft_choose_pl1), d);
	d->wid[BUTTON_3] = gtk_button_new_with_label("Second fighter");
	gtk_grid_attach(GTK_GRID(d->wid[GRID]), d->wid[BUTTON_3], 1, 2, 1, 1);
	g_signal_connect(d->wid[BUTTON_3], "clicked", G_CALLBACK(ft_choose_pl2), d);
	d->wid[BUTTON_4] = gtk_button_new_with_label("Choose the map");
	gtk_grid_attach(GTK_GRID(d->wid[GRID]), d->wid[BUTTON_4], 0, 3, 2, 1);
	g_signal_connect(d->wid[BUTTON_4], "clicked", G_CALLBACK(ft_choose_map), d);
	d->wid[BUTTON_5] = gtk_button_new_with_label("Exit");
	gtk_grid_attach(GTK_GRID(d->wid[GRID]), d->wid[BUTTON_5], 0, 4, 2, 1);
	g_signal_connect_swapped(d->wid[BUTTON_5], "clicked",
		G_CALLBACK(gtk_widget_destroy), d->win);
	gtk_widget_show_all(d->win);
}
