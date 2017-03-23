/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_int_up.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 07:18:32 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/19 23:07:13 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_int_up(t_flags *list)
{
	ft_putstr(list->args);
	ft_return_size(list);
	ft_strdel(&list->args);
	if (list->digit > 0)
		ft_strdel(&list->digit);
	ft_clear_flags(list);
	return (0);
}

void	ft_process_int_up(t_flags *list)
{
	if (ft_check_flags(list))
	{
		ft_process_flags(list);
		ft_print_int_up(list);
	}
	else
	{
		ft_putstr(list->args);
		ft_return_size(list);
		ft_strdel(&list->args);
		ft_clear_flags(list);
		return ;
	}
}
