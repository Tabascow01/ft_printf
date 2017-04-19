/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wldgt_nn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 04:42:31 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/29 04:48:32 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_wldgt_8(t_flags *list, t_precs *lst, int *digittmp, int *dgit)
{
	if ((*digittmp) > 0)
	{
		lst->i = 0;
		lst->wtmpargs = ft_wstrnew((*dgit));
		while (list->wargs[lst->i] && lst->i < (*dgit))
			lst->i++;
		lst->wtmp = &list->wargs[lst->i];
		lst->i = 0;
		while (lst->i < (*dgit))
		{
			lst->wtmpargs[lst->i] = list->args[lst->i];
			lst->i++;
		}
		lst->i = 0;
		if (list->args[0] != '\0')
			(*digittmp) -= (*dgit);
		lst->wtmp = ft_wstrnew((*digittmp));
		while (lst->i < (*digittmp))
			lst->wtmp[lst->i++] = ' ';
		list->wargs = ft_wstrjoin(lst->wtmpargs, lst->wtmp);
		ft_wstrdel(&lst->wtmpargs);
		ft_wstrdel(&lst->wtmp);
		lst->wtmpargs = list->wargs;
		list->wargs = ft_wstrjoin(list->wargs, lst->wtmp);
	}
}

void	ft_wldgt_7(t_flags *list, t_precs *lst, int *dgit)
{
	if ((*dgit) > 0)
	{
		lst->wtmpargs = ft_wstrnew((*dgit));
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
}

void	ft_wldgt_6(t_flags *list, t_precs *lst, wchar_t **newarg)
{
	if (list->wargs[0] == '-' || list->wargs[0] == '+')
	{
		list->wargs++;
		lst->wtmpargs = ft_wstrjoin(lst->wtmp, list->wargs);
		ft_wstrdel(&lst->wtmp);
		list->wargs--;
		ft_wstrdel(&list->wargs);
		lst->wtmp = (*newarg);
		(*newarg) = ft_wstrjoin(lst->wtmpargs, lst->wtmp);
		ft_wstrdel(&lst->wtmpargs);
		ft_wstrdel(&lst->wtmp);
	}
	else
	{
		lst->wtmpargs = ft_wstrjoin(lst->wtmp, list->wargs);
		ft_wstrdel(&list->wargs);
		ft_wstrdel(&lst->wtmp);
		lst->wtmp = (*newarg);
		(*newarg) = ft_wstrjoin(lst->wtmpargs, lst->wtmp);
		ft_wstrdel(&lst->wtmpargs);
		ft_wstrdel(&lst->wtmp);
	}
}
