/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldigitflag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 15:57:39 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/27 04:32:21 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_precs(t_flags *list, wchar_t *newarg, wchar_t *d, int digit)
{
	wchar_t		*tmp;
	wchar_t		*tmpargs;
	int			i;
	int			j;
	int			size;
	int			digittmp;

	digittmp = ft_atoi((void *)d);
	ft_wstrdel(&d);
	i = 0;
	size = (int)ft_wstrlen(list->wargs);
	if (list->conv != 'S')
	{
		if (list->wargs[0] == '-' || list->wargs[0] == '+')
			size -= 1;
		if (digittmp > digit && (list->space > 0 || list->sign > 0))
			digittmp -= digit;
		if (digittmp > (digit - size) + (int)ft_wstrlen(list->wargs))
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
		if (list->wargs[0] == '-' || list->wargs[0] == '+')
			i = 0;
		else
			i = 1;
		j = 0;
		tmp = ft_wstrnew(digit - size);
		while (i <= digit - size)
		{
			if (list->wargs[0] == '-' && j < 1)
				tmp[j++] = '-';
			else if (list->wargs[0] == '+' && j < 1)
				tmp[j++] = '+';
			else
				tmp[j++] = '0';
			i++;
		}
		if (j >= 1)
			tmp[j] = '\0';
		if (list->wargs[0] == '-' || list->wargs[0] == '+')
		{
			list->wargs++;
			tmpargs = ft_wstrjoin(tmp, list->wargs);
			ft_wstrdel(&tmp);
			list->wargs--;
			ft_wstrdel(&list->wargs);
			tmp = newarg;
			newarg = ft_wstrjoin(tmpargs, tmp);
			ft_wstrdel(&tmpargs);
			ft_wstrdel(&tmp);
		}
		else
		{
			tmpargs = ft_wstrjoin(tmp, list->wargs);
			ft_wstrdel(&list->wargs);
			ft_wstrdel(&tmp);
			tmp = newarg;
			newarg = ft_wstrjoin(tmpargs, tmp);
			ft_wstrdel(&tmpargs);
			ft_wstrdel(&tmp);
		}
		list->wargs = ft_wreallocf(newarg, 0);
		if (list->space > 0)
			ft_spaceflag(list);
	}
	else
	{
		if (digit > 0)
		{
			tmpargs = ft_wstrnew(digit);
			while (list->wargs[i] && i < digit)
				i++;
			tmp = &list->wargs[i];
			i = 0;
			while (i < digit)
			{
				tmpargs[i] = list->wargs[i];
				i++;
			}
			if (list->wargs[0] != '\0')
				ft_wstrdel(&list->wargs);
			list->wargs = ft_wstrjoin(tmpargs, tmp);
			ft_wstrdel(&tmpargs);
		}
		if (digittmp > 0)
		{
			i = 0;
			tmpargs = ft_wstrnew(digit);
			while (list->wargs[i] && i < digit)
				i++;
			tmp = &list->wargs[i];
			i = 0;
			while (i < digit)
			{
				tmpargs[i] = list->args[i];
				i++;
			}
			i = 0;
			if (list->args[0] != '\0')
				digittmp -= digit;
			d = ft_wstrnew(digittmp);
			while (i < digittmp)
				d[i++] = ' ';
			list->wargs = ft_wstrjoin(tmpargs, d);
			ft_wstrdel(&tmpargs);
			ft_wstrdel(&d);
			tmpargs = list->wargs;
			list->wargs = ft_wstrjoin(list->wargs, tmp);
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
	wchar_t		*tmp;
	int			digit;
	int			i;
	int			size;

	ft_wldigit_n(list, &size, &i, &newarg);
	if (list->precision == 0)
	{
		digit = ft_atoi(list->digit);
		newarg = ft_wstrnew(digit - size);
		while (i < (digit - size))
			newarg[i++] = ' ';
		ft_wld_nn(list, &i, &newarg, &tmp);
	}
	else
	{
		ft_wldigit_nnn(list, &i, &tmp);
		digit = ft_atoi(&list->digit[i + 1]);
		newarg = ft_wstrnew(ft_atoi((void *)tmp) + (digit -
					(int)ft_wstrlen(list->wargs)));
		ft_precs(list, newarg, tmp, digit);
	}
}
