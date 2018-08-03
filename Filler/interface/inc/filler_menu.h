/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_menu.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 19:26:49 by rnovodra          #+#    #+#             */
/*   Updated: 2018/07/27 19:26:50 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_VISUAL_H
# define FILLER_VISUAL_H

# include <gtk/gtk.h>
#include <stdio.h>
#include <string.h>

typedef	GtkWidget *t_widgets;

enum e_widgets_name {GRID, IMAGE, BUTTON_1, BUTTON_2, BUTTON_3, BUTTON_4,
					BUTTON_5};

typedef	struct	s_menu_data
{
	t_widgets		wid[7];
	GtkCssProvider	*provider;
	GdkDisplay		*display;
	GdkScreen		*screen;
	GtkWidget		*win;
	gchar			*player_1;
	gchar			*player_2;
	gchar			*map;
}				t_menu_data;

void			ft_menu_error(t_menu_data *d, int error);
void			ft_choose_pl1(GtkApplication* app, t_menu_data *d);
void			ft_choose_pl2(GtkApplication* app, t_menu_data *d);
void			ft_choose_map(GtkApplication* app, t_menu_data *d);

# endif
