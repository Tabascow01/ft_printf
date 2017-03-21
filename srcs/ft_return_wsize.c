/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return_wsize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/12 04:58:42 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/21 20:13:46 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_calcul_wsize_next(t_flags *list)
{
	if (list->conv == 'S' && list->option == 0 && !ft_check_flags(list))
		list->size += list->bytes - 2;
	else if (list->conv == 'S' && list->option > 0 && list->dbloption == 0)
		list->size += list->bytes - 3;
	else if (list->conv == 'S' && list->option > 0 && list->dbloption > 0)
		list->size += list->bytes - 4;
	else if (list->conv == 'S' && (int)ft_strlen(list->digit) > 0
			&& list->left == 0)
		list->size += list->bytes - (int)ft_strlen(list->digit) - 2;
	else if (list->conv == 'S' && (int)ft_strlen(list->digit) > 0
			&& list->left > 0)
		list->size += list->bytes - (int)ft_strlen(list->digit) - 3;
}

static void		ft_calcul_wsize(t_flags *list)
{
	if (list->conv == 'C' && list->option == 0 && !ft_check_flags(list))
		list->size += list->bytes - 2;
	else if (list->conv == 'C' && list->space > 0)
		list->size += list->bytes - list->space - 2;
	else if (list->conv == 'C' && list->precision > 0
			&& (int)ft_strlen(list->digit) > 0)
		list->size += list->bytes - (int)ft_strlen(list->digit) - 2;
	else if (list->conv == 'C' && list->option > 0 && list->dbloption == 0)
		list->size += list->bytes - 3;
	else if (list->conv == 'C' && list->option > 0 && list->dbloption > 0)
		list->size += list->bytes - 4;
	else if (list->conv == 'C' && list->sign == '+')
		list->size += list->bytes - 3;
	else if (list->conv == 'S' && list->space > 0)
		list->size += list->bytes - list->space - 2;
	else
		ft_calcul_wsize_next(list);
}

void			ft_return_wsize(t_flags *list)
{
	ft_calcul_wsize(list);
	list->ret = (int)ft_strlen(list->format);
	list->ret += list->size;
}
