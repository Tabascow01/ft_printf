/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_left.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 01:13:16 by mchemakh          #+#    #+#             */
/*   Updated: 2017/04/10 03:12:14 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_save_left(t_flags *list, int idxtmp)
{
	while (list->format[idxtmp] != '%' && list->format[idxtmp]
			&& ft_isflag(list->format[idxtmp]))
	{
		if (list->format[idxtmp] == '-')
			list->nbleft += 1;
		idxtmp++;
	}
	if (list->nbleft > 0)
	{
		list->index += list->nbleft;
		list->left = 1;
	}
}

int		ft_isleft_allowed(t_flags *list, int idxtmp)
{
	if (list->format[idxtmp] == '-'
			&& ft_isdigit(list->format[idxtmp + 1]))
		return (1);
	while (list->format[idxtmp] != '%' && list->format[idxtmp]
			&& ft_isflag(list->format[idxtmp]))
	{
		if (list->format[idxtmp] == '-' &&
				(ft_isdigit(list->format[idxtmp + 1])
				|| list->format[idxtmp + 1] == '+'
				|| list->format[idxtmp + 1] == '#'
				|| !ft_isflag(list->format[idxtmp + 1])
				|| list->format[idxtmp + 1] == '.'
				|| list->format[idxtmp + 1] == '-'
				|| list->format[idxtmp + 1] == '%'))
			return (1);
		idxtmp++;
	}
	return (0);
}

int		ft_verif_left(t_flags *list, int idxtmp)
{
	while (list->format[idxtmp] != '%' && list->format[idxtmp]
			&& ft_isflag(list->format[idxtmp]))
	{
		if (list->format[idxtmp] == '-')
			return (1);
		idxtmp++;
	}
	return (0);
}
