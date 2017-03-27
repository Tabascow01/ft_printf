/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldigitflag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 15:57:39 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/27 04:12:56 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_precs(t_flags *list, char *newarg, char *fdigit, int digit)
{
	char	*tmp;
	char	*tmpargs;
	int		i;
	int		j;
	int		size;
	int		digittmp;

	digittmp = ft_atoi(fdigit);
	ft_strdel(&fdigit);
	i = 0;
	size = (int)ft_strlen(list->args);
	if (list->conv != 's')
	{
		if (list->args[0] == '-' || list->args[0] == '+')
			size -= 1;
		if (digittmp > digit && (list->space > 0 || list->sign > 0))
			digittmp -= digit;
		if (digittmp > (digit - size) + (int)ft_strlen(list->args))
		{
			while (i < digittmp - size)
				newarg[i++] = ' ';
			i--;
		}
		else if (list->sign > 0)
		{
			while (i < digittmp)
				newarg[i++] = ' ';
			i--;
		}
		if (i > 0)
			newarg[i] = '\0';
		if (list->args[0] == '-' || list->args[0] == '+')
			i = 0;
		else
			i = 1;
		j = 0;
		tmp = ft_strnew(digit - size);
		while (i <= digit - size)
		{
			if (list->args[0] == '-' && j < 1)
				tmp[j++] = '-';
			else if (list->args[0] == '+' && j < 1)
				tmp[j++] = '+';
			else
				tmp[j++] = '0';
			i++;
		}
		if (j >= 1)
			tmp[j] = '\0';
		if (list->args[0] == '-' || list->args[0] == '+')
		{
			list->args++;
			tmpargs = ft_strjoin(tmp, list->args);
			ft_strdel(&tmp);
			list->args--;
			ft_strdel(&list->args);
			tmp = newarg;
			newarg = ft_strjoin(tmpargs, tmp);
			ft_strdel(&tmpargs);
			ft_strdel(&tmp);
		}
		else
		{
			tmpargs = ft_strjoin(tmp, list->args);
			ft_strdel(&list->args);
			ft_strdel(&tmp);
			tmp = newarg;
			newarg = ft_strjoin(tmpargs, tmp);
			ft_strdel(&tmpargs);
			ft_strdel(&tmp);
		}
		list->args = ft_reallocf(newarg, 0);
		if (list->space > 0)
			ft_spaceflag(list);
	}
	else
	{
		if (digit > 0)
		{
			tmpargs = ft_strnew(digit);
			while (list->args[i] && i < digit)
				i++;
			tmp = &list->args[i];
			i = 0;
			while (i < digit)
			{
				tmpargs[i] = list->args[i];
				i++;
			}
			if (list->args[0] != '\0')
				ft_strdel(&list->args);
			list->args = ft_strjoin(tmpargs, tmp);
			ft_strdel(&tmpargs);
		}
		if (digittmp > 0)
		{
			i = 0;
			tmpargs = ft_strnew(digit);
			while (list->args[i] && i < digit)
				i++;
			tmp = &list->args[i];
			i = 0;
			while (i < digit)
			{
				tmpargs[i] = list->args[i];
				i++;
			}
			i = 0;
			if (list->args[0] != '\0')
				digittmp -= digit;
			fdigit = ft_strnew(digittmp);
			while (i < digittmp)
				fdigit[i++] = ' ';
			list->args = ft_strjoin(tmpargs, fdigit);
			ft_strdel(&tmpargs);
			ft_strdel(&fdigit);
			tmpargs = list->args;
			list->args = ft_strjoin(list->args, tmp);
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
	char	*tmp;
	int		digit;
	int		i;
	int		size;

	ft_ldigit_nnnn(list, &size, &i, &newarg);
	if (list->args == NULL)
		size += 1;
	if (list->precision == 0)
	{
		digit = ft_atoi(list->digit);
		newarg = ft_strnew(digit - size);
		while (i < (digit - size))
			newarg[i++] = ' ';
		ft_ldigit_n(list, &i, &digit, &newarg);
		ft_ldigit_nn(list, &tmp, &newarg);
	}
	else
	{
		ft_ldigit_nnn(list, &i, &tmp);
		digit = ft_atoi(&list->digit[i + 1]);
		newarg = ft_strnew(ft_atoi(tmp) + (digit - (int)ft_strlen(list->args)));
		ft_precs(list, newarg, tmp, digit);
	}
}
