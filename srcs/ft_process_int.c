/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 01:11:53 by mchemakh          #+#    #+#             */
/*   Updated: 2017/04/10 02:35:23 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>//

int		ft_print_int(t_flags *list)
{
	ft_putstr(list->args);
	ft_return_size(list);
	ft_strdel(&list->args);
	if (list->digit > 0)
		ft_strdel(&list->digit);
	ft_clear_flags(list);
	return (0);
}

void	ft_process_int(t_flags *list)
{
	if (ft_check_flags(list))
	{
		ft_process_flags(list);
		ft_print_int(list);
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
