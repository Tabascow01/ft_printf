/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldigitflag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 15:57:39 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/29 00:14:23 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_precs(t_flags *list, wchar_t *newarg, t_precs *lst, int dgit)
{
	int			digittmp;

	digittmp = ft_atoi((void *)lst->wtmp);
	ft_wstrdel(&lst->wtmp);
	lst->i = 0;
	lst->size = (int)ft_wstrlen(list->wargs);
	if (list->conv != 'S')
	{
		if (list->wargs[0] == '-' || list->wargs[0] == '+')
			lst->size -= 1;
		if (digittmp > dgit && (list->space > 0 || list->sign > 0))
			digittmp -= dgit;
		if (digittmp > (dgit - lst->size) + (int)ft_wstrlen(list->wargs))
		{
			while (lst->i < digittmp - lst->size)
				newarg[lst->i++] = ' ';
			lst->i--;
		}
		else if (list->sign > 0)
		{
			while (lst->i < digittmp)
				newarg[lst->i++] = ' ';
			lst->i--;
		}
		if (lst->i > 0)
			newarg[lst->i] = '\0';
		if (list->wargs[0] == '-' || list->wargs[0] == '+')
			lst->i = 0;
		else
			lst->i = 1;
		lst->j = 0;
		lst->wtmp = ft_wstrnew(dgit - lst->size);
		while (lst->i <= dgit - lst->size)
		{
			if (list->wargs[0] == '-' && lst->j < 1)
				lst->wtmp[lst->j++] = '-';
			else if (list->wargs[0] == '+' && lst->j < 1)
				lst->wtmp[lst->j++] = '+';
			else
				lst->wtmp[lst->j++] = '0';
			lst->i++;
		}
		if (lst->j >= 1)
			lst->wtmp[lst->j] = '\0';
		if (list->wargs[0] == '-' || list->wargs[0] == '+')
		{
			list->wargs++;
			lst->wtmpargs = ft_wstrjoin(lst->wtmp, list->wargs);
			ft_wstrdel(&lst->wtmp);
			list->wargs--;
			ft_wstrdel(&list->wargs);
			lst->wtmp = newarg;
			newarg = ft_wstrjoin(lst->wtmpargs, lst->wtmp);
			ft_wstrdel(&lst->wtmpargs);
			ft_wstrdel(&lst->wtmp);
		}
		else
		{
			lst->wtmpargs = ft_wstrjoin(lst->wtmp, list->wargs);
			ft_wstrdel(&list->wargs);
			ft_wstrdel(&lst->wtmp);
			lst->wtmp = newarg;
			newarg = ft_wstrjoin(lst->wtmpargs, lst->wtmp);
			ft_wstrdel(&lst->wtmpargs);
			ft_wstrdel(&lst->wtmp);
		}
		list->wargs = ft_wreallocf(newarg, 0);
		if (list->space > 0)
			ft_spaceflag(list);
	}
	else
	{
		if (dgit > 0)
		{
			lst->wtmpargs = ft_wstrnew(dgit);
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
		if (digittmp > 0)
		{
			lst->i = 0;
			lst->wtmpargs = ft_wstrnew(dgit);
			while (list->wargs[lst->i] && lst->i < dgit)
				lst->i++;
			lst->wtmp = &list->wargs[lst->i];
			lst->i = 0;
			while (lst->i < dgit)
			{
				lst->wtmpargs[lst->i] = list->args[lst->i];
				lst->i++;
			}
			lst->i = 0;
			if (list->args[0] != '\0')
				digittmp -= dgit;
			lst->wtmp = ft_wstrnew(digittmp);
			while (lst->i < digittmp)
				lst->wtmp[lst->i++] = ' ';
			list->wargs = ft_wstrjoin(lst->wtmpargs, lst->wtmp);
			ft_wstrdel(&lst->wtmpargs);
			ft_wstrdel(&lst->wtmp);
			lst->wtmpargs = list->wargs;
			list->wargs = ft_wstrjoin(list->wargs, lst->wtmp);
		}
	}
}

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
	ft_wstrdel((*&newarg));
	lst->wargs = ft_wreallocf((*tmp), 0);
}

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

void			ft_wldigitflag(t_flags *list)
{
	wchar_t		*newarg;
	int			digit;
	t_precs		*lst;

	lst = NULL;
	lst = ft_init_precs(lst);
	ft_wldigit_n(list, &lst->size, &lst->i, &newarg);
	if (list->precision == 0)
	{
		digit = ft_atoi(list->digit);
		newarg = ft_wstrnew(digit - lst->size);
		while (lst->i < (digit - lst->size))
			newarg[lst->i++] = ' ';
		ft_wld_nn(list, &lst->i, &newarg, &lst->wtmp);
	}
	else
	{
		ft_wldigit_nnn(list, &lst->i, &lst->wtmp);
		digit = ft_atoi(&list->digit[lst->i + 1]);
		newarg = ft_wstrnew(ft_atoi((void *)lst->wtmp) + (digit -
					(int)ft_wstrlen(list->wargs)));
		ft_precs(list, newarg, lst, digit);
	}
}
