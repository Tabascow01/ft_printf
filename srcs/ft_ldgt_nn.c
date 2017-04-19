/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldgt_nn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 02:27:59 by mchemakh          #+#    #+#             */
/*   Updated: 2017/04/18 14:11:26 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ldgt_8(t_flags *list, t_precs *lst)
{
	lst->i = 0;
	lst->tmpargs = ft_strnew(list->dig2);
	while (list->args[lst->i] && lst->i < list->dig2)
		lst->i++;
	lst->tmp = &list->args[lst->i];
	lst->i = 0;
	while (lst->i < list->dig2)
	{
		lst->tmpargs[lst->i] = list->args[lst->i];
		lst->i++;
	}
	lst->i = 0;
	if (list->args[0] != '\0')
		list->dig1 -= list->dig2;
	lst->tmp = ft_strnew(list->dig1);
	while (lst->i < list->dig1)
		lst->tmp[lst->i++] = ' ';
	list->args = ft_strjoin(lst->tmpargs, lst->tmp);
	ft_strdel(&lst->tmpargs);
	ft_strdel(&lst->tmp);
	lst->tmpargs = ft_reallocf(list->args, ft_strlen(list->args));
	list->args = ft_strjoin(lst->tmpargs, lst->tmp);
	list->args = ft_reallocf(list->args, ft_strlen(list->args));
}

void	ft_ldgt_7(t_flags *list, t_precs *lst)
{
	char	*del;

	del = list->args;
	lst->tmpargs = ft_strnew(list->dig2);
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
	ft_strdel(&lst->tmpargs);
}
