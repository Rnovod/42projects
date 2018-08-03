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

static	int			ft_check_data(t_menu_data *d)
{
	GtkWidget	*dialog;
	gchar		*str;

	if (!d->player_1)
		str = "first fighter";
	else if (!d->player_2)
		str = "second fighter";
	else if (!d->map)
		str = "map";
	else
		str = NULL;
	if (!d->player_1 || !d->player_2 || !d->map)
	{
		dialog = gtk_message_dialog_new(GTK_WINDOW(d->win),
				GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_ERROR,
				GTK_BUTTONS_CLOSE, "Please choose the %s", str);
		gtk_dialog_run (GTK_DIALOG(dialog));
		gtk_widget_destroy (dialog);
		return (1);
	}
	return (0);
}


static	inline	size_t	ft_calc_len(char *cp, const char *str)
{
	if (cp[0] == 0)
		return (cp - str);
	if (cp[1] == 0)
		return (cp - str + 1);
	if (cp[2] == 0)
		return (cp - str + 2);
	if (cp[3] == 0)
		return (cp - str + 3);
	if (cp[4] == 0)
		return (cp - str + 4);
	if (cp[5] == 0)
		return (cp - str + 5);
	if (cp[6] == 0)
		return (cp - str + 6);
	else
		return (cp - str + 7);
}

size_t					ft_strlen(const char *str)
{
	char		*cp;
	uintmax_t	*longword_ptr;
	uintmax_t	longword;

	longword_ptr = (uintmax_t *)str;
	if (!str)
		return (0);
	while (42)
	{
		longword = *longword_ptr++;
		if (((longword - 0x101010101010101L)
			& ~longword & 0x8080808080808080L) != 0)
		{
			cp = (char *)(longword_ptr - 1);
			return (ft_calc_len(cp, str));
		}
	}
}

char	*ft_strcpy(char *dest, const char *src)
{
	size_t i;

	i = 0;
	if (!dest || !src)
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcat(char *dest, const char *src)
{
	ssize_t len;

	len = ft_strlen(dest);
	ft_strcpy(&dest[len], src);
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	if (!(str = (char*)malloc(sizeof(char) *
					(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	return (str);
}

static	void		ft_start_game(GtkApplication* app, t_menu_data *d)
{
	char	*str;
	char	*tmp;

	str = "./filler_vm -p1 ";
	if (ft_check_data(d) != 0)
		return ;
	tmp = str;
	str = ft_strjoin(str, d->player_1);
	// free(tmp);
	tmp = str;
	str = ft_strjoin(str, " -p2 ");
	// free(tmp);
	tmp = str;
	str = ft_strjoin(str, d->player_2);
	// free(tmp);
	tmp = str;
	str = ft_strjoin(str, " -f ");
	// free(tmp);
	tmp = str;
	str = ft_strjoin(str, d->map);
	// free(tmp);
	tmp = str;
	str = ft_strjoin(str, " | ");
	// free(tmp);
	tmp = str;
	str = ft_strjoin(str, " ./../visualization/visual&");
	// free(tmp);
	system(str);
	(void)app;
}

static	void		ft_create_window(GtkApplication* app, t_menu_data *d)
{
	if (!(d->win = gtk_application_window_new(app)))
		ft_menu_error(d, 5);
	gtk_window_set_position(GTK_WINDOW(d->win), GTK_WIN_POS_CENTER);
	gtk_window_set_title(GTK_WINDOW(d->win), "FILLER");
	gtk_window_set_default_size(GTK_WINDOW(d->win), 600, 650);
	gtk_window_set_resizable(GTK_WINDOW(d->win), FALSE);
	gtk_widget_set_name(d->win, "win");
}

static	void		ft_load_css(t_menu_data *d)
{
	d->provider = gtk_css_provider_new();
	d->display = gdk_display_get_default();
	d->screen = gdk_display_get_default_screen(d->display);
	gtk_style_context_add_provider_for_screen(d->screen,
		GTK_STYLE_PROVIDER(d->provider),
		GTK_STYLE_PROVIDER_PRIORITY_USER);
	gtk_css_provider_load_from_path(d->provider, "./styles/styles.css", NULL);
}

static	t_widgets	ft_create_grid(t_menu_data *d)
{
	t_widgets	grid;

	grid = gtk_grid_new();
	gtk_container_add(GTK_CONTAINER(d->win), grid);
	gtk_widget_set_hexpand(grid, FALSE);
	gtk_widget_set_vexpand(grid, FALSE);
	gtk_widget_set_halign(grid, GTK_ALIGN_CENTER);
	gtk_container_set_border_width(GTK_CONTAINER(grid), 50);
	return (grid);
}

static	void		ft_main_window(GtkApplication* app, t_menu_data *d)
{
	ft_create_window(app, d);
	ft_load_css(d);
	d->wid[GRID] = ft_create_grid(d);
	d->wid[IMAGE] = gtk_image_new_from_file ("./img/42.png");
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

int		main(int argc, char **argv)
{
	t_menu_data		d;
	GtkApplication	*app;

	bzero(&d, sizeof(d));
	gtk_disable_setlocale();
	if (!(app = gtk_application_new("menu.rnovodra.filler", G_APPLICATION_FLAGS_NONE)))
		ft_menu_error(&d, 2);
	if (!g_signal_connect(app, "activate", G_CALLBACK(ft_main_window), &d))
	{
		g_object_unref(app);
		ft_menu_error(&d, 3);
	}
	if (g_application_run(G_APPLICATION(app), argc, argv))
	{
		g_object_unref(app);
		ft_menu_error(&d, 4);
	}
	g_object_unref(app);
	return (0);
}