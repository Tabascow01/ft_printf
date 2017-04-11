/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dgt_n.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 05:02:59 by mchemakh          #+#    #+#             */
/*   Updated: 2017/04/06 03:50:04 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_dgt_1(t_flags *list, int *digittmp, t_precs *lst, int *digit)
{
	(*digittmp) = ft_atoi(lst->tmp);
	ft_strdel(&lst->tmp);
	lst->i = 0;
	lst->size = (int)ft_strlen(list->args);
	if (((*digittmp) == 0 && (*digit) == 0)
			|| ((*digittmp) < lst->size
			&& (*digit) < lst->size))
		return (0);
	return (1);
}

void	ft_dgt_2(t_flags *list, int *digittmp, t_precs *lst, int *digit)
{
	if (list->args[0] == 0 && (list->conv == 'd' || list->conv == 'i'
				|| list->conv == 'x' || list->conv == 'X'
				|| list->conv == 'o' || list->conv == 'O'))
		lst->null = 1;
	if ((list->args[0] == '-' && (*digit) >= lst->size) || (list->args[0] == '+'
			&& (*digit) >= 0)
			|| ((*digittmp) > (*digit) && list->conv == 'p'))
		lst->size -= 1;
	if ((list->conv == 'o' ||list->conv == 'O') && (*digittmp) > (*digit)
			&& (*digit) <= lst->size && list->hash > 0)
		lst->size += 1;
	else if ((list->conv == 'x' ||list->conv == 'X') && (*digittmp) > (*digit)
			&& (*digit) <= lst->size && list->hash > 0)
		lst->size += 2;
	else if ((*digittmp) > (*digit) && (list->space > 0 || list->sign > 0)
			&& (*digit) > 0 && list->conv != 'p')
		(*digittmp) = (*digittmp) - (*digit) + lst->size;
	else if ((list->args[0] == '-' || list->args[0] == '+')
			&& (*digittmp) > (*digit) && (*digit) > 0 && lst->size > 0
			&& (*digit) > lst->size)
		lst->neg = 1;
	else
		(*digittmp) += 0;
}

void	ft_dgt_3(char **newarg, t_precs *lst, int *digittmp, int *digit)
{
	int		diff;

	diff = 0;
	if ((*digittmp) > (*digit) + lst->size && (*digit) < lst->size)
		diff = (*digittmp) - lst->size;
	else if ((*digittmp) > (*digit) && (*digit) > lst->size)
		diff = (*digittmp) - (lst->size + ((*digit) - lst->size));
	else
		diff = (*digittmp) - lst->size;
	if (lst->null > 0)
		diff -= 1;
	while (lst->i < diff)
		(*newarg)[lst->i++] = ' ';
	if (lst->neg > 0)
		lst->i--;
}

void	ft_dgt_4(t_flags *list, char **newarg, t_precs *lst, int *digit)
{
	int diff;

	diff = 0;
	lst->j = 0;
	if ((*digit) < lst->size)
		diff = 0;
	else
		diff = (*digit) - lst->size;
	while (lst->j < diff)
	{
		if (list->args[0] == '-' && (*newarg)[lst->i - 1] != '0')
			(*newarg)[lst->i++] = '-';
		if (list->args[0] == '+' && (*newarg)[lst->i - 1] != '0')
			(*newarg)[lst->i++] = '+';
		(*newarg)[lst->i] = '0';
		lst->i++;
		lst->j++;
	}
	if (lst->i > 0 && list->hash == 0)
		(*newarg)[lst->i] = '\0';
	else
		ft_strzhash(list, &(*newarg));
}

void	ft_dgt_5(t_flags *list, char **newarg, t_precs *lst, int *digittmp)
{
	if ((list->args[0] == '-' || list->args[0] == '+') && lst->i > 0)
	{
		list->args++;
		lst->tmp = (*newarg);
		(*newarg) = ft_strjoin((*newarg), list->args);
		ft_strdel(&lst->tmp);
		list->args--;
		lst->tmp = list->args;
	}
	else
	{
		lst->tmpargs = (*newarg);
		if ((*digittmp) > 0 && list->args[0] == '\0')
			list->args[0] = ' ';
		lst->tmp = list->args;
		(*newarg) = ft_strjoin(lst->tmpargs, list->args);
		ft_strdel(&lst->tmpargs);
	}
}
