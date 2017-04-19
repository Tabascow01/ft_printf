/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 23:45:57 by mchemakh          #+#    #+#             */
/*   Updated: 2017/02/27 06:34:06 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_save_uint_up(t_flags *list, va_list args)
{
	char	*tmp;

	if (list->option != 0 || list->dbloption != 0)
		ft_process_option(list, args, 'U');
	else
	{
		tmp = ft_luitoa_base(va_arg(args, unsigned long), 10);
		list->args = ft_reallocf(tmp, 0);
	}
	if (list->precision > 0 && (int)ft_strlen(list->digit) > 0
			&& ft_atoi(list->args) == 0 && list->zero == 0)
		ft_bzero(list->args, ft_strlen(list->args) + 1);
	ft_process_uint(list);
}

void	ft_save_uint_low(t_flags *list, va_list args)
{
	char	*tmp;

	if (list->option != 0 || list->dbloption != 0)
		ft_process_option(list, args, 'u');
	else
	{
		tmp = ft_uitoa_base(va_arg(args, unsigned int), 10);
		list->args = ft_reallocf(tmp, 0);
	}
	list->conv = 'u';
	if (list->precision > 0 && (int)ft_strlen(list->digit) > 0
			&& ft_atoi(list->args) == 0 && list->zero == 0)
		ft_bzero(list->args, ft_strlen(list->args) + 1);
	ft_process_uint(list);
}

int		ft_verif_uint_up(t_flags *list, int idxtmp)
{
	while (list->format[idxtmp] && list->format[idxtmp] == '%'
			&& ft_isflag(list->format[idxtmp])
			&& list->format[idxtmp] == 'U')
		idxtmp++;
	if (list->format[idxtmp] == 'U')
		return (1);
	return (0);
}

int		ft_verif_uint_low(t_flags *list, int idxtmp)
{
	while (list->format[idxtmp] && list->format[idxtmp] == '%'
			&& ft_isflag(list->format[idxtmp])
			&& list->format[idxtmp] == 'u')
		idxtmp++;
	if (list->format[idxtmp] == 'u')
		return (1);
	return (0);
}
