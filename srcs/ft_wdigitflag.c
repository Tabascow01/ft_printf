/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wdigitflag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 00:30:03 by mchemakh          #+#    #+#             */
/*   Updated: 2017/05/09 22:39:45 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_wdigit_n(t_flags *list, int *size)
{
	if ((int)ft_wstrlen(list->wargs) == 0 && (list->conv != 'S'
		|| list->noconv > 0))
	{
		if (list->noconv > 0)
			list->size += 1;
		(*size) += 1;
	}
}

static void		ft_wd_nn(t_flags *list, int *i, wchar_t **newarg, wchar_t **tmp)
{
	if ((*i) > 0)
		(*newarg)[(*i)] = '\0';
	(*tmp) = ft_wstrjoin((*newarg), list->wargs);
	ft_wstrdel(&list->wargs);
	list->wargs = (*tmp);
}

void			ft_wdigitflag(t_flags *list)
{
	wchar_t	*newarg;
	int		digit;
	t_precs	*lst;

	lst = NULL;
	lst = ft_init_precs(lst);
	newarg = NULL;
	lst->size = (int)ft_wstrlen(list->wargs);
	ft_wdigit_n(list, &lst->size);
	digit = ft_atoi(list->digit);
	newarg = ft_wstrnew(digit - lst->size + 1);
	while (lst->i < (digit - lst->size))
		newarg[lst->i++] = ' ';
	ft_wd_nn(list, &lst->i, &newarg, &lst->wtmp);
	free(lst);
}
