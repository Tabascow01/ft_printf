/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_oct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 01:34:20 by mchemakh          #+#    #+#             */
/*   Updated: 2017/04/18 14:13:24 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_oct(t_flags *list)
{
	ft_putstr(list->args);
	ft_return_size(list);
	ft_strdel(&list->args);
	if (list->digit > 0)
		ft_strdel(&list->digit);
	ft_clear_flags(list);
	return (0);
}

void	ft_process_oct(t_flags *list)
{
	if (ft_check_flags(list))
	{
		ft_process_flags(list);
		ft_print_oct(list);
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
