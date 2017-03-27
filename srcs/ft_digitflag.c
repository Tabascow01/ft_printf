/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digitflag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 16:38:38 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/27 03:30:11 by mchemakh         ###   ########.fr       */
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
	if (digittmp == 0 && digit == 0)
		return ;
	i = 0;
	size = (int)ft_strlen(list->args);
	if (list->conv != 's')
	{
		if (((list->args[0] == '-' || list->args[0] == '+') && digit >= 0)
				|| (digittmp > digit && list->conv == 'p'))
			size -= 1;
		if (digittmp > digit && (list->space > 0 || list->sign > 0)
				&& digit > 0 && list->conv != 'p')
			digittmp = digittmp - digit + size;
		else if (digittmp > digit && size > 0 && size <= digit && digit > 0
				&& list->conv != 'p' && list->args[0] != '-'
				&& list->args[0] != '+')
			digittmp = digittmp - (digit - size) + 1;
		else if (digittmp > digit && digittmp > size && digit > 0
				&& list->conv != 'p' && list->args[0] != '-'
				&& list->args[0] != '+')
			digittmp += 1;
		else if ((list->args[0] == '-' || list->args[0] == '+')
				&& digittmp > digit && digit > 0 && size > 0 && digit > size)
			digittmp -= size;
		else
			digittmp += 0;
		if (digittmp > (int)ft_strlen(list->args) + digit - size)
		{
			while (i < digittmp - size)
				newarg[i++] = ' ';
			i--;
		}
		j = 0;
		while (j < digit - size)
		{
			if (list->args[0] == '-' && newarg[i - 1] != '0')
				newarg[i++] = '-';
			if (list->args[0] == '+' && newarg[i - 1] != '0')
				newarg[i++] = '+';
			newarg[i] = '0';
			i++;
			j++;
		}
		if (i > 0)
			newarg[i] = '\0';
		if (digit < size && (list->args[0] == '-' || list->args[0] == '+')
				&& digittmp > size)
			newarg[i] = list->args[0];
		if ((list->args[0] == '-' || list->args[0] == '+') && i > 0)
		{
			list->args++;
			tmp = newarg;
			newarg = ft_strjoin(newarg, list->args);
			ft_strdel(&tmp);
			list->args--;
			tmp = list->args;
		}
		else
		{
			tmpargs = newarg;
			if (digittmp > 0 && list->args[0] == '\0')
				list->args[0] = ' ';
			tmp = list->args;
			newarg = ft_strjoin(tmpargs, list->args);
			ft_strdel(&tmpargs);
		}
		ft_strdel(&tmp);
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
		else
			ft_bzero(list->args, size);
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
			tmp = ft_strnew(digittmp);
			while (i < digittmp)
				tmp[i++] = ' ';
			list->args = ft_strjoin(tmp, list->args);
			ft_strdel(&tmp);
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

static void		ft_digit_nn(t_flags *list, int *i, char **tmp, int *digit)
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
	char	*tmp;
	int		digit;
	int		i;
	int		size;

	newarg = NULL;
	i = 0;
	size = (int)ft_strlen(list->args);
	if (list->precision == 0)
	{
		ft_digit_n(list, &size, &digit, &newarg);
		while (i < (digit - size))
			newarg[i++] = ' ';
		ft_digit_nnn(list, &i, &newarg, &tmp);
	}
	else
	{
		ft_digit_nn(list, &i, &tmp, &digit);
		digit = ft_atoi(&list->digit[i + 1]);
		newarg = ft_strnew(ft_atoi(tmp) + digit - ((int)ft_strlen(list->args)));
		ft_precs(list, newarg, tmp, digit);
	}
}
