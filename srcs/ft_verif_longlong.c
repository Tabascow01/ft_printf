/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_longlong.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 00:17:40 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/12 05:19:01 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_islonglong_allowed(t_flags *list, int idxtmp)
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
				|| list->format[idxtmp + 1] == 'C')
			return (1);
		idxtmp++;
	}
	return (0);
}

int		ft_verif_longlong(t_flags *list, int idxtmp)
{
	while (list->format[idxtmp] != '%' && list->format[idxtmp]
			&& ft_isflag(list->format[idxtmp]))
	{
		if (list->format[idxtmp] == 'l'
				&& list->format[idxtmp + 1] == 'l')
			return (1);
		idxtmp++;
	}
	return (0);
}
