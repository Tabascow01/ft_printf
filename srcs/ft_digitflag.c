/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digitflag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 16:38:38 by mchemakh          #+#    #+#             */
/*   Updated: 2017/04/06 00:51:18 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h" //

static void		ft_precs(t_flags *list, char *newarg, t_precs *lst, int digit)
{
	int		digittmp;

	if (ft_dgt_1(list, &digittmp, lst, &digit) == 0)
		return ;
	if (list->conv != 's')
	{
		ft_dgt_2(list, &digittmp, lst, &digit);
		if (digittmp > (int)ft_strlen(list->args) + digit - lst->size)
			ft_dgt_3(&newarg, lst, &digittmp, &digit);
		ft_dgt_4(list, &newarg, lst, &digit);
		if (digit < lst->size && (list->args[0] == '-' || list->args[0] == '+')
				&& digittmp > lst->size)
			newarg[lst->i] = list->args[0];
		ft_dgt_5(list, &newarg, lst, &digittmp);
		ft_dgt_6(list, lst, &newarg);
	}
	else
	{
		if (digit > 0)
			ft_dgt_7(list, lst, &digit);
		else
			ft_bzero(list->args, lst->size);
		if (digittmp > 0)
			ft_dgt_8(list, lst, &digittmp, &digit);
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
	free(lst);
}
