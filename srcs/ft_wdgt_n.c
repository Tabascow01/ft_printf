/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wdgt_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 03:50:35 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/29 04:21:33 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_wdgt_5(t_flags *list, t_precs *lst, int *digittmp, wchar_t **newarg)
{
	if ((list->wargs[0] == '-' || list->wargs[0] == '+') && lst->i > 0)
	{
		list->wargs++;
		lst->wtmp = (*newarg);
		(*newarg) = ft_wstrjoin((*newarg), list->wargs);
		ft_wstrdel(&lst->wtmp);
		list->wargs--;
		lst->wtmp = list->wargs;
	}
	else
	{
		lst->wtmpargs = (*newarg);
		if ((*digittmp) > 0 && list->wargs[0] == '\0')
			list->wargs[0] = ' ';
		lst->wtmp = list->wargs;
		(*newarg) = ft_wstrjoin(lst->wtmpargs, list->wargs);
		ft_wstrdel(&lst->wtmpargs);
	}
}

void	ft_wdgt_4(t_flags *list, t_precs *lst, int *dgit, wchar_t **newarg)
{
	lst->j = 0;
	while (lst->j < (*dgit) - lst->size)
	{
		if (list->wargs[0] == '-' && (*newarg)[lst->i - 1] != '0')
			(*newarg)[lst->i++] = '-';
		if (list->wargs[0] == '+' && (*newarg)[lst->i - 1] != '0')
			(*newarg)[lst->i++] = '+';
		(*newarg)[lst->i] = '0';
		lst->i++;
		lst->j++;
	}
	if (lst->i > 0)
		(*newarg)[lst->i] = '\0';
}

void	ft_wdgt_3(t_precs *lst, int *digittmp, wchar_t **newarg)
{
	while (lst->i < (*digittmp) - lst->size)
		(*newarg)[lst->i++] = ' ';
	lst->i--;
}

void	ft_wdgt_2(t_flags *list, t_precs *lst, int *digittmp, int *dgit)
{
	if (((list->wargs[0] == '-' || list->wargs[0] == '+') && dgit >= 0))
		lst->size -= 1;
	if (digittmp > dgit && lst->size > 0 && lst->size <= (*dgit) && dgit > 0
			&& list->wargs[0] != '-' && list->wargs[0] != '+')
		(*digittmp) = (*digittmp) - ((*dgit) - lst->size) + 1;
	else if ((*digittmp) > (*dgit) && (*digittmp) > lst->size && dgit > 0
			&& list->wargs[0] != '-' && list->wargs[0] != '+')
		digittmp += 1;
	else if ((list->wargs[0] == '-' || list->wargs[0] == '+')
			&& (*digittmp) > (*dgit) && (*dgit) > 0 && lst->size > 0 &&
			(*dgit) > lst->size)
		(*digittmp) -= lst->size;
	else
		(*digittmp) += 0;
}

int		ft_wdgt_1(t_flags *list, t_precs *lst, int *digittmp, int *dgit)
{
	(*digittmp) = ft_atoi((void *)lst->wtmp);
	ft_wstrdel(&lst->wtmp);
	if ((*digittmp) == 0 && (*dgit) == 0)
		return (0);
	lst->i = 0;
	lst->size = (int)ft_wstrlen(list->wargs);
	return (1);
}
