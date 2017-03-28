/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digitflag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 16:38:38 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/28 23:24:01 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_precs(t_flags *list, char *newarg, t_precs *lst, int digit)
{
	int		digittmp;

	digittmp = ft_atoi(lst->tmp);
	ft_strdel(&lst->tmp);
	if (digittmp == 0 && digit == 0)
		return ;
	lst->i = 0;
	lst->size = (int)ft_strlen(list->args);
	if (list->conv != 's')
	{
		if (((list->args[0] == '-' || list->args[0] == '+') && digit >= 0)
				|| (digittmp > digit && list->conv == 'p'))
			lst->size -= 1;
		if (digittmp > digit && (list->space > 0 || list->sign > 0)
				&& digit > 0 && list->conv != 'p')
			digittmp = digittmp - digit + lst->size;
		else if (digittmp > digit && lst->size > 0 && lst->size <= digit &&
				digit > 0
				&& list->conv != 'p' && list->args[0] != '-'
				&& list->args[0] != '+')
			digittmp = digittmp - (digit - lst->size) + 1;
		else if (digittmp > digit && digittmp > lst->size && digit > 0
				&& list->conv != 'p' && list->args[0] != '-'
				&& list->args[0] != '+')
			digittmp += 1;
		else if ((list->args[0] == '-' || list->args[0] == '+')
				&& digittmp > digit && digit > 0 && lst->size > 0 &&
				digit > lst->size)
			digittmp -= lst->size;
		else
			digittmp += 0;
		if (digittmp > (int)ft_strlen(list->args) + digit - lst->size)
		{
			while (lst->i < digittmp - lst->size)
				newarg[lst->i++] = ' ';
			lst->i--;
		}
		lst->j = 0;
		while (lst->j < digit - lst->size)
		{
			if (list->args[0] == '-' && newarg[lst->i - 1] != '0')
				newarg[lst->i++] = '-';
			if (list->args[0] == '+' && newarg[lst->i - 1] != '0')
				newarg[lst->i++] = '+';
			newarg[lst->i] = '0';
			lst->i++;
			lst->j++;
		}
		if (lst->i > 0)
			newarg[lst->i] = '\0';
		if (digit < lst->size && (list->args[0] == '-' || list->args[0] == '+')
				&& digittmp > lst->size)
			newarg[lst->i] = list->args[0];
		if ((list->args[0] == '-' || list->args[0] == '+') && lst->i > 0)
		{
			list->args++;
			lst->tmp = newarg;
			newarg = ft_strjoin(newarg, list->args);
			ft_strdel(&lst->tmp);
			list->args--;
			lst->tmp = list->args;
		}
		else
		{
			lst->tmpargs = newarg;
			if (digittmp > 0 && list->args[0] == '\0')
				list->args[0] = ' ';
			lst->tmp = list->args;
			newarg = ft_strjoin(lst->tmpargs, list->args);
			ft_strdel(&lst->tmpargs);
		}
		ft_strdel(&lst->tmp);
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
		else
			ft_bzero(list->args, lst->size);
		if (digittmp > 0)
		{
			lst->i = 0;
			if (digittmp > digit && digit <= lst->size)
				digittmp -= digit;
			else if (digittmp > digit && digit > lst->size && lst->size > 0)
				digittmp -= digit - lst->size;
			else if (digittmp < digit && digittmp > lst->size && lst->size > 0)
				digittmp -= lst->size;
			else if (digittmp < digit && digittmp < lst->size && digittmp > 0)
				digittmp -= digit;
			else
				digittmp -= 0;
			lst->tmp = ft_strnew(digittmp);
			while (lst->i < digittmp)
				lst->tmp[lst->i++] = ' ';
			list->args = ft_strjoin(lst->tmp, list->args);
			ft_strdel(&lst->tmp);
		}
	}
}

static void		ft_digit_n(t_flags *list, int *size, int *digit, char **newarg)
{
	if ((int)ft_strlen(list->args) == 0 && (list->conv != 's'
				|| list->noconv > 0))
	{
		if (list->noconv > 0)
			list->size += 1;
		(*size) += 1;
	}
	(*digit) = ft_atoi(list->digit);
	(*newarg) = ft_strnew((*digit) - (*size));
}

static void		ft_digit_nn(t_flags *list, int *i, char **tmp)
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

static void		ft_digit_nnn(t_flags *list, int *i, char **newarg, char **tmp)
{
	if ((*i) >= 0 && list->conv != 'u')
		(*newarg)[(*i)] = '\0';
	else if ((*i) > 0)
		(*newarg)[(*i)] = '\0';
	(*tmp) = ft_strjoin((*newarg), list->args);
	ft_strdel((*&newarg));
	ft_strdel(&list->args);
	list->args = ft_reallocf((*tmp), 0);
}

void			ft_digitflag(t_flags *list)
{
	char	*newarg;
	t_precs	*lst;
	int		digit;

	newarg = NULL;
	lst = NULL;
	lst = ft_init_precs(lst);
	lst->size = (int)ft_strlen(list->args);
	if (list->precision == 0)
	{
		ft_digit_n(list, &lst->size, &digit, &newarg);
		while (lst->i < (digit - lst->size))
			newarg[lst->i++] = ' ';
		ft_digit_nnn(list, &lst->i, &newarg, &lst->tmp);
	}
	else
	{
		ft_digit_nn(list, &lst->i, &lst->tmp);
		digit = ft_atoi(&list->digit[lst->i + 1]);
		newarg = ft_strnew(ft_atoi(lst->tmp) + digit -
				((int)ft_strlen(list->args)));
		ft_precs(list, newarg, lst, digit);
	}
}
