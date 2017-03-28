/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldigitflag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 15:57:39 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/28 23:51:39 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_precs(t_flags *list, char *newarg, t_precs *lst, int digit)
{
	int		digittmp;

	digittmp = ft_atoi(lst->tmp);
	ft_strdel(&lst->tmp);
	lst->i = 0;
	lst->size = (int)ft_strlen(list->args);
	if (list->conv != 's')
	{
		if (list->args[0] == '-' || list->args[0] == '+')
			lst->size -= 1;
		if (digittmp > digit && (list->space > 0 || list->sign > 0))
			digittmp -= digit;
		if (digittmp > (digit - lst->size) + (int)ft_strlen(list->args))
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
		if (list->args[0] == '-' || list->args[0] == '+')
			lst->i = 0;
		else
			lst->i = 1;
		lst->j = 0;
		lst->tmp = ft_strnew(digit - lst->size);
		while (lst->i <= digit - lst->size)
		{
			if (list->args[0] == '-' && lst->j < 1)
				lst->tmp[lst->j++] = '-';
			else if (list->args[0] == '+' && lst->j < 1)
				lst->tmp[lst->j++] = '+';
			else
				lst->tmp[lst->j++] = '0';
			lst->i++;
		}
		if (lst->j >= 1)
			lst->tmp[lst->j] = '\0';
		if (list->args[0] == '-' || list->args[0] == '+')
		{
			list->args++;
			lst->tmpargs = ft_strjoin(lst->tmp, list->args);
			ft_strdel(&lst->tmp);
			list->args--;
			ft_strdel(&list->args);
			lst->tmp = newarg;
			newarg = ft_strjoin(lst->tmpargs, lst->tmp);
			ft_strdel(&lst->tmpargs);
			ft_strdel(&lst->tmp);
		}
		else
		{
			lst->tmpargs = ft_strjoin(lst->tmp, list->args);
			ft_strdel(&list->args);
			ft_strdel(&lst->tmp);
			lst->tmp = newarg;
			newarg = ft_strjoin(lst->tmpargs, lst->tmp);
			ft_strdel(&lst->tmpargs);
			ft_strdel(&lst->tmp);
		}
		list->args = ft_reallocf(newarg, 0);
		if (list->space > 0)
			ft_spaceflag(list);
	}
	else
	{
		if (digit > 0)
		{
			lst->tmpargs = ft_strnew(digit);
			while (list->args[lst->i] && lst->i < digit)
				lst->i++;
			lst->tmp = &list->args[lst->i];
			lst->i = 0;
			while (lst->i < digit)
			{
				lst->tmpargs[lst->i] = list->args[lst->i];
				lst->i++;
			}
			if (list->args[0] != '\0')
				ft_strdel(&list->args);
			list->args = ft_strjoin(lst->tmpargs, lst->tmp);
			ft_strdel(&lst->tmpargs);
		}
		if (digittmp > 0)
		{
			lst->i = 0;
			lst->tmpargs = ft_strnew(digit);
			while (list->args[lst->i] && lst->i < digit)
				lst->i++;
			lst->tmp = &list->args[lst->i];
			lst->i = 0;
			while (lst->i < digit)
			{
				lst->tmpargs[lst->i] = list->args[lst->i];
				lst->i++;
			}
			lst->i = 0;
			if (list->args[0] != '\0')
				digittmp -= digit;
			lst->tmp = ft_strnew(digittmp);
			while (lst->i < digittmp)
				lst->tmp[lst->i++] = ' ';
			list->args = ft_strjoin(lst->tmpargs, lst->tmp);
			ft_strdel(&lst->tmpargs);
			ft_strdel(&lst->tmp);
			lst->tmpargs = list->args;
			list->args = ft_strjoin(list->args, lst->tmp);
		}
	}
}

static void		ft_ldigit_n(t_flags *list, int *i, int *digit, char **newarg)
{
	if ((((*i) >= 0 && list->conv != 'p') || ((*i) > 0 && list->conv == 'p'))
			&& (*digit) < 13)
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
}
