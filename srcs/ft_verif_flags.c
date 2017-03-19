/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 00:59:31 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/14 02:54:58 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_verif_flags(t_flags *list)
{
	int		idxtmp;

	idxtmp = list->index;
	while (list->format[idxtmp] && ft_isflag(list->format[idxtmp]))
	{
		if (ft_verif_hash(list, idxtmp) &&
				ft_ishash_allowed(list, idxtmp) && list->hash == 0)
		{
			list->hash = '#';
		}
		if (ft_verif_numbersign(list, idxtmp) &&
				ft_isnbsign_allowed(list, idxtmp) && list->sign == 0)
		{
			ft_save_sign(list, idxtmp);
		}
		if	(ft_verif_zero(list, idxtmp) &&
				ft_iszero_allowed(list, idxtmp) && list->zero == 0)
		{
			list->zero = '0';
		}
		if (ft_verif_spcs(list, idxtmp) &&
				ft_isspcs_allowed(list, idxtmp) && list->space == 0)
		{
			ft_save_spcs(list, idxtmp);
		}
		if (ft_verif_left(list, idxtmp) &&
				ft_isleft_allowed(list, idxtmp) && list->left == 0)
		{
			list->index += 1;
			list->left = 1;
		}
		if (ft_verif_number(list, idxtmp) &&
				ft_isdigit_allowed(list, idxtmp) && list->digit == 0)
		{
			ft_save_digit(list, idxtmp);
		}
		if (ft_verif_percent(list, idxtmp) && list->percent == 0)
		{
			list->index += 1;
			list->percent = 1;
			ft_process_percent(list);
			return (0);
		}
		idxtmp++;
	}
	//printf("sign[%d]\nhash[%c]\ndigit[%s]\nleft[%d]\nspace[%d]\nzero[%c]\nprecision[%d]\n",list->sign,list->hash,list->digit,list->left,list->space,list->zero,list->precision);
	return (0);
}
