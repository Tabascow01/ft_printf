/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dgt_n.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 05:02:59 by mchemakh          #+#    #+#             */
/*   Updated: 2017/04/06 00:43:30 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_dgt_1(t_flags *list, int *digittmp, t_precs *lst, int *digit)
{
	(*digittmp) = ft_atoi(lst->tmp);
	ft_strdel(&lst->tmp);
	if ((*digittmp) == 0 && (*digit) == 0)
		return (0);
	lst->i = 0;
	lst->size = (int)ft_strlen(list->args);
	return (1);
}

void	ft_dgt_2(t_flags *list, int *digittmp, t_precs *lst, int *digit)
{
	if (((list->args[0] == '-' || list->args[0] == '+') && (*digit) >= 0)
			|| ((*digittmp) > (*digit) && list->conv == 'p'))
		lst->size -= 1;
	if ((*digittmp) > (*digit) && (list->space > 0 || list->sign > 0)
			&& (*digit) > 0 && list->conv != 'p')
	{
		///printf("1\n");
		(*digittmp) = (*digittmp) - (*digit) + lst->size;
	}
	else if ((*digittmp) > (*digit) && lst->size > 0 && lst->size <= (*digit)
			&& (*digit) > 0 && list->conv != 'p' && list->args[0] != '-'
			&& list->args[0] != '+' && (*digittmp) > (*digit) +
			(int)ft_strlen(list->args))
	{
		//printf("2\n");
		(*digittmp) = (*digittmp) - ((*digit) - lst->size) + 1;
	}
	else if ((*digittmp) > (*digit) && (*digittmp) > lst->size && (*digit) > 0
			&& list->conv != 'p' && list->args[0] != '-'
			&& list->args[0] != '+' && (*digittmp) > (*digit) +
			(int)ft_strlen(list->args))
	{
		//printf("3\n");
		(*digittmp) += 1;
	}
	else if ((list->args[0] == '-' || list->args[0] == '+')
			&& (*digittmp) > (*digit) && (*digit) > 0 && lst->size > 0
			&& (*digit) > lst->size)
	{
		printf("4\n");
		lst->neg = 1;
	}
	/*
	else if ((*digittmp) > (*digit) && lst->size > 0 && lst->size <= (*digit)
			&& (*digit) > 0 && list->conv != 'p' && list->args[0] != '-'
			&& list->args[0] != '+' && (*digittmp) <= (*digit) +
			(int)ft_strlen(list->args))
	{
		//printf("5\n");
		(*digittmp) += lst->size;
	}
	*/
	else
	{
		//printf("6\n");
		(*digittmp) += 0;
	}
}

void	ft_dgt_3(char **newarg, t_precs *lst, int *digittmp, int *digit)
{
	int		diff;

	diff = 0;
	//printf("dgtmp3[%d]-dgt3[%d]\n",*digittmp, *digit);
	if ((*digittmp) > (*digit) + lst->size)
		diff = (*digittmp);
	else
		diff = (*digittmp) - (lst->size + ((*digit) - lst->size));
	//printf("%d - (%d + (%d - %d)) = [%d]\n",*digittmp,lst->size,*digit,lst->size,diff);
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
		diff = (*digit);
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
	if (lst->i > 0)
		(*newarg)[lst->i] = '\0';
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
