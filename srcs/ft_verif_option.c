/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_option.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 00:18:55 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/21 22:14:56 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_verif_option_next(t_flags *list, int *idxtmp)
{
	if (ft_verif_shortshort(list, (*idxtmp))
			&& ft_isshortshort_allowed(list, (*idxtmp)))
		list->dbloption = 'h';
	else if (ft_verif_longlong(list, (*idxtmp))
			&& ft_islonglong_allowed(list, (*idxtmp)))
		list->dbloption = 'l';
}

int				ft_verif_option(t_flags *list)
{
	int		idxtmp;

	idxtmp = list->index;
	while (list->format[idxtmp] != '\0' && ft_isflag(list->format[idxtmp]))
	{
		if (ft_verif_sizet(list, idxtmp)
				&& ft_issizet_allowed(list, idxtmp))
			list->option = 'z';
		else if (ft_verif_intmax(list, idxtmp)
				&& ft_isintmax_allowed(list, idxtmp))
			list->option = 'j';
		else if (ft_verif_short(list, idxtmp)
				&& ft_isshort_allowed(list, idxtmp))
			list->option = 'h';
		else if (ft_verif_long(list, idxtmp)
				&& ft_islong_allowed(list, idxtmp))
			list->option = 'l';
		ft_verif_option_next(list, &idxtmp);
		idxtmp++;
	}
	return (0);
}
