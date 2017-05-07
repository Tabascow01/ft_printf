/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dgt_nn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 05:40:34 by mchemakh          #+#    #+#             */
/*   Updated: 2017/05/07 21:46:38 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_dgt_7(t_flags *list, t_precs *lst)
{
	char	*del;

	del = list->args;
	lst->tmpargs = ft_strnew(list->dig2);
	if (list->args != NULL)
	{
		while (list->args[lst->i] && lst->i < list->dig2)
			lst->i++;
		lst->tmp = &list->args[lst->i];
		lst->i = 0;
		while (lst->i < list->dig2)
		{
			lst->tmpargs[lst->i] = list->args[lst->i];
			lst->i++;
		}
		ft_strdel(&del);
		list->args = ft_strjoin(lst->tmpargs, lst->tmp);
	}
	ft_strdel(&lst->tmpargs);
}

void	ft_dgt_8(t_flags *list, t_precs *lst)
{
	lst->i = 0;
	if (list->dig1 > list->dig2 && list->dig2 <= lst->size)
		list->dig1 -= list->dig2;
	else if (list->dig1 > list->dig2 && list->dig2 > lst->size && lst->size > 0)
		list->dig1 -= list->dig2 - lst->size;
	else if (list->dig1 < list->dig2 && list->dig1 > lst->size && lst->size > 0)
		list->dig1 -= lst->size;
	else if (list->dig1 < list->dig2 && list->dig1 < lst->size &&
			list->dig1 > 0)
		list->dig1 -= list->dig2;
	else
		list->dig1 -= 0;
	lst->tmp = ft_strnew(list->dig1);
	while (lst->i < list->dig1)
		lst->tmp[lst->i++] = ' ';
	list->args = ft_strjoin(lst->tmp, list->args);
	ft_strdel(&lst->tmp);
}

void	ft_dgt_5_n(t_flags *list, t_precs *lst, int *a)
{
	*a = 0;
	if ((list->args[0] == '-' || list->args[0] == '+') && lst->i > 0
			&& list->dig2 > lst->size)
	{
		list->args++;
		*a += 1;
	}
}

void	ft_dgt_nnn(t_flags *list, t_precs *lst, char **newarg)
{
	if (list->conv != 's')
	{
		if (list->dig1 > list->dig2 && list->dig1 > lst->size)
			(*newarg) = ft_strnew(list->dig1);
		else if (list->dig2 > list->dig1 && list->dig2 > lst->size)
			(*newarg) = ft_strnew(list->dig2);
		else
			(*newarg) = ft_strnew(list->dig1 + list->dig2);
	}
}
