/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldigitflag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 15:57:39 by mchemakh          #+#    #+#             */
/*   Updated: 2017/04/10 04:40:53 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void		ft_precs(t_flags *list, char *newarg, t_precs *lst, int digit)
{
	int		digittmp;

	ft_ldgt_1(list, lst, &digittmp, &digit);
	if (list->conv != 's')
	{
		ft_ldgt_2(list, lst, &digittmp, &digit);
		if (digittmp > (int)ft_strlen(list->args) + digit - lst->size)
			ft_ldgt_3(lst, &digittmp, &newarg, &digit);
		ft_ldgt_5(list, lst, &digit, &newarg);
		ft_ldgt_6(list, lst, &newarg);
		if (list->space > 0)
			ft_spaceflag(list);
	}
	else
	{
		if (digit > 0)
			ft_ldgt_7(list, lst, &digit);
		if (digittmp > 0)
			ft_ldgt_8(list, lst, &digittmp, &digit);
	}
}

static void		ft_ldigit_n(t_flags *list, int *i, int *digit, char **newarg)
{
	if ((((*i) >= 0 && list->conv != 'p') || (((*i) > 0 && list->conv == 'p'
						&& (*digit) < 13))) && (int)ft_strlen((*newarg)) > 0)
		(*newarg)[(*i)] = '\0';
	else if (list->conv == 'p' && (*digit) > 12)
		(*newarg)[(*i)] = '\0';
}

static void		ft_ldigit_nn(t_flags *list, char **tmp, char **newarg)
{
	(*tmp) = ft_strjoin(list->args, (*newarg));
	ft_strdel((*&newarg));
	ft_strdel(&list->args);
	list->args = ft_reallocf((*tmp), 0);
}

static void		ft_ldigit_nnn(t_flags *list, int *i, char **tmp)
{
	while (list->digit[(*i)] && list->digit[(*i)] != '.')
		(*i)++;
	(*tmp) = ft_strnew((*i));
	(*i) = 0;
	while (list->digit[(*i)] && list->digit[(*i)] != '.')
	{
		(*tmp)[(*i)] = list->digit[(*i)];
		(*i)++;
	}
}

void			ft_ldigitflag(t_flags *list)
{
	char	*newarg;
	int		digit;
	t_precs	*lst;

	lst = NULL;
	lst = ft_init_precs(lst);
	ft_ldigit_nnnn(list, &lst->size, &lst->i, &newarg);
	if (list->args == NULL)
		lst->size += 1;
	if (list->precision == 0)
	{
		ft_ldigit_nnnnn(list, &newarg, &digit, lst);
		while (lst->i < (digit - lst->size))
			newarg[lst->i++] = ' ';
		ft_ldigit_n(list, &lst->i, &digit, &newarg);
		ft_ldigit_nn(list, &lst->tmp, &newarg);
	}
	else
	{
		ft_ldigit_nnn(list, &lst->i, &lst->tmp);
		digit = ft_atoi(&list->digit[lst->i + 1]);
		newarg = ft_strnew(ft_atoi(lst->tmp) + (digit -
					(int)ft_strlen(list->args)));
		ft_precs(list, newarg, lst, digit);
	}
	free(lst);
}
