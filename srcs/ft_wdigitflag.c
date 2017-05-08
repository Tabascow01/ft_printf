/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wdigitflag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 00:30:03 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/29 04:20:16 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
static void		ft_precs(t_flags *list, wchar_t *newarg, t_precs *lst, int dgit)
{
	int		digittmp;

	if (ft_wdgt_1(list, lst, &digittmp, &dgit) == 0)
		return ;
	if (list->conv != 'S')
	{
		ft_wdgt_2(list, lst, &digittmp, &dgit);
		if (digittmp > (int)ft_wstrlen(list->wargs) + dgit - lst->size)
			ft_wdgt_3(lst, &digittmp, &newarg);
		ft_wdgt_4(list, lst, &dgit, &newarg);
		if (dgit < lst->size && (list->wargs[0] == '-' || list->wargs[0] == '+')
				&& digittmp > lst->size)
			newarg[lst->i] = list->wargs[0];
		ft_wdgt_5(list, lst, &digittmp, &newarg);
		ft_wstrdel(&lst->wtmp);
		list->wargs = ft_wreallocf(newarg, 0);
		if (list->space > 0)
			ft_spaceflag(list);
	}
	else
	{
		ft_wdgt_6(list, lst, &dgit);
		ft_wdgt_7(list, lst, &digittmp, &dgit);
	}
}
*/
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
	//ft_wstrdel((*&newarg));
	list->wargs = ft_wreallocf((*tmp), 0);
}
/*
static void		ft_wd_nnn(t_flags *list, int *i, wchar_t **tmp, int *digit)
{
	while (list->digit[(*i)] && list->digit[(*i)] != '.')
		(*i)++;
	(*tmp) = ft_wstrnew(1);
	(*i) = 0;
	while (list->digit[(*i)] && list->digit[(*i)] != '.')
	{
		(*tmp)[(*i)] = list->digit[(*i)];
		(*i)++;
	}
	(*digit) = ft_atoi(&list->digit[(*i) + 1]);
}
*/
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
