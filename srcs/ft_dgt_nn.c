/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dgt_nn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 05:40:34 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/27 06:21:17 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_dgt_6(t_flags *list, char **tmp, char **newarg, char *tmpargs)
{
	(*tmp) = list->args;
	(*newarg) = ft_strjoin(tmpargs, list->args);
	ft_strdel(&tmpargs);
}

void	ft_dgt_7(t_flags *list, char **tmpargs, char **newarg, int *digitmp)
{
	(*tmpargs) = (*newarg);
	if ((*digitmp) > 0 && list->args[0] == '\0')
		list->args[0] = ' ';
}

void	ft_dgt_8(t_flags *list, char **tmp, char **newarg)
{
	ft_strdel((*&tmp));
	list->args = ft_reallocf((*newarg), 0);
	if (list->space > 0)
		ft_spaceflag(list);
}

void	ft_dgt_9(t_flags *list, int *i, char **tmpargs, int *digit)
{
	(*i) = 0;
	while ((*i) < (*digit))
	{
		(*tmpargs)[(*i)] = list->args[(*i)];
		(*i)++;
	}
	if (list->args[0] != '\0')
		ft_strdel(&list->args);
}

void	ft_dgt_10(int *i, int *dgttmp, int *dgt, int *size)
{
	(*i) = 0;
	if ((*dgttmp) > (*dgt) && (*dgt) <= (*size))
		(*dgttmp) -= (*dgt);
	else if ((*dgttmp) > (*dgt) && (*dgt) > (*size) && (*size) > 0)
		(*dgttmp) -= (*dgt) - (*size);
	else if ((*dgttmp) < (*dgt) && (*dgttmp) > (*size) && (*size) > 0)
		(*dgttmp) -= (*size);
	else if ((*dgttmp) < (*dgt) && (*dgttmp) < (*size) && (*dgttmp) > 0)
		(*dgttmp) -= (*dgt);
	else
		(*dgttmp) -= 0;
}
