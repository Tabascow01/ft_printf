/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wdgt_nn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 04:15:04 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/29 04:27:17 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_wdgt_7(t_flags *list, t_precs *lst, int *digittmp, int *dgit)
{
	if ((*digittmp) > 0)
	{
		lst->i = 0;
		if ((*digittmp) > (*dgit) && (*dgit) <= lst->size)
			(*digittmp) -= (*dgit);
		else if ((*digittmp) > (*dgit) && (*dgit) > lst->size && lst->size > 0)
			(*digittmp) -= (*dgit) - lst->size;
		else if ((*digittmp) < (*dgit) && (*digittmp) > lst->size
				&& lst->size > 0)
			(*digittmp) -= lst->size;
		else if ((*digittmp) < (*dgit) && (*digittmp) < lst->size
				&& (*digittmp) > 0)
			(*digittmp) -= (*dgit);
		else
			(*digittmp) -= 0;
		lst->wtmp = ft_wstrnew((*digittmp) + 1);
		while (lst->i < (*digittmp))
			lst->wtmp[lst->i++] = ' ';
		list->wargs = ft_wstrjoin(lst->wtmp, list->wargs);
		ft_wstrdel(&lst->wtmp);
	}
}

void	ft_wdgt_6(t_flags *list, t_precs *lst, int *dgit)
{
	if (dgit > 0)
	{
		lst->wtmpargs = ft_wstrnew((*dgit) + 1);
		while (list->wargs[lst->i] && lst->i < (*dgit))
			lst->i++;
		lst->wtmp = &list->wargs[lst->i];
		lst->i = 0;
		while (lst->i < (*dgit))
		{
			lst->wtmpargs[lst->i] = list->wargs[lst->i];
			lst->i++;
		}
		if (list->wargs[0] != '\0')
			ft_wstrdel(&list->wargs);
		list->wargs = ft_wstrjoin(lst->wtmpargs, lst->wtmp);
		ft_wstrdel(&lst->wtmpargs);
	}
	else
		ft_bzero(list->wargs, lst->size);
}
