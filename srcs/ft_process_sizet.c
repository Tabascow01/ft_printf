/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_sizet.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 00:23:19 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/21 20:09:49 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_sizet(t_flags *list, va_list args, char conv)
{
	int i;

	i = -1;
	if (conv == 'd' || conv == 'i')
		list->args = ft_llitoa_base(va_arg(args, long long int), 10);
	else if (conv == 'o' || conv == 'O')
		list->args = ft_luitoa_base(va_arg(args, size_t), 8);
	else if (conv == 'x')
	{
		list->args = ft_luitoa_base(va_arg(args, size_t), 16);
		while (list->args[i++])
			list->args[i] = ft_tolower(list->args[i]);
	}
	else if (conv == 'X')
	{
		list->args = ft_luitoa_base(va_arg(args, size_t), 16);
		while (list->args[i++])
			list->args[i] = ft_toupper(list->args[i]);
	}
	else if (conv == 'u' || conv == 'U')
		list->args = ft_luitoa_base(va_arg(args, size_t), 10);
	else
		return ;
}
