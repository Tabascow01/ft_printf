/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dgt_n.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 05:02:59 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/29 04:26:22 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		(*digittmp) = (*digittmp) - (*digit) + lst->size;
	else if ((*digittmp) > (*digit) && lst->size > 0 && lst->size <= (*digit)
			&& (*digit) > 0 && list->conv != 'p' && list->args[0] != '-'
			&& list->args[0] != '+')
		(*digittmp) = (*digittmp) - ((*digit) - lst->size) + 1;
	else if ((*digittmp) > (*digit) && (*digittmp) > lst->size && (*digit) > 0
			&& list->conv != 'p' && list->args[0] != '-'
			&& list->args[0] != '+')
		(*digittmp) += 1;
	else if ((list->args[0] == '-' || list->args[0] == '+')
			&& (*digittmp) > (*digit) && (*digit) > 0 && lst->size > 0
			&& (*digit) > lst->size)
		(*digittmp) -= lst->size;
	else
		(*digittmp) += 0;
}

void	ft_dgt_3(char **newarg, t_precs *lst, int *digittmp)
{
	while (lst->i < (*digittmp) - lst->size)
		(*newarg)[lst->i++] = ' ';
	lst->i--;
}

void	ft_dgt_4(t_flags *list, char **newarg, t_precs *lst, int *digit)
{
	lst->j = 0;
	while (lst->j < (*digit) - lst->size)
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
