/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_intmax.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 00:24:11 by mchemakh          #+#    #+#             */
/*   Updated: 2017/04/06 04:31:33 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_intmax(t_flags *list, va_list args, char conv)
{
	char *tmp;

	if (conv == 'd' || conv == 'i')
		list->args = ft_llitoa_base(va_arg(args, intmax_t), 10);
	else if (conv == 'o' || conv == 'O')
		list->args = ft_luitoa_base(va_arg(args, uintmax_t), 8);
	else if (conv == 'x')
	{
		tmp = ft_uitoa_base(va_arg(args, uintmax_t), 16);
		tmp = ft_strtolower(tmp);
		list->args = ft_reallocf(tmp, 0);
	}
	else if (conv == 'X')
	{
		tmp = ft_uitoa_base(va_arg(args, uintmax_t), 16);
		tmp = ft_strtoupper(tmp);
		list->args = ft_reallocf(tmp, 0);
	}
	else if (conv == 'u' || conv == 'U')
		list->args = ft_luitoa_base(va_arg(args, uintmax_t), 10);
	else
		return ;
}
