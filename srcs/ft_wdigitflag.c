/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wdigitflag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 00:30:03 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/29 00:03:07 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_precs(t_flags *list, wchar_t *newarg, t_precs *lst, int dgit)
{
	int		digittmp;

	digittmp = ft_atoi((void *)lst->wtmp);
	ft_wstrdel(&lst->wtmp);
	if (digittmp == 0 && dgit == 0)
		return ;
	lst->i = 0;
	lst->size = (int)ft_wstrlen(list->wargs);
	if (list->conv != 'S')
	{
		if (((list->wargs[0] == '-' || list->wargs[0] == '+') && dgit >= 0))
			lst->size -= 1;
		if (digittmp > dgit && lst->size > 0 && lst->size <= dgit && dgit > 0
				&& list->wargs[0] != '-' && list->wargs[0] != '+')
			digittmp = digittmp - (dgit - lst->size) + 1;
		else if (digittmp > dgit && digittmp > lst->size && dgit > 0
				&& list->wargs[0] != '-' && list->wargs[0] != '+')
			digittmp += 1;
		else if ((list->wargs[0] == '-' || list->wargs[0] == '+')
				&& digittmp > dgit && dgit > 0 && lst->size > 0 &&
				dgit > lst->size)
			digittmp -= lst->size;
		else
			digittmp += 0;
		if (digittmp > (int)ft_wstrlen(list->wargs) + dgit - lst->size)
		{
			while (lst->i < digittmp - lst->size)
				newarg[lst->i++] = ' ';
			lst->i--;
		}
		lst->j = 0;
		while (lst->j < dgit - lst->size)
		{
			if (list->wargs[0] == '-' && newarg[lst->i - 1] != '0')
				newarg[lst->i++] = '-';
			if (list->wargs[0] == '+' && newarg[lst->i - 1] != '0')
				newarg[lst->i++] = '+';
			newarg[lst->i] = '0';
			lst->i++;
			lst->j++;
		}
		if (lst->i > 0)
			newarg[lst->i] = '\0';
		if (dgit < lst->size && (list->wargs[0] == '-' || list->wargs[0] == '+')
				&& digittmp > lst->size)
			newarg[lst->i] = list->wargs[0];
		if ((list->wargs[0] == '-' || list->wargs[0] == '+') && lst->i > 0)
		{
			list->wargs++;
			lst->wtmp = newarg;
			newarg = ft_wstrjoin(newarg, list->wargs);
			ft_wstrdel(&lst->wtmp);
			list->wargs--;
			lst->wtmp = list->wargs;
		}
		else
		{
			lst->wtmpargs = newarg;
			if (digittmp > 0 && list->wargs[0] == '\0')
				list->wargs[0] = ' ';
			lst->wtmp = list->wargs;
			newarg = ft_wstrjoin(lst->wtmpargs, list->wargs);
			ft_wstrdel(&lst->wtmpargs);
		}
		ft_wstrdel(&lst->wtmp);
		list->wargs = ft_wreallocf(newarg, 0);
		if (list->space > 0)
			ft_spaceflag(list);
	}
	else
	{
		if (dgit > 0)
		{
			lst->wtmpargs = ft_wstrnew(dgit + 1);
			while (list->wargs[lst->i] && lst->i < dgit)
				lst->i++;
			lst->wtmp = &list->wargs[lst->i];
			lst->i = 0;
			while (lst->i < dgit)
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
		if (digittmp > 0)
		{
			lst->i = 0;
			if (digittmp > dgit && dgit <= lst->size)
				digittmp -= dgit;
			else if (digittmp > dgit && dgit > lst->size && lst->size > 0)
				digittmp -= dgit - lst->size;
			else if (digittmp < dgit && digittmp > lst->size && lst->size > 0)
				digittmp -= lst->size;
			else if (digittmp < dgit && digittmp < lst->size && digittmp > 0)
				digittmp -= dgit;
			else
				digittmp -= 0;
			lst->wtmp = ft_wstrnew(digittmp + 1);
			while (lst->i < digittmp)
				lst->wtmp[lst->i++] = ' ';
			list->wargs = ft_wstrjoin(lst->wtmp, list->wargs);
			ft_wstrdel(&lst->wtmp);
		}
	}
}

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
	ft_wstrdel((*&newarg));
	list->wargs = ft_wreallocf((*tmp), 0);
}

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

void			ft_wdigitflag(t_flags *list)
{
	wchar_t	*newarg;
	int		digit;
	t_precs	*lst;

	lst = NULL;
	lst = ft_init_precs(lst);
	newarg = NULL;
	lst->size = (int)ft_wstrlen(list->wargs);
	if (list->precision == 0)
	{
		ft_wdigit_n(list, &lst->size);
		digit = ft_atoi(list->digit);
		newarg = ft_wstrnew(digit - lst->size + 1);
		while (lst->i < (digit - lst->size))
			newarg[lst->i++] = ' ';
		ft_wd_nn(list, &lst->i, &newarg, &lst->wtmp);
	}
	else
	{
		ft_wd_nnn(list, &lst->i, &lst->wtmp, &digit);
		newarg = ft_wstrnew(ft_atoi((void *)lst->wtmp) + digit -
				((int)ft_wstrlen(list->wargs) + 1));
		ft_precs(list, newarg, lst, digit);
	}
}
