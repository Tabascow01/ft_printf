/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldigitflag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 15:57:39 by mchemakh          #+#    #+#             */
/*   Updated: 2017/05/09 22:39:52 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_wldigit_n(t_flags *list, int *size, int *i, wchar_t **newarg)
{
	(*newarg) = NULL;
	(*i) = 0;
	(*size) = (int)ft_wstrlen(list->wargs);
	if (list->wargs == NULL)
		(*size) += 1;
}

static void		ft_wld_nn(t_flags *lst, int *i, wchar_t **newarg, wchar_t **tmp)
{
	if ((*i) > 0)
		(*newarg)[(*i)] = '\0';
	(*tmp) = ft_wstrjoin(lst->wargs, (*newarg));
	ft_wstrdel(&lst->wargs);
	lst->wargs = (*tmp);
}

void			ft_wldigitflag(t_flags *list)
{
	wchar_t		*newarg;
	int			digit;
	t_precs		*lst;

	lst = NULL;
	lst = ft_init_precs(lst);
	ft_wldigit_n(list, &lst->size, &lst->i, &newarg);
	digit = ft_atoi(list->digit);
	newarg = ft_wstrnew(digit - lst->size);
	while (lst->i < (digit - lst->size))
		newarg[lst->i++] = ' ';
	ft_wld_nn(list, &lst->i, &newarg, &lst->wtmp);
	free(lst);
}
