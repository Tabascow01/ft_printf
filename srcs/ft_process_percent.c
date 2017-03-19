/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_percent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 02:12:44 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/15 20:06:16 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_percent(t_flags *list)
{
	ft_putstr(list->args);
	ft_return_size(list);
	ft_strdel(&list->args);
	if (list->digit > 0)
		ft_strdel(&list->digit);
	ft_clear_flags(list);
	list->percent = 1;
	return (0);
}

void		ft_process_percent(t_flags *list)
{
	list->precision = 0;
	if (ft_check_flags(list))
	{
		list->args = ft_strnew(1);
		list->args[0] = '%';
		ft_process_flags(list);
		ft_print_percent(list);
	}
	else
	{
		ft_putchar('%');
		list->size -= 1;
		ft_return_size(list);
		ft_clear_flags(list);
		list->percent = 1;
	}
}
