/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldgt_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 02:13:40 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/29 03:42:14 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_ldgt_5(t_flags *list, t_precs *lst, int *digit, char **newarg)
{
	if (lst->i > 0 && ((*digit) > 0 || (*digit) - lst->size > 0))
		(*newarg)[lst->i] = '\0';
	if (list->args[0] == '-' || list->args[0] == '+')
		lst->i = 0;
	else
		lst->i = 1;
	lst->j = 0;
	if ((*digit) - lst->size > 0)
		lst->tmp = ft_memalloc((*digit) - lst->size);
	while (lst->i <= (*digit) - lst->size)
	{
		if (list->args[0] == '-' && lst->j < 1)
			lst->tmp[lst->j++] = '-';
		else if (list->args[0] == '+' && lst->j < 1)
			lst->tmp[lst->j++] = '+';
		else
			lst->tmp[lst->j++] = '0';
		lst->i++;
	}
	if (lst->j >= 1)
		lst->tmp[lst->j] = '\0';
}

void	ft_ldgt_4(t_precs *lst, int *digittmp, char **newarg)
{
	while (lst->i < (*digittmp))
		(*newarg)[lst->i++] = ' ';
	lst->i--;
}

void	ft_ldgt_3(t_precs *lst, int *digittmp, char **newarg)
{
	while (lst->i < (*digittmp) - lst->size)
		(*newarg)[lst->i++] = ' ';
	lst->i--;
}

void	ft_ldgt_2(t_flags *list, t_precs *lst, int *digittmp, int *digit)
{
	if (list->args[0] == '-' || list->args[0] == '+')
		lst->size -= 1;
	if ((*digittmp) > (*digit) && (list->space > 0 || list->sign > 0))
		(*digittmp) -= (*digit);
	else if (((*digit) == lst->size || (*digit) - lst->size < 0) && (*digittmp) > (*digit) && (*digit) != 0)
		(*digittmp) += 1;
}

void	ft_ldgt_1(t_flags *list, t_precs *lst, int *digittmp)
{
	(*digittmp) = ft_atoi(lst->tmp);
	ft_strdel(&lst->tmp);
	lst->i = 0;
	lst->size = (int)ft_strlen(list->args);
}
