/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 18:54:47 by rnovodra          #+#    #+#             */
/*   Updated: 2018/08/08 18:54:48 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_menu.h"

static inline int		ft_check_data(t_menu_data *d)
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
		gtk_dialog_run(GTK_DIALOG(dialog));
		gtk_widget_destroy(dialog);
		return (1);
	}
	return (0);
}

static inline	char	*ft_command_line(t_menu_data *d, char *str)
{
	char	*tmp;

	tmp = str;
	if (!(str = ft_strjoin(str, d->map)))
		ft_menu_error(d, 0, tmp);
	free(tmp);
	tmp = str;
	if (!(str = ft_strjoin(str, " | ")))
		ft_menu_error(d, 0, tmp);
	free(tmp);
	tmp = str;
	if (!(str = ft_strjoin(str, " ./../visualization/visual")))
		ft_menu_error(d, 0, tmp);
	free(tmp);
	return (str);
}

static inline	char	*ft_create_command_line(t_menu_data *d)
{
	char	*str;
	char	*tmp;

	str = "./filler_vm -p1 ";
	if (!(str = ft_strjoin(str, d->player_1)))
		ft_menu_error(d, 0, NULL);
	tmp = str;
	if (!(str = ft_strjoin(str, " -p2 ")))
		ft_menu_error(d, 0, tmp);
	free(tmp);
	tmp = str;
	if (!(str = ft_strjoin(str, d->player_2)))
		ft_menu_error(d, 0, tmp);
	free(tmp);
	tmp = str;
	if (!(str = ft_strjoin(str, " -f ")))
		ft_menu_error(d, 0, tmp);
	free(tmp);
	str = ft_command_line(d, str);
	return (str);
}

void					ft_start_game(GtkApplication *app, t_menu_data *d)
{
	char	*str;

	if (ft_check_data(d) != 0)
		return ;
	str = ft_create_command_line(d);
	system(str);
	free(str);
	(void)app;
}
