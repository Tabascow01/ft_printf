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

void	ft_ldgt_5(t_flags *list, t_precs *lst, int *digit, char **newarg)
{
	if (lst->i > 0 && ((*digit) > 0 || (*digit) - lst->size > 0))
		(*newarg)[lst->i] = '\0';
	if (list->args[0] == '-' || list->args[0] == '+')
		lst->i = 0;
	else
		lst->i = 1;
	lst->j = 0;
	if ((*digit) - lst->size > 0)
		lst->tmp = ft_strnew((*digit) - lst->size);
	else
		lst->tmp = ft_strnew(lst->size + 1);
	while (lst->i <= (*digit) - lst->size)
	{
		if (list->args[0] == '-' && lst->j < 1)
			lst->tmp[lst->j++] = '-';
		else if (list->args[0] == '+' && lst->j < 1)
			lst->tmp[lst->j++] = '+';
		else
			lst->tmp[lst->j++] = '0';
		lst->i++;
	}
	if (lst->j >= 1)
		lst->tmp[lst->j] = '\0';
}

void	ft_ldgt_4(t_precs *lst, int *digittmp, char **newarg, int *digit)
{
	int diff;

	diff = 0;
	if ((*digittmp) > (*digit) + lst->size && (*digit) <= lst->size)
		diff = (*digittmp) - (*digit);
	else if ((*digittmp) > (*digit) && (*digit) > lst->size && lst->flags == 0)
		diff = (*digittmp) - (lst->size + ((*digit) - lst->size));
	else if (lst->flags == 0)
		diff = (*digittmp) - lst->size;
	else if (lst->flags > 0)
		diff = (*digittmp) - (*digit);
	while (lst->i < diff)
		(*newarg)[lst->i++] = ' ';
	lst->i--;
}

void	ft_ldgt_3(t_precs *lst, int *digittmp, char **newarg, int *digit)
{
	int		diff;

	diff = 0;
	if ((*digittmp) > (*digit) + lst->size && (*digit) < lst->size)
		diff = (*digittmp) - lst->size;
	else if ((*digittmp) > (*digit) && (*digit) > lst->size)
		diff = (*digittmp) - (lst->size + ((*digit) - lst->size));
	else
	{
//		printf("dgtmp[%d]-dgt[%d]\n",*digittmp, *digit);
		diff = (*digittmp) - lst->size;
	}
	if (lst->null > 0)
		diff -= 1;
//	printf("diff2[%d]-size[%d]\n", diff, lst->size);
	while (lst->i < diff)
		(*newarg)[lst->i++] = ' ';
	if (lst->neg > 0)
		lst->i--;
}

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

int		ft_ldgt_1(t_flags *list, t_precs *lst, int *digittmp, int *digit)
{
	(*digittmp) = ft_atoi(lst->tmp);
	ft_strdel(&lst->tmp);
	lst->i = 0;
	lst->size = (int)ft_strlen(list->args);
	lst->flags = ft_check_flags(list);
	if ((*digittmp == 0 && (*digit) == 0)
			|| ((*digittmp) < lst->size && (*digit) < lst->size))
		return (0);
	return (1);
}
