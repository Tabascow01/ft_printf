/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_intmax.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 00:20:43 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/01 12:03:41 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isintmax_allowed(t_flags *list, int idxtmp)
{
	while (list->format[idxtmp] != '%' && list->format[idxtmp]
			&& ft_isflag(list->format[idxtmp]))
	{
		if (list->format[idxtmp + 1] == 'd'
				|| list->format[idxtmp + 1] == 'i'
				|| list->format[idxtmp + 1] == 'o'
				|| list->format[idxtmp + 1] == 'O'
				|| list->format[idxtmp + 1] == 'x'
				|| list->format[idxtmp + 1] == 'X'
				|| list->format[idxtmp + 1] == 'u'
				|| list->format[idxtmp + 1] == 'U'
				|| list->format[idxtmp + 1] == 'p'
				|| list->format[idxtmp + 1] == 'D')
			return (1);
		idxtmp++;
	}
	return (0);
}

int		ft_verif_intmax(t_flags *list, int idxtmp)
{
	while (list->format[idxtmp] != '%' && list->format[idxtmp]
			&& ft_isflag(list->format[idxtmp]))
	{
		if (list->format[idxtmp] == 'j')
			return (1);
		idxtmp++;
	}
	return (0);
}
