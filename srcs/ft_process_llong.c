/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_llong.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 00:22:59 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/21 20:08:56 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_llong(t_flags *list, va_list args, char conv)
{
	int i;

	i = -1;
	if (conv == 'd' || conv == 'i')
		list->args = ft_llitoa_base(va_arg(args, long long int), 10);
	else if (conv == 'o' || conv == 'O')
		list->args = ft_luitoa_base(va_arg(args, unsigned long long), 8);
	else if (conv == 'x')
	{
		list->args = ft_luitoa_base(va_arg(args, unsigned long long), 16);
		while (list->args[i++])
			list->args[i] = ft_tolower(list->args[i]);
	}
	else if (conv == 'X')
	{
		list->args = ft_luitoa_base(va_arg(args, unsigned long long), 16);
		while (list->args[i++])
			list->args[i] = ft_toupper(list->args[i]);
	}
	else if (conv == 'u' || conv == 'U')
		list->args = ft_luitoa_base(va_arg(args, unsigned long long), 10);
	else
		return ;
}
