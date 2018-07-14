/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovodra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 17:26:20 by rnovodra          #+#    #+#             */
/*   Updated: 2018/07/07 17:26:21 by rnovodra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/ft_printf.h"

inline	static	void	ft_put_color(t_data *d, char *str_color)
{
	t_bytes	*ptr_buff;
	t_bytes	*ptr_color;

	ptr_buff = (t_bytes*)&d->buff[d->buff_i];
	ptr_color = (t_bytes*)str_color;
	ptr_buff->byte7 = ptr_color->byte7;
	d->buff_i += 7;
	d->ret -= 7;
}

inline	static	int		ft_choose_color(t_data *d, char *color, int chrs)
{
	t_bytes *ptr;

	ptr = (t_bytes*)color;
	if (ptr->byte3 == EOC_CODE && chrs == 4)
		ft_put_color(d, EOC);
	else if (ptr->byte3 == RED_CODE && chrs == 4)
		ft_put_color(d, RED);
	else if (ptr->byte5 == GREEN_CODE && chrs == 6)
		ft_put_color(d, GREEN);
	else if (ptr->byte6 == YELLOW_CODE && chrs == 7)
		ft_put_color(d, YELLOW);
	else if (ptr->byte4 == BLUE_CODE && chrs == 5)
		ft_put_color(d, BLUE);
	else if (ptr->byte6 == PURPLE_CODE && chrs == 7)
		ft_put_color(d, PURPLE);
	else if (ptr->byte4 == CYAN_CODE && chrs == 5)
		ft_put_color(d, CYAN);
	else if (ptr->byte5 == WHITE_CODE && chrs == 6)
		ft_put_color(d, WHITE);
	else
		return (1);
	d->form_i += chrs;
	return (0);
}

void					ft_color(t_data *d, const char *f)
{
	int		i;
	int		flag;
	char	str_col[7];

	i = 0;
	flag = 0;
	++d->form_i;
	while (f[i + d->form_i] && f[i + d->form_i] && i < 7)
	{
		if (f[i + d->form_i] == '}')
		{
			flag = 1;
			break ;
		}
		str_col[i] = f[i + d->form_i];
		i++;
	}
	if (!flag || ft_choose_color(d, str_col, ++i))
		FT_PRINTF_BUFF_SIZE == d->buff_i ? ft_print_buff(d) :
		(d->buff[d->buff_i++] = '{');
}
