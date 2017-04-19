/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_numbersign.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 01:13:30 by mchemakh          #+#    #+#             */
/*   Updated: 2017/04/10 03:15:40 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_allowed_next(t_flags *list, int idxtmp)
{
	if (list->format[idxtmp] == 'd' || list->format[idxtmp] == 'i')
		return (1);
	return (0);
}

void			ft_save_sign(t_flags *list, int idxtmp)
{
	while (list->format[idxtmp] != '%' && list->format[idxtmp]
			&& ft_isflag(list->format[idxtmp]))
	{
		if (list->format[idxtmp] == '+')
		{
			list->sign += 1;
			list->index += 1;
		}
		idxtmp++;
	}
}

int				ft_isnbsign_allowed(t_flags *list, int idxtmp)
{
	if (ft_allowed_next(list, idxtmp))
		return (1);
	while (list->format[idxtmp] != '%' && list->format[idxtmp]
		&& ft_isflag(list->format[idxtmp]))
	{
		if (list->format[idxtmp + 1] == 'u' || list->format[idxtmp + 1] == 'U'
				|| list->format[idxtmp + 1] == 'c'
				|| list->format[idxtmp + 1] == 'p'
				|| list->format[idxtmp + 1] == 'C'
				|| list->format[idxtmp + 1] == 'o'
				|| list->format[idxtmp + 1] == 'O'
				|| list->format[idxtmp + 1] == 'x'
				|| list->format[idxtmp + 1] == 'X'
				|| list->format[idxtmp + 1] == 's'
				|| list->format[idxtmp + 1] == 'S')
		{
			list->index += 1;
			if (list->format[idxtmp + 1] != '-')
				list->size -= 1;
		}
		if (list->format[idxtmp + 1] == 'd' || list->format[idxtmp + 1] == 'i')
			return (1);
		idxtmp++;
	}
	return (0);
}

int				ft_verif_numbersign(t_flags *list, int idxtmp)
{
	while (list->format[idxtmp] != '%' && list->format[idxtmp]
		&& ft_isflag(list->format[idxtmp]))
	{
		if (list->format[idxtmp] == '+')
			return (1);
		idxtmp++;
	}
	return (0);
}
