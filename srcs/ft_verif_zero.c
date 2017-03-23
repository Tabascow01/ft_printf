/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_zero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 01:14:43 by mchemakh          #+#    #+#             */
/*   Updated: 2017/02/25 04:02:19 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_iszero_allowed(t_flags *list, int idxtmp)
{
	if (list->format[idxtmp] == 'x'
			|| list->format[idxtmp] == 'X'
			|| list->format[idxtmp] == 'o'
			|| list->format[idxtmp] == 'O'
			|| list->format[idxtmp] == 'd'
			|| list->format[idxtmp] == 'i')
		return (1);
	while (list->format[idxtmp] != '%' && list->format[idxtmp]
			&& ft_isflag(list->format[idxtmp]))
	{
		if (list->format[idxtmp + 1] == 'x'
				|| list->format[idxtmp + 1] == 'X'
				|| list->format[idxtmp + 1] == 'o'
				|| list->format[idxtmp + 1] == 'O'
				|| list->format[idxtmp + 1] == 'd'
				|| list->format[idxtmp + 1] == 'i')
			return (1);
		idxtmp++;
	}
	return (0);
}

int		ft_verif_zero(t_flags *list, int idxtmp)
{
	while (list->format[idxtmp] != '%' && list->format[idxtmp]
			&& ft_isflag(list->format[idxtmp]))
	{
		if (list->format[idxtmp] == '0' &&
				!ft_isdigit(list->format[idxtmp - 1]) &&
				ft_isdigit(list->format[idxtmp + 1]))
			return (1);
		idxtmp++;
	}
	return (0);
}
