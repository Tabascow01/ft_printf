/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 20:00:46 by mchemakh          #+#    #+#             */
/*   Updated: 2016/11/22 15:31:50 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*list;

	if (alst == NULL || del == NULL)
		return ;
	list = *alst;
	while (list != NULL)
	{
		del(list->content, list->content_size);
		free(list);
		list = list->next;
	}
	*alst = NULL;
}
