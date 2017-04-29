/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_chr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 22:39:31 by mchemakh          #+#    #+#             */
/*   Updated: 2017/04/29 15:38:31 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_chr(t_flags *list, char c)
{
	if (list->left == 0 && (ft_atoi(list->digit) > 1
			|| list->args[0] == '\0') && !ft_isprint(c))
	{
		ft_putstr(list->args);
		ft_putchar(c);
	}
	else if (list->left > 0 && (ft_atoi(list->digit) > 1
			|| list->args[0] == '\0') && !ft_isprint(c))
	{
		list->size += 1;
		ft_putchar(c);
		ft_putstr(list->args);
	}
	else
		ft_putstr(list->args);
	ft_return_size(list);
	ft_strdel(&list->args);
	if (list->digit > 0)
		ft_strdel(&list->digit);
	ft_clear_flags(list);
	return (0);
}

void	ft_process_chr(t_flags *list)
{
	char c;

	if (ft_check_flags(list) && list->space == 0 && list->zero == 0
			&& list->sign == 0)
	{
		c = list->args[0];
		ft_process_flags(list);
		ft_print_chr(list, c);
	}
	else
	{
		ft_putchar(list->args[0]);
		ft_return_size(list);
		ft_strdel(&list->args);
		ft_clear_flags(list);
		return ;
	}
}
