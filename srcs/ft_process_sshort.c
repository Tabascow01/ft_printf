/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_sshort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 00:22:51 by mchemakh          #+#    #+#             */
/*   Updated: 2017/04/06 04:29:40 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_sshort(t_flags *list, va_list args, char conv)
{
	char *tmp;

	if (conv == 'd' || conv == 'i')
		list->args = ft_itoa_base((char)va_arg(args, int), 10);
	else if (conv == 'o')
		list->args = ft_uctoa_base((unsigned char)va_arg(args, int), 8);
	else if (conv == 'O')
		list->args = ft_uitoa_base(va_arg(args, unsigned int), 8);
	else if (conv == 'x')
	{
		tmp = ft_uctoa_base((unsigned char)va_arg(args, int), 16);
		tmp = ft_strtolower(tmp);
		list->args = ft_reallocf(tmp, 0);
	}
	else if (conv == 'X')
	{
		tmp = ft_uctoa_base((unsigned char)va_arg(args, int), 16);
		tmp = ft_strtoupper(tmp);
		list->args = ft_reallocf(tmp, 0);
	}
	else if (conv == 'u')
		list->args = ft_uctoa_base((unsigned char)va_arg(args, int), 10);
	else if (conv == 'U')
		list->args = ft_uitoa_base(va_arg(args, unsigned int), 10);
}
