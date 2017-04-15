/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 01:13:08 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/14 03:23:09 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_save_int(t_flags *list, va_list args)
{
	char	*tmp;

	if (list->option != 0 || list->dbloption != 0)
		ft_process_option(list, args, 'd');
	else
	{
		tmp = ft_itoa_base(va_arg(args, int), 10);
		list->args = ft_reallocf(tmp, 0);
	}
	list->conv = 'd';
	if (list->precision > 0 && (int)ft_strlen(list->digit) > 0
			&& ft_atoi(list->args) == 0 && list->zero == 0)
		ft_bzero(list->args, ft_strlen(list->args) + 1);
	ft_process_int(list);
}

int		ft_verif_int(t_flags *list, int idxtmp)
{
	while (list->format[idxtmp] && list->format[idxtmp] == '%'
			&& (list->format[idxtmp] == 'd' || list->format[idxtmp] == 'i')
			&& ft_isflag(list->format[idxtmp]))
		idxtmp++;
	if (list->format[idxtmp] == 'd' || list->format[idxtmp] == 'i')
		return (1);
	return (0);
}
