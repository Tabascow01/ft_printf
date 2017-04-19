/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 00:00:30 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/02 13:19:47 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_save_ptr(t_flags *list, va_list args)
{
	char	*tmp;
	char	*argstmp;

	if (list->option > 0)
		list->index += 1;
	if (list->dbloption > 0)
		list->index += 1;
	tmp = ft_litoa_base(va_arg(args, intptr_t), 16);
	argstmp = list->args;
	list->args = ft_strnew(ft_strlen(tmp) + 2);
	list->args = ft_strjoin("0x", tmp);
	ft_strdel(&tmp);
	list->args = ft_reallocf(list->args, 0);
	ft_strdel(&argstmp);
	if (list->precision > 0 && (int)ft_strlen(list->digit) > 0
			&& list->args[2] == '0' && list->zero == 0)
	{
		ft_bzero(list->args, ft_strlen(list->args) + 1);
		list->args = ft_strcpy(list->args, "0x");
	}
	list->conv = 'p';
	ft_process_ptr(list);
}

int		ft_verif_ptr(t_flags *list, int idxtmp)
{
	while (list->format[idxtmp] && list->format[idxtmp] == '%'
			&& ft_isflag(list->format[idxtmp]))
		idxtmp++;
	if (list->format[idxtmp] == 'p' || list->format[idxtmp] == 'p')
		return (1);
	return (0);
}
