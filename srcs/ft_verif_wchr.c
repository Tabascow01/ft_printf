/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_wchr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 01:19:27 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/20 01:19:34 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_save_wchr(t_flags *list, va_list args)
{
	wchar_t		chr;

	if (list->option > 0)
	{
		list->index += 1;
		if (list->dbloption > 0)
			list->index += 1;
	}
	chr = va_arg(args, wchar_t);
	list->wargs = (wchar_t *)ft_strnew(sizeof(chr));
	list->wargs[0] = chr;
	list->wargs[1] = '\0';
	list->conv = 'C';
	ft_process_wchr(list);
}

int		ft_verif_wchr(t_flags *list, int idxtmp)
{
	while (list->format[idxtmp] && list->format[idxtmp] == '%'
			&& ft_isflag(list->format[idxtmp]))
		idxtmp++;
	if (list->format[idxtmp] == 'C' || (list->format[idxtmp] == 'c'
				&& list->option == 'l'))
		return (1);
	return (0);
}
