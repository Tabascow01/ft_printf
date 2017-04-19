/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_wstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 01:18:21 by mchemakh          #+#    #+#             */
/*   Updated: 2017/04/18 14:16:43 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_save_wstr(t_flags *list, va_list args)
{
	wchar_t		*tmp;

	tmp = va_arg(args, wchar_t *);
	if (list->option > 0)
	{
		list->index += 1;
		if (list->dbloption > 0)
			list->index += 1;
	}
	if (tmp == NULL)
	{
		list->wargs = (wchar_t *)ft_strnew(6 * 4);
		list->wargs = ft_memcpy(list->wargs, L"(null)", 6 * 4 - 1);
	}
	else
	{
		list->wargs = (wchar_t *)ft_strnew(ft_wstrlen(tmp) * sizeof(tmp));
		if (tmp != NULL)
			list->wargs = ft_memcpy(list->wargs, tmp,
					ft_wstrlen(tmp) * sizeof(tmp));
		list->wargs[(int)ft_wstrlen(tmp)] = '\0';
	}
	list->conv = 'S';
	ft_process_wstr(list);
}

int		ft_verif_wstr(t_flags *list, int idxtmp)
{
	while (list->format[idxtmp] && list->format[idxtmp] == '%'
			&& ft_isflag(list->format[idxtmp]))
		idxtmp++;
	if (list->format[idxtmp] == 'S' || (list->format[idxtmp] == 's'
				&& list->option == 'l'))
		return (1);
	return (0);
}
