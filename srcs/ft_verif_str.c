/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 00:13:59 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/20 01:18:11 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_save_str(t_flags *list, va_list args)
{
	char	*tmp;

	tmp = va_arg(args, char *);
	if (tmp == NULL && list->digit == 0)
	{
		list->args = ft_strnew(6);
		list->args = ft_strcpy(list->args, "(null)");
	}
	else if (list->precision == 0 || (int)ft_strlen(list->digit) > 1)
	{
		list->args = ft_strnew((int)ft_strlen(tmp));
		if (tmp != NULL)
			list->args = ft_strcpy(list->args, tmp);
	}
	list->conv = 's';
	ft_process_str(list);
}

int		ft_verif_str(t_flags *list, int idxtmp)
{
	while (list->format[idxtmp] && list->format[idxtmp] == '%'
			&& ft_isflag(list->format[idxtmp]))
		idxtmp++;
	if (list->format[idxtmp] == 's' && list->option != 'l')
		return (1);
	return (0);
}
