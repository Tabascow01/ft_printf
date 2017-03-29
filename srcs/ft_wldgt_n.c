/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wldgt_n.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 04:29:51 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/29 04:42:13 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_wldgt_5(t_flags *list, t_precs *lst, int *dgit)
{
	if (list->wargs[0] == '-' || list->wargs[0] == '+')
		lst->i = 0;
	else
		lst->i = 1;
	lst->j = 0;
	lst->wtmp = ft_wstrnew((*dgit) - lst->size);
	while (lst->i <= (*dgit) - lst->size)
	{
		if (list->wargs[0] == '-' && lst->j < 1)
			lst->wtmp[lst->j++] = '-';
		else if (list->wargs[0] == '+' && lst->j < 1)
			lst->wtmp[lst->j++] = '+';
		else
			lst->wtmp[lst->j++] = '0';
		lst->i++;
	}
	if (lst->j >= 1)
		lst->wtmp[lst->j] = '\0';
}

void	ft_wldgt_4(t_precs *lst, int *digittmp, wchar_t **newarg)
{
	while (lst->i < (*digittmp))
		(*newarg)[lst->i++] = ' ';
	lst->i--;
}

void	ft_wldgt_3(t_precs *lst, int *digittmp, wchar_t **newarg)
{
	while (lst->i < (*digittmp) - lst->size)
		(*newarg)[lst->i++] = ' ';
	lst->i--;
}

void	ft_wldgt_2(t_flags *list, t_precs *lst, int *digittmp, int *dgit)
{
	if (list->wargs[0] == '-' || list->wargs[0] == '+')
		lst->size -= 1;
	if ((*digittmp) > (*dgit) && (list->space > 0 || list->sign > 0))
		(*digittmp) -= (*dgit);
}

void	ft_wldgt_1(t_flags *list, t_precs *lst, int *digittmp)
{
	(*digittmp) = ft_atoi((void *)lst->wtmp);
	ft_wstrdel(&lst->wtmp);
	lst->i = 0;
	lst->size = (int)ft_wstrlen(list->wargs);
}
