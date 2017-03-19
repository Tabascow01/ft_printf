/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 20:00:27 by mchemakh          #+#    #+#             */
/*   Updated: 2017/01/13 00:45:45 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_lstadd(t_list **alst, t_list *newlst)
{
	if (newlst != NULL)
	{
		newlst->next = *alst;
		*alst = newlst;
	}
}
