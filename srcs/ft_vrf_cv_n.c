/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vrf_cv_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 21:29:28 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/21 22:11:12 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_vf_cv_next(t_flags *list, int *idxtmp, va_list args)
{
	int ret;

	ret = 0;
	if (ft_verif_int_up(list, (*idxtmp)))
	{
		list->index += 1;
		ft_save_int_up(list, args);
		ret = 1;
	}
	else if (ft_verif_wchr(list, (*idxtmp)) && list->conv != 'c')
	{
		list->index += 1;
		ft_save_wchr(list, args);
		ret = 1;
	}
	else if (ft_verif_wstr(list, (*idxtmp)) && list->conv != 's')
	{
		list->index += 1;
		ft_save_wstr(list, args);
		ret = 1;
	}
	return (ret);
}

int				ft_vrf_cv_nnnnn(t_flags *list, int *idxtmp, va_list args)
{
	int ret;

	ret = 0;
	if (ft_verif_ptr(list, (*idxtmp)))
	{
		list->index += 1;
		ft_save_ptr(list, args);
		ret = 1;
	}
	else if (ft_verif_str(list, (*idxtmp)) && list->conv != 'S')
	{
		list->index += 1;
		ft_save_str(list, args);
		ret = 1;
	}
	else
		ret = ft_vf_cv_next(list, &(*idxtmp), args);
	return (ret);
}
