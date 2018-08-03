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

void		ft_choose_pl1(GtkApplication* app, t_menu_data *d)
{
	GtkWidget				*dialog;
	GtkFileChooser			*chooser;
	GtkFileChooserAction	action;
	gint					res;

	action = GTK_FILE_CHOOSER_ACTION_OPEN;
	dialog = gtk_file_chooser_dialog_new("Choose file", GTK_WINDOW(d->win),
		action, "_Cancel", GTK_RESPONSE_CANCEL, "_Open",
		GTK_RESPONSE_ACCEPT, NULL);
	res = gtk_dialog_run(GTK_DIALOG(dialog));
	if (res == GTK_RESPONSE_ACCEPT)
	{
		chooser = GTK_FILE_CHOOSER(dialog);
		d->player_1 = gtk_file_chooser_get_filename(chooser);
	}
	(void)app;
	gtk_widget_destroy(dialog);
}

void		ft_choose_pl2(GtkApplication* app, t_menu_data *d)
{
	GtkWidget				*dialog;
	GtkFileChooser			*chooser;
	GtkFileChooserAction	action;
	gint					res;

	action = GTK_FILE_CHOOSER_ACTION_OPEN;
	dialog = gtk_file_chooser_dialog_new("Choose file", GTK_WINDOW(d->win),
		action, "_Cancel", GTK_RESPONSE_CANCEL, "_Open",
		GTK_RESPONSE_ACCEPT, NULL);
	res = gtk_dialog_run(GTK_DIALOG(dialog));
	if (res == GTK_RESPONSE_ACCEPT)
	{
		chooser = GTK_FILE_CHOOSER(dialog);
		d->player_2 = gtk_file_chooser_get_filename(chooser);
	}
	(void)app;
	gtk_widget_destroy(dialog);
}

void		ft_choose_map(GtkApplication* app, t_menu_data *d)
{
	GtkWidget				*dialog;
	GtkFileChooser			*chooser;
	GtkFileChooserAction	action;
	gint					res;

	action = GTK_FILE_CHOOSER_ACTION_OPEN;
	dialog = gtk_file_chooser_dialog_new("Choose file", GTK_WINDOW(d->win),
		action, "_Cancel", GTK_RESPONSE_CANCEL, "_Open",
		GTK_RESPONSE_ACCEPT, NULL);
	res = gtk_dialog_run(GTK_DIALOG(dialog));
	if (res == GTK_RESPONSE_ACCEPT)
	{
		chooser = GTK_FILE_CHOOSER(dialog);
		d->map = gtk_file_chooser_get_filename(chooser);
	}
	(void)app;
	gtk_widget_destroy(dialog);
}
