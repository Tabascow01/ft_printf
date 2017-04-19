/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 20:03:47 by mchemakh          #+#    #+#             */
/*   Updated: 2016/11/22 15:34:29 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *element))
{
	t_list *list;

	if (lst != NULL)
	{
		list = lst;
		while (list != NULL)
		{
			f(list);
			list = list->next;
		}
	}
}
