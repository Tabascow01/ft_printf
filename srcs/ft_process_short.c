/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_short.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 00:22:45 by mchemakh          #+#    #+#             */
/*   Updated: 2017/04/10 03:08:56 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_short(t_flags *list, va_list args, char conv)
{
	char *tmp;

	if (conv == 'd' || conv == 'i')
		list->args = ft_sitoa_base((short int)va_arg(args, int), 10);
	else if (conv == 'o' || conv == 'O')
		list->args = ft_ustoa_base((unsigned short)va_arg(args, int), 8);
	else if (conv == 'x')
	{
		tmp = ft_ustoa_base((unsigned short)va_arg(args, int), 16);
		tmp = ft_strtolower(tmp);
		list->args = ft_reallocf(tmp, 0);
	}
	else if (conv == 'X')
	{
		tmp = ft_ustoa_base((unsigned short)va_arg(args, int), 16);
		tmp = ft_strtoupper(tmp);
		list->args = ft_reallocf(tmp, 0);
	}
	else if (conv == 'u')
		list->args = ft_ustoa_base((unsigned short)va_arg(args, int), 10);
	else if (conv == 'U')
		list->args = ft_luitoa_base(va_arg(args, long int), 10);
	else
		return ;
}
