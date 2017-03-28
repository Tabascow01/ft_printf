/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dgt_nn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 05:40:34 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/29 01:21:39 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_dgt_6(t_flags *list, t_precs *lst, char **newarg)
{
	ft_strdel(&lst->tmp);
	list->args = ft_reallocf((*newarg), 0);
	if (list->space > 0)
		ft_spaceflag(list);
}

void	ft_dgt_7(t_flags *list, t_precs *lst, int *digit)
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

void	ft_dgt_8(t_flags *list, t_precs *lst, int *digittmp, int *digit)
{
	lst->i = 0;
	if ((*digittmp) > (*digit) && (*digit) <= lst->size)
		(*digittmp) -= (*digit);
	else if ((*digittmp) > (*digit) && (*digit) > lst->size && lst->size > 0)
		(*digittmp) -= (*digit) - lst->size;
	else if ((*digittmp) < (*digit) && (*digittmp) > lst->size && lst->size > 0)
		(*digittmp) -= lst->size;
	else if ((*digittmp) < (*digit) && (*digittmp) < lst->size &&
			(*digittmp) > 0)
		(*digittmp) -= (*digit);
	else
		(*digittmp) -= 0;
	lst->tmp = ft_strnew((*digittmp));
	while (lst->i < (*digittmp))
		lst->tmp[lst->i++] = ' ';
	list->args = ft_strjoin(lst->tmp, list->args);
	ft_strdel(&lst->tmp);
}
