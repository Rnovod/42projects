/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 17:33:46 by rnovodra          #+#    #+#             */
/*   Updated: 2018/07/28 17:33:46 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_menu.h"

void		ft_choose_pl1(GtkApplication *app, t_menu_data *d)
{
	GtkWidget				*dialog;
	GtkFileChooserAction	action;
	gint					res;

	action = GTK_FILE_CHOOSER_ACTION_OPEN;
	dialog = gtk_file_chooser_dialog_new("Choose file", GTK_WINDOW(d->win),
		action, "_Cancel", GTK_RESPONSE_CANCEL, "_Open",
		GTK_RESPONSE_ACCEPT, NULL);
	res = gtk_dialog_run(GTK_DIALOG(dialog));
	if (res == GTK_RESPONSE_ACCEPT)
	{
		if (d->player_1)
			free(d->player_1);
		d->player_1 = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
	}
	(void)app;
	gtk_widget_destroy(dialog);
}

void		ft_choose_pl2(GtkApplication *app, t_menu_data *d)
{
	GtkWidget				*dialog;
	GtkFileChooserAction	action;
	gint					res;

	action = GTK_FILE_CHOOSER_ACTION_OPEN;
	dialog = gtk_file_chooser_dialog_new("Choose file", GTK_WINDOW(d->win),
		action, "_Cancel", GTK_RESPONSE_CANCEL, "_Open",
		GTK_RESPONSE_ACCEPT, NULL);
	res = gtk_dialog_run(GTK_DIALOG(dialog));
	if (res == GTK_RESPONSE_ACCEPT)
	{
		if (d->player_2)
			free(d->player_2);
		d->player_2 = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
	}
	(void)app;
	g_object_ref_sink(dialog);
	gtk_widget_destroy(dialog);
}

void		ft_choose_map(GtkApplication *app, t_menu_data *d)
{
	GtkWidget				*dialog;
	GtkFileChooserAction	action;
	gint					res;

	action = GTK_FILE_CHOOSER_ACTION_OPEN;
	dialog = gtk_file_chooser_dialog_new("Choose file", GTK_WINDOW(d->win),
		action, "_Cancel", GTK_RESPONSE_CANCEL, "_Open",
		GTK_RESPONSE_ACCEPT, NULL);
	res = gtk_dialog_run(GTK_DIALOG(dialog));
	if (res == GTK_RESPONSE_ACCEPT)
	{
		if (d->map)
			free(d->map);
		d->map = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
	}
	(void)app;
	gtk_widget_destroy(dialog);
}
