/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_spcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 01:13:51 by mchemakh          #+#    #+#             */
/*   Updated: 2017/04/10 03:16:07 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_save_spcs(t_flags *list, int idxtmp)
{
	while (list->format[idxtmp] != '%' && list->format[idxtmp]
			&& ft_isflag(list->format[idxtmp]))
	{
		if (list->format[idxtmp] == ' ')
		{
			list->space += 1;
			list->index += 1;
		}
		idxtmp++;
	}
}

int		ft_isspcs_allowed(t_flags *list, int idxtmp)
{
	while (list->format[idxtmp] != '%' && list->format[idxtmp]
			&& ft_isflag(list->format[idxtmp]))
	{
		if (list->format[idxtmp + 1] == 'u' || list->format[idxtmp + 1] == 'U')
		{
			list->size -= 1;
			list->index += 1;
		}
		if (list->format[idxtmp] == ' '
				&& list->format[idxtmp + 1] != 'u'
				&& list->format[idxtmp + 1] != 'U')
			return (1);
		idxtmp++;
	}
	return (0);
}

int		ft_verif_spcs(t_flags *list, int idxtmp)
{
	while (list->format[idxtmp] != '%' && list->format[idxtmp]
			&& ft_isflag(list->format[idxtmp]))
	{
		if (list->format[idxtmp] == ' ')
			return (1);
		idxtmp++;
	}
	return (0);
}
