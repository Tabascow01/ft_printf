/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_chr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 22:37:32 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/15 21:44:09 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_save_chr(t_flags *list, va_list args)
{
	char	chr;

	list->args = ft_strnew(1);
	chr = va_arg(args, int);
	list->args[0] = chr;
	list->conv = 'c';
	ft_process_chr(list);
}

int		ft_verif_chr(t_flags *list, int idxtmp)
{
	while (list->format[idxtmp] && list->format[idxtmp] == '%'
			&& ft_isflag(list->format[idxtmp]))
		idxtmp++;
	if (list->format[idxtmp] == 'c' && list->option != 'l')
		return (1);
	return (0);
}
