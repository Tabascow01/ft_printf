/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 01:12:28 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/21 22:10:42 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_vrf_cv_nnnn(t_flags *list, int *idxtmp, va_list args)
{
	int ret;

	ret = 0;
	if (ft_verif_oct_up(list, (*idxtmp)))
	{
		list->index += 1;
		ft_save_oct_up(list, args);
		ret = 1;
	}
	else if (ft_verif_chr(list, (*idxtmp)) && list->conv != 'C')
	{
		list->index += 1;
		ft_save_chr(list, args);
		ret = 1;
	}
	else
		ret = ft_vrf_cv_nnnnn(list, &(*idxtmp), args);
	return (ret);
}

static int		ft_vrf_cnv_nnn(t_flags *list, int *idxtmp, va_list args)
{
	int ret;

	ret = 0;
	if (ft_verif_uint_up(list, (*idxtmp)))
	{
		list->index += 1;
		ft_save_uint_up(list, args);
		ret = 1;
	}
	else if (ft_verif_oct_low(list, (*idxtmp)))
	{
		list->index += 1;
		ft_save_oct_low(list, args);
		ret = 1;
	}
	else
		ret = ft_vrf_cv_nnnn(list, &(*idxtmp), args);
	return (ret);
}

static int		ft_vrf_cnv_nn(t_flags *list, int *idxtmp, va_list args)
{
	int ret;

	ret = 0;
	if (ft_verif_hex_up(list, (*idxtmp)))
	{
		list->index += 1;
		ft_save_hex_up(list, args);
		ret = 1;
	}
	else if (ft_verif_uint_low(list, (*idxtmp)))
	{
		list->index += 1;
		ft_save_uint_low(list, args);
		ret = 1;
	}
	else
		ret = ft_vrf_cnv_nnn(list, &(*idxtmp), args);
	return (ret);
}

static int		ft_verif_cnv_n(t_flags *list, int *idxtmp, va_list args)
{
	int ret;

	ret = 0;
	if (ft_verif_int(list, (*idxtmp)))
	{
		list->index += 1;
		ft_save_int(list, args);
		ret = 1;
	}
	else if (ft_verif_hex_low(list, (*idxtmp)))
	{
		list->index += 1;
		ft_save_hex_low(list, args);
		ret = 1;
	}
	else
		ret = ft_vrf_cnv_nn(list, &(*idxtmp), args);
	return (ret);
}

int				ft_verif_conv(t_flags *list, va_list args)
{
	int		idxtmp;
	int		pass;
	int		passnoconv;
	int		ret;

	pass = 0;
	ret = 0;
	passnoconv = 0;
	idxtmp = list->index;
	while (list->format[idxtmp] != '\0' && ret == 0)
	{
		if (ft_verif_noconv(list, idxtmp))
			ret = ft_verif_noconv(list, idxtmp);
		else
			ret = ft_verif_cnv_n(list, &idxtmp, args);
		idxtmp++;
	}
	if ((ret == 'Z' || ret == 'R') && ft_check_flags(list)
			&& list->space == 0)
		ft_process_flags(list);
	else if (ret == 0 && !ft_check_flags(list))
		list->noconv = 1;
	return (ret);
}
