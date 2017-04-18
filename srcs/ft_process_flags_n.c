/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_flags_n.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 01:48:06 by mchemakh          #+#    #+#             */
/*   Updated: 2017/04/18 13:34:48 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_flags_nnnn(t_flags *list)
{
	if (((int)ft_strlen(list->digit) > 0 && list->conv == 'S'
			&& list->left == 0 && list->zero == 0)
			|| (list->conv == 'S' && list->zero == '0'
			&& list->precision > 0))
		ft_wdigitflag(list);
	if (list->left > 0 && list->conv == 'S' && list->zero == 0)
		ft_wldigitflag(list);
	else if (list->zero == '0' && (list->conv == 'C' || list->conv == 'S')
			&& list->precision == 0)
		ft_wzeroflag(list);
}
