/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_option.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 00:23:33 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/15 21:37:07 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_option(t_flags *list, va_list args, char conv)
{
	list->index += 1;
	if (list->option == 'z' && list->dbloption == 0)
		ft_process_sizet(list, args, conv);
	else if (list->option == 'j' && list->dbloption == 0)
		ft_process_intmax(list, args, conv);
	else if (list->option == 'h' && list->dbloption == 0)
		ft_process_short(list, args, conv);
	else if (list->option == 'l' && list->dbloption == 0)
		ft_process_long(list, args, conv);
	else
	{
		list->index += 1;
		if (list->dbloption == 'h' && list->option == 'h')
			ft_process_sshort(list, args, conv);
		else if (list->dbloption == 'l' && list->option == 'l')
			ft_process_llong(list, args, conv);
		else
			return ;
	}
}
