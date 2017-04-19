/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 00:17:31 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/15 21:54:38 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_islong_allowed(t_flags *list, int idxtmp)
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
				|| list->format[idxtmp + 1] == 'D'
				|| list->format[idxtmp + 1] == 'c'
				|| list->format[idxtmp + 1] == 's')
			return (1);
		idxtmp++;
	}
	return (0);
}

int		ft_verif_long(t_flags *list, int idxtmp)
{
	while (list->format[idxtmp] != '%' && list->format[idxtmp]
			&& ft_isflag(list->format[idxtmp]))
	{
		if (list->format[idxtmp] == 'l')
			return (1);
		idxtmp++;
	}
	return (0);
}
