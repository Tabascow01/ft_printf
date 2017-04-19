/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_long.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 00:23:05 by mchemakh          #+#    #+#             */
/*   Updated: 2017/04/06 04:30:09 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_long(t_flags *list, va_list args, char conv)
{
	char *tmp;

	if (conv == 'd' || conv == 'i')
		list->args = ft_litoa_base(va_arg(args, long), 10);
	else if (conv == 'o' || conv == 'O')
		list->args = ft_luitoa_base(va_arg(args, unsigned long), 8);
	else if (conv == 'x')
	{
		tmp = ft_luitoa_base(va_arg(args, unsigned long), 16);
		tmp = ft_strtolower(tmp);
		list->args = ft_reallocf(tmp, 0);
	}
	else if (conv == 'X')
	{
		tmp = ft_luitoa_base(va_arg(args, unsigned long), 16);
		tmp = ft_strtoupper(tmp);
		list->args = ft_reallocf(tmp, 0);
	}
	else if (conv == 'u' || conv == 'U')
		list->args = ft_luitoa_base(va_arg(args, unsigned long), 10);
	else
		return ;
}
