/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_int_up.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 07:16:25 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/20 01:12:36 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_save_int_up(t_flags *list, va_list args)
{
	char	*tmp;

	if (list->option > 0)
		ft_process_option(list, args, 'D');
	tmp = ft_litoa_base(va_arg(args, long int), 10);
	list->args = ft_reallocf(tmp, 0);
	if (list->precision > 0 && (int)ft_strlen(list->digit) > 0
			&& ft_atoi(list->args) == 0 && list->zero == 0)
		ft_bzero(list->args, ft_strlen(list->args) + 1);
	ft_process_int_up(list);
}

int		ft_verif_int_up(t_flags *list, int idxtmp)
{
	while (list->format[idxtmp] && list->format[idxtmp] == '%'
			&& ft_isflag(list->format[idxtmp]))
		idxtmp++;
	if (list->format[idxtmp] == 'D')
		return (1);
	return (0);
}
