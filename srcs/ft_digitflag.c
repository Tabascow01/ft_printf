/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digitflag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 16:38:38 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/27 06:20:46 by mchemakh         ###   ########.fr       */
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

	ft_dgt_1(list, &digittmp, fdigit, &size);
	if (digittmp == 0 && digit == 0)
		return ;
	i = 0;
	if (list->conv != 's')
	{
		ft_dgt_2(list, &digittmp, &size, &digit);
		if (digittmp > (int)ft_strlen(list->args) + digit - size)
			ft_dgt_4(&i, &digittmp, &size, &newarg);
		j = 0;
		while (j < digit - size)
			ft_dgt_3(list, &i, &j, &newarg);
		if (i > 0)
			newarg[i] = '\0';
		if (digit < size && (list->args[0] == '-' || list->args[0] == '+')
				&& digittmp > size)
			newarg[i] = list->args[0];
		if ((list->args[0] == '-' || list->args[0] == '+') && i > 0)
			ft_dgt_5(list, &tmp, &newarg);
		else
		{
			ft_dgt_7(list, &tmpargs, &newarg, &digittmp);
			ft_dgt_6(list, &tmp, &newarg, tmpargs);
		}
		ft_dgt_8(list, &tmp, &newarg);
	}
	else
	{
		if (digit > 0)
		{
			tmpargs = ft_strnew(digit);
			while (list->args[i] && i < digit)
				i++;
			tmp = &list->args[i];
			ft_dgt_9(list, &i, &tmpargs, &digit);
			list->args = ft_strjoin(tmpargs, tmp);
			ft_strdel(&tmpargs);
		}
		else
			ft_bzero(list->args, size);
		if (digittmp > 0)
		{
			ft_dgt_10(&i, &digittmp, &digit, &size);
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
		ft_digit_nn(list, &i, &tmp);
		digit = ft_atoi(&list->digit[i + 1]);
		newarg = ft_strnew(ft_atoi(tmp) + digit - ((int)ft_strlen(list->args)));
		ft_precs(list, newarg, tmp, digit);
	}
}
