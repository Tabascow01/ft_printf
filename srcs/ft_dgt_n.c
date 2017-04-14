/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dgt_n.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 05:02:59 by mchemakh          #+#    #+#             */
/*   Updated: 2017/04/12 10:08:57 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>//

int		ft_dgt_1(t_flags *list, t_precs *lst)
{
	ft_strdel(&lst->tmp);
	lst->i = 0;
	if ((list->dig1 == 0 && list->dig2 == 0)
			|| (list->dig1 <= lst->size
			&& list->dig2 <= lst->size))
		return (0);
	return (1);
}

/*
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
	else if (list->args[0] != '+' && list->args[0] != '-'
			&& (*digittmp) > (*digit) && (list->space > 0 || list->sign > 0)
			&& (*digit) > 0 && list->conv != 'p')
		(*digittmp) = (*digittmp) - (*digit) + lst->size;
	else if ((list->args[0] == '-' || list->args[0] == '+')
			&& (*digittmp) > (*digit) && (*digit) > 0 && lst->size > 0)
		lst->neg = 1;
	else
		(*digittmp) += 0;
}
*/

void	ft_dgt_3(t_flags *list, t_precs *lst)
{
	int		diff;

	diff = 0;
	if (lst->neg > 0)
		diff = -1;
	if (list->dig1 > list->dig2 && list->dig2 > lst->size)
		diff += list->dig1 - list->dig2;
	else if (list->dig1 > list->dig2 && list->dig2 <= lst->size)
		diff += list->dig1 - lst->size;
	if (list->hash > 0 && (list->conv == 'x' || list->conv == 'X'))
		diff -= 2;
	else if (list->hash > 0 && (list->conv == 'o' || list->conv == 'O'))
		diff -= 1;
	lst->spaces = ft_strnew(diff);
	while (lst->i < diff)
		lst->spaces[lst->i++] = ' ';
	if (lst->neg > 0)
		lst->i--;
}

void	ft_dgt_4(t_flags *list, t_precs *lst)
{
	int diff;

	diff = 0;
	lst->i = 0;
	lst->zero = ft_strnew(list->dig2);
	if (list->args[0] == '-' ||list->args[0] == '+')
		lst->size -= 2;
	if (list->dig2 > lst->size)
	{
		diff = list->dig2 - lst->size;

		if (list->args[0] == '-')
			lst->zero[lst->i++] = '-';
		if (list->args[0] == '+')
			lst->zero[lst->i++] = '+';
	}
	while (lst->i < diff)
		lst->zero[lst->i++] = '0';
	if (lst->i > 0 && list->hash == 0)
		lst->zero[lst->i] = '\0';
	else if (list->hash > 0)
		ft_strzhash(list, &lst->zero);
	else
		lst->zero[lst->i + 1] = '\0';
}

void	ft_dgt_5(char **newarg, t_flags *list, t_precs *lst)
{
	int a;

	a = 0;
	if ((list->args[0] == '-' || list->args[0] == '+') && lst->i > 0)
	{
		list->args++;
		a++;
	}
	if (list->dig1 > list->dig2 && list->dig2 > lst->size)
	{
		lst->tmp = ft_strjoin(lst->spaces, lst->zero);
		*newarg = ft_strjoin(lst->tmp, list->args);
	}
	else if (list->dig1 > list->dig2 && list->dig2 <= lst->size
			&& list->hash == 0)
		*newarg = ft_strjoin(lst->spaces, list->args);
	else if (list-> dig1 > list->dig2 && list->dig2 <= lst->size
				&& list->hash > 0)
	{
		lst->zero = ft_strnew(2);
		ft_strzhash(list, &lst->zero);
		lst->tmp = ft_strjoin(lst->zero, list->args);
		*newarg = ft_strjoin(lst->spaces, lst->tmp);
	}
	else
		*newarg = ft_strjoin(lst->zero, list->args);
	if (a > 0)
		list->args--;
	ft_strdel(&list->args);
	list->args = (*newarg);
}
