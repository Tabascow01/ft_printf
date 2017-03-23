/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wdigitflag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 00:30:03 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/20 01:38:50 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_precs(t_flags *list, wchar_t *newarg, wchar_t *d, int digit)
{
	wchar_t	*tmp;
	wchar_t	*tmpargs;
	int		i;
	int		j;
	int		size;
	int		digittmp;

	digittmp = ft_atoi((void *)d);
	ft_wstrdel(&d);
	if (digittmp == 0 && digit == 0)
		return ;
	i = 0;
	size = (int)ft_wstrlen(list->wargs);
	if (list->conv != 'S')
	{
		if (((list->wargs[0] == '-' || list->wargs[0] == '+') && digit >= 0))
			size -= 1;
		if (digittmp > digit && size > 0 && size <= digit && digit > 0
				&& list->wargs[0] != '-' && list->wargs[0] != '+')
			digittmp = digittmp - (digit - size) + 1;
		else if (digittmp > digit && digittmp > size && digit > 0
				&& list->wargs[0] != '-' && list->wargs[0] != '+')
			digittmp += 1;
		else if ((list->wargs[0] == '-' || list->wargs[0] == '+')
				&& digittmp > digit && digit > 0 && size > 0 && digit > size)
			digittmp -= size;
		else
			digittmp += 0;
		if (digittmp > (int)ft_wstrlen(list->wargs) + digit - size)
		{
			while (i < digittmp - size)
				newarg[i++] = ' ';
			i--;
		}
		j = 0;
		while (j < digit - size)
		{
			if (list->wargs[0] == '-' && newarg[i - 1] != '0')
				newarg[i++] = '-';
			if (list->wargs[0] == '+' && newarg[i - 1] != '0')
				newarg[i++] = '+';
			newarg[i] = '0';
			i++;
			j++;
		}
		if (i > 0)
			newarg[i] = '\0';
		if (digit < size && (list->wargs[0] == '-' || list->wargs[0] == '+')
				&& digittmp > size)
			newarg[i] = list->wargs[0];
		if ((list->wargs[0] == '-' || list->wargs[0] == '+') && i > 0)
		{
			list->wargs++;
			tmp = newarg;
			newarg = ft_wstrjoin(newarg, list->wargs);
			ft_wstrdel(&tmp);
			list->wargs--;
			tmp = list->wargs;
		}
		else
		{
			tmpargs = newarg;
			if (digittmp > 0 && list->wargs[0] == '\0')
				list->wargs[0] = ' ';
			tmp = list->wargs;
			newarg = ft_wstrjoin(tmpargs, list->wargs);
			ft_wstrdel(&tmpargs);
		}
		ft_wstrdel(&tmp);
		list->wargs = ft_wreallocf(newarg, 0);
		if (list->space > 0)
			ft_spaceflag(list);
	}
	else
	{
		if (digit > 0)
		{
			tmpargs = ft_wstrnew(digit + 1);
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
		else
			ft_bzero(list->wargs, size);
		if (digittmp > 0)
		{
			i = 0;
			if (digittmp > digit && digit <= size)
				digittmp -= digit;
			else if (digittmp > digit && digit > size && size > 0)
				digittmp -= digit - size;
			else if (digittmp < digit && digittmp > size && size > 0)
				digittmp -= size;
			else if (digittmp < digit && digittmp < size && digittmp > 0)
				digittmp -= digit;
			else
				digittmp -= 0;
			tmp = ft_wstrnew(digittmp + 1);
			while (i < digittmp)
				tmp[i++] = ' ';
			list->wargs = ft_wstrjoin(tmp, list->wargs);
			ft_wstrdel(&tmp);
		}
	}
}

void			ft_wdigitflag(t_flags *list)
{
	wchar_t	*newarg;
	wchar_t	*tmp;
	int		digit;
	int		i;
	int		size;

	newarg = NULL;
	i = 0;
	size = (int)ft_wstrlen(list->wargs);
	if (list->precision == 0)
	{
		if ((int)ft_wstrlen(list->wargs) == 0 && (list->conv != 'S'
			|| list->noconv > 0))
		{
			if (list->noconv > 0)
				list->size += 1;
			size += 1;
		}
		digit = ft_atoi(list->digit);
		newarg = ft_wstrnew(digit - size + 1);
		while (i < (digit - size))
		{
			newarg[i] = ' ';
			i++;
		}
		if (i > 0)
			newarg[i] = '\0';
		tmp = ft_wstrjoin(newarg, list->wargs);
		ft_wstrdel(&newarg);
		list->wargs = ft_wreallocf(tmp, 0);
	}
	else
	{
		while (list->digit[i] && list->digit[i] != '.')
			i++;
		tmp = ft_wstrnew(1);
		i = 0;
		while (list->digit[i] && list->digit[i] != '.')
		{
			tmp[i] = list->digit[i];
			i++;
		}
		digit = ft_atoi(&list->digit[i + 1]);
		newarg = ft_wstrnew(ft_atoi((void *)tmp) + digit - ((int)ft_wstrlen(list->wargs) + 1));
		ft_precs(list, newarg, tmp, digit);
	}
}
