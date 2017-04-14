/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldgt_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 02:13:40 by mchemakh          #+#    #+#             */
/*   Updated: 2017/04/12 09:25:40 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>//

void	ft_ldgt_5(char **newarg, t_flags *list, t_precs *lst)
{
	int	a;

	a = 0;
	if ((list->args[0] == '-' || list->args[0] == '+') && lst->i > 0)
	{
		list->args++;
		a++;
	}
	if (list->dig1 > list->dig2 && list->dig2 > lst->size)
	{
		lst->tmp = ft_strjoin(list->args, lst->spaces);
		*newarg = ft_strjoin(lst->zero, lst->tmp);
	}
	else if (list->dig1 > list->dig2 && list->dig2 <= lst->size)
	{
		*newarg = ft_strjoin(list->args, lst->spaces);
		if (list->hash > 0)
			ft_strzhash(list,&(*newarg));
	}
	else
		*newarg = ft_strjoin(lst->zero, list->args);
	if (a > 0)
		list->args--;
	ft_strdel(&list->args);
	list->args = (*newarg);
}

void	ft_ldgt_4(t_flags *list, t_precs *lst)
{
	int diff;

	diff = 0;
	lst->i = 0;
	if (list->args[0] == '-' || list->args[0] == '+')
		lst->size -= 2;
	if (list->dig2 > lst->size)
	{
		diff = list->dig2 - lst->size;
		lst->zero = ft_strnew(list->dig2);
		if (list->args[0] == '-')
			lst->zero[lst->i++] = '-';
		if (list->args[0] == '+')
		lst->zero[lst->i++] = '+';
	}
	while(lst->i < diff)
		lst->zero[lst->i++] = '0';
	if (lst->i > 0 && list->hash == 0)
		lst->zero[lst->i] = '\0';
	else if (list->hash > 0)
		ft_strzhash(list, &lst->zero);
	else
		lst->zero[lst->i + 1] = '\0';
}

void	ft_ldgt_3(t_flags *list, t_precs *lst)
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
/*
void	ft_ldgt_2(t_flags *list, t_precs *lst, int *digittmp, int *digit)
{
	if (list->args[0] == 0 && (list->conv == 'd' || list->conv == 'i'
				|| list->conv == 'x' || list->conv == 'X'
				|| list->conv == 'o' || list->conv == 'O'))
		lst->null = 1;
	if ((list->args[0] == '-' && (*digit) >= lst->size) || (list->args[0] == '+'
				&& (*digit) >= 0)
			|| ((*digittmp) > (*digit) && list->conv == 'p'))
		lst->size -= 1;
	if ((*digittmp) > (*digit) && (list->space > 0)
			&& (*digit) > 0 && list->conv != 'p')
		(*digittmp) = (*digittmp) - (*digit) + lst->size;
	else if ((list->args[0] == '-' || list->args[0] == '+')
			&& (*digittmp) > (*digit) && (*digit) > 0 && lst->size > 0
			&& (*digit) > lst->size)
		lst->neg = 1;
	else
		(*digittmp) += 0;
}
*/
int		ft_ldgt_1(t_flags *list, t_precs *lst)
{
	ft_strdel(&lst->tmp);
	lst->i = 0;
	lst->flags = ft_check_flags(list);
	if ((list->dig1 == 0 && list->dig2 == 0)
			|| (list->dig1 < lst->size && list->dig2 < lst->size))
		return (0);
	return (1);
}
