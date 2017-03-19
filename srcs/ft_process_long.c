/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_long.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 00:23:05 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/19 23:06:04 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_long(t_flags *list, va_list args, char conv)
{
	int i;

	i = 0;
	if (conv == 'd' || conv == 'i')
		list->args = ft_litoa_base(va_arg(args, long), 10);
	else if (conv == 'o' || conv == 'O')
		list->args = ft_luitoa_base(va_arg(args, unsigned long), 8);
	else if (conv == 'x')
	{
		list->args = ft_luitoa_base(va_arg(args, unsigned long), 16);
		while (list->args[i])
		{
			list->args[i] = ft_tolower(list->args[i]);
			i++;
		}
	}
	else if (conv == 'X')
	{
		list->args = ft_luitoa_base(va_arg(args, unsigned long), 16);
		while (list->args[i])
		{
			list->args[i] = ft_toupper(list->args[i]);
			i++;
		}
	}
	else if (conv == 'u' || conv == 'U')
		list->args = ft_luitoa_base(va_arg(args, unsigned long), 10);
	else
		return ;
}