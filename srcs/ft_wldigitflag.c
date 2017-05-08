/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldigitflag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 15:57:39 by mchemakh          #+#    #+#             */
/*   Updated: 2017/05/07 22:54:35 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
static void		ft_precs(t_flags *list, wchar_t *newarg, t_precs *lst, int dgit)
{
	int		digittmp;

	ft_wldgt_1(list, lst, &digittmp);
	if (list->conv != 'S')
	{
		ft_wldgt_2(list, lst, &digittmp, &dgit);
		if (digittmp > (dgit - lst->size) + (int)ft_wstrlen(list->wargs))
			ft_wldgt_3(lst, &digittmp, &newarg);
		else if (list->sign > 0)
			ft_wldgt_4(lst, &digittmp, &newarg);
		if (lst->i > 0)
			newarg[lst->i] = '\0';
		ft_wldgt_5(list, lst, &dgit);
		ft_wldgt_6(list, lst, &newarg);
		list->wargs = ft_wreallocf(newarg, 0);
		if (list->space > 0)
			ft_spaceflag(list);
	}
	else
	{
		ft_wldgt_7(list, lst, &dgit);
		ft_wldgt_8(list, lst, &digittmp, &dgit);
	}
}
*/
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
		(*newarg)[(*i)] = 0;
	(*tmp) = ft_wstrjoin(lst->wargs, (*newarg));
//	ft_wstrdel((*&newarg));
	lst->wargs = ft_wreallocf((*tmp), 0);
}
/*
static void		ft_wldigit_nnn(t_flags *list, int *i, wchar_t **tmp)
{
	while (list->digit[(*i)] && list->digit[(*i)] != '.')
		(*i)++;
	(*tmp) = ft_wstrnew((*i));
	(*i) = 0;
	while (list->digit[(*i)] && list->digit[(*i)] != '.')
	{
		(*tmp)[(*i)] = list->digit[(*i)];
		(*i)++;
	}
}
*/
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
