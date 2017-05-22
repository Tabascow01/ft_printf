/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_flags_d.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 23:39:44 by mchemakh          #+#    #+#             */
/*   Updated: 2017/05/22 04:32:36 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>//

void	ft_process_flags_d(t_flags *list)
{
	ft_decompose_digit(list);
	if (list->zero > 0 && list->precision == 0 && list->left == 0)
		ft_zeroflag(list);
	if (list->sign > 0)
		ft_signflag(list);
	if ((int)ft_strlen(list->digit) > 0 && list->left == 0
			&& list->precision > 0)
		ft_digitflag(list);
	else if ((int)ft_strlen(list->digit) > 0 && list->left > 0
			&& list->precision > 0)
		ft_ldigitflag(list);
	else if (list->space > 0 && list->precision == 0 && list->sign == 0)
		ft_spaceflag(list);
}
