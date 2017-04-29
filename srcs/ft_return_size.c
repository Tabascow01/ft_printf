/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 15:16:52 by mchemakh          #+#    #+#             */
/*   Updated: 2017/04/29 15:37:39 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_size_conv_n(t_flags *list)
{
	if (list->option > 0 && list->dbloption == 0)
		list->size -= 1;
	else if (list->option > 0 && list->dbloption > 0)
		list->size -= 2;
}

static void		ft_size_conv(t_flags *list)
{
	ft_size_conv_n(list);
	if (list->digit > 0 && list->left == 0)
		ft_return_size_nn(list);
	else if (list->space > 0 && list->sign == 0 && list->noconv > 0)
		list->size += 1 - list->space - 2;
	else if (list->space > 0 && list->sign == 0 && list->args[0] != '\0')
		list->size += (int)ft_strlen(list->args) - list->space - 2;
	else if (list->sign > 0 && list->left == 0)
	{
		if (list->space > 0)
			list->size += (int)ft_strlen(list->args)
				- list->sign - list->space - 2;
		else
			list->size += (int)ft_strlen(list->args) - list->sign - 2;
	}
	else if (list->left > 0)
		ft_return_size_nnnn(list);
	else if (list->hash > 0 && list->conv != 'c' && list->args != 0)
		list->size += (int)ft_strlen(list->args) - 3;
	else if (list->hash > 0 && list->conv == 'c' && list->args[0] != '\0')
		list->size += (int)ft_strlen(list->args) - 3;
	else
		ft_return_size_nnnnn(list);
}

static void		ft_size_percent(t_flags *list)
{
	if (((int)ft_strlen(list->digit) > 0 || list->nbleft > 0)
			&& list->zero == 0)
	{
		list->size += (int)ft_strlen(list->args) -
			(int)ft_strlen(list->digit) - list->nbleft - 2;
	}
	else if (list->digit > 0 && list->zero == '0')
		list->size += (int)ft_strlen(list->args)
			- (int)ft_strlen(list->digit) - 2;
	else if (list->space > 0)
		list->size -= list->space + 1;
	else
		return ;
}

static void		ft_calcul_size(t_flags *list)
{
	if (list->percent > 0)
		ft_size_percent(list);
	else
		ft_size_conv(list);
}

void			ft_return_size(t_flags *list)
{
	ft_calcul_size(list);
	list->ret = (int)ft_strlen(list->format);
	list->ret += list->size;
	return ;
}
