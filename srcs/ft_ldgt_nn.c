/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldgt_nn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 02:27:59 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/29 03:16:33 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ldgt_8(t_flags *list, t_precs *lst, int *digittmp, int *digit)
{
	if ((*digittmp) > 0)
	{
		lst->i = 0;
		lst->tmpargs = ft_strnew((*digit));
		while (list->args[lst->i] && lst->i < (*digit))
			lst->i++;
		lst->tmp = &list->args[lst->i];
		lst->i = 0;
		while (lst->i < (*digit))
		{
			lst->tmpargs[lst->i] = list->args[lst->i];
			lst->i++;
		}
		lst->i = 0;
		if (list->args[0] != '\0')
			digittmp -= (*digit);
		lst->tmp = ft_strnew((*digittmp));
		while (lst->i < (*digittmp))
			lst->tmp[lst->i++] = ' ';
		list->args = ft_strjoin(lst->tmpargs, lst->tmp);
		ft_strdel(&lst->tmpargs);
		ft_strdel(&lst->tmp);
		lst->tmpargs = list->args;
		list->args = ft_strjoin(list->args, lst->tmp);
	}
}

void	ft_ldgt_7(t_flags *list, t_precs *lst, int *digit)
{
	if ((*digit) > 0)
	{
		lst->tmpargs = ft_strnew((*digit));
		while (list->args[lst->i] && lst->i < (*digit))
			lst->i++;
		lst->tmp = &list->args[lst->i];
		lst->i = 0;
		while (lst->i < (*digit))
		{
			lst->tmpargs[lst->i] = list->args[lst->i];
			lst->i++;
		}
		if (list->args[0] != '\0')
			ft_strdel(&list->args);
		list->args = ft_strjoin(lst->tmpargs, lst->tmp);
		ft_strdel(&lst->tmpargs);
	}
}

void	ft_ldgt_6(t_flags *list, t_precs *lst, char **newarg)
{
	if (list->args[0] == '-' || list->args[0] == '+')
	{
		list->args++;
		lst->tmpargs = ft_strjoin(lst->tmp, list->args);
		ft_strdel(&lst->tmp);
		list->args--;
		ft_strdel(&list->args);
		lst->tmp = (*newarg);
		(*newarg) = ft_strjoin(lst->tmpargs, lst->tmp);
		ft_strdel(&lst->tmpargs);
		ft_strdel(&lst->tmp);
	}
	else
	{
		lst->tmpargs = ft_strjoin(lst->tmp, list->args);
		ft_strdel(&list->args);
		ft_strdel(&lst->tmp);
		lst->tmp = (*newarg);
		(*newarg) = ft_strjoin(lst->tmpargs, lst->tmp);
		ft_strdel(&lst->tmpargs);
		ft_strdel(&lst->tmp);
	}
	list->args = ft_reallocf((*newarg), 0);
}
