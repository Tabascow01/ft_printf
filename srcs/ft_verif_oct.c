/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_oct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 01:16:31 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/20 01:35:35 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_save_oct_low(t_flags *list, va_list args)
{
	char				*tmp;
	unsigned int		itmp;

	if (list->option != 0 || list->dbloption != 0)
		ft_process_option(list, args, 'o');
	else
	{
		itmp = va_arg(args, unsigned int);
		if (itmp > 0)
			tmp = ft_uitoa_base(itmp, 8);
		else
		{
			tmp = ft_strnew(1);
			tmp = ft_strcpy(tmp, "0");
		}
		list->args = ft_reallocf(tmp, 0);
	}
	list->conv = 'o';
	if (list->precision > 0 && (int)ft_strlen(list->digit) > 0
			&& ft_atoi(list->args) == 0 && list->zero == 0 && list->hash == 0)
		ft_bzero(list->args, ft_strlen(list->args) + 1);
	ft_process_oct(list);
}

void	ft_save_oct_up(t_flags *list, va_list args)
{
	char				*tmp;
	unsigned long int	itmp;

	if (list->option != 0 || list->dbloption != 0)
		ft_process_option(list, args, 'O');
	else
	{
		itmp = va_arg(args, unsigned long int);
		if (itmp > 0)
			tmp = ft_luitoa_base(itmp, 8);
		else
		{
			tmp = ft_strnew(1);
			tmp = ft_strcpy(tmp, "0");
		}
		list->args = ft_reallocf(tmp, 0);
	}
	list->conv = 'O';
	if (list->precision > 0 && (int)ft_strlen(list->digit) > 0
			&& ft_atoi(list->args) == 0 && list->zero == 0 && list->hash == 0)
		ft_bzero(list->args, ft_strlen(list->args) + 1);
	ft_process_oct(list);
}

int		ft_verif_oct_low(t_flags *list, int idxtmp)
{
	while (list->format[idxtmp] && list->format[idxtmp] == '%'
			&& ft_isflag(list->format[idxtmp])
			&& list->format[idxtmp] == 'o')
		idxtmp++;
	if (list->format[idxtmp] == 'o')
		return (1);
	return (0);
}

int		ft_verif_oct_up(t_flags *list, int idxtmp)
{
	while (list->format[idxtmp] && list->format[idxtmp] == '%'
			&& ft_isflag(list->format[idxtmp])
			&& list->format[idxtmp] == 'O')
		idxtmp++;
	if (list->format[idxtmp] == 'O')
		return (1);
	return (0);
}
