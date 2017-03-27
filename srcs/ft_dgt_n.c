/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dgt_n.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 05:02:59 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/27 06:22:54 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_dgt_1(t_flags *list, int *digittmp, char *fdigit, int *size)
{
	(*digittmp) = ft_atoi(fdigit);
	ft_strdel(&fdigit);
	(*size) = (int)ft_strlen(list->args);
}

void	ft_dgt_2(t_flags *list, int *digittmp, int *size, int *digit)
{
	if (((list->args[0] == '-' || list->args[0] == '+') && (*digit) >= 0)
			|| ((*digittmp) > (*digit) && list->conv == 'p'))
		(*size) -= 1;
	if ((*digittmp) > (*digit) && (list->space > 0 || list->sign > 0)
			&& (*digit) > 0 && list->conv != 'p')
		(*digittmp) = (*digittmp) - (*digit) + (*size);
	else if ((*digittmp) > (*digit) && (*size) > 0 && (*size) <= (*digit) &&
			(*digit) > 0 && list->conv != 'p' && list->args[0] != '-'
			&& list->args[0] != '+')
		(*digittmp) = (*digittmp) - ((*digit) - (*size)) + 1;
	else if ((*digittmp) > (*digit) && (*digittmp) > (*size) && (*digit) > 0
			&& list->conv != 'p' && list->args[0] != '-'
			&& list->args[0] != '+')
		(*digittmp) += 1;
	else if ((list->args[0] == '-' || list->args[0] == '+') && (*digittmp) >
			(*digit) && (*digit) > 0 && (*size) > 0 && (*digit) > (*size))
		(*digittmp) -= (*size);
	else
		(*digittmp) += 0;
}

void	ft_dgt_3(t_flags *list, int *i, int *j, char **newarg)
{
	if (list->args[0] == '-' && (*newarg)[(*i) - 1] != '0')
		(*newarg)[(*i)++] = '-';
	if (list->args[0] == '+' && (*newarg)[(*i) - 1] != '0')
		(*newarg)[(*i)++] = '+';
	(*newarg)[(*i)] = '0';
	(*i)++;
	(*j)++;
}

void	ft_dgt_4(int *i, int *digittmp, int *size, char **newarg)
{
	while ((*i) < (*digittmp) - (*size))
		(*newarg)[(*i)++] = ' ';
	(*i)--;
}

void	ft_dgt_5(t_flags *list, char **tmp, char **newarg)
{
	list->args++;
	(*tmp) = (*newarg);
	(*newarg) = ft_strjoin((*newarg), list->args);
	ft_strdel((*&tmp));
	list->args--;
	(*tmp) = list->args;
}
