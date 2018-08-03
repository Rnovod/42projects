/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyevresh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:11:40 by eyevresh          #+#    #+#             */
/*   Updated: 2017/11/28 17:27:49 by eyevresh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *tmp;

	tmp = *alst;
	if (alst != NULL && new != NULL)
	{
		if (*alst == NULL)
		{
			*alst = new;
			return ;
		}
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}
