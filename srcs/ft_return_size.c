/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 15:16:52 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/20 01:16:16 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_size_conv(t_flags *list)
{
	if (list->option > 0 && list->dbloption == 0)
		list->size -= 1;
	else if (list->option > 0 && list->dbloption > 0)
		list->size -= 2;
	if (list->digit > 0 && list->left == 0)
	{
		if (list->sign > 0 && list->precision == 0 && list->zero == 0)
			list->size += (int)ft_strlen(list->args)
				- (int)ft_strlen(list->digit) - list->sign - 1;
		else if (list->sign > 0 && list->precision == 0 && list->zero == '0')
			list->size += (int)ft_strlen(list->args)
				- (int)ft_strlen(list->digit) - list->sign - 2;
		else if (list->space > 0 && list->precision > 0)
			list->size += (int)ft_strlen(list->args)
				- (int)ft_strlen(list->digit) - list->space - 2;
		else if (list->sign > 0 && list->precision > 0)
			list->size += (int)ft_strlen(list->args)
				- (int)ft_strlen(list->digit) - list->sign - 2;
		else if (list->digit > 0 && list->hash == '#' && list->conv != 'p')
			list->size += (int)ft_strlen(list->args)
				- (int)ft_strlen(list->digit) - 3;
		else if (list->conv == 'c'
				&& list->args[ft_atoi(list->digit) - 1] == '\0')
			list->size += (int)ft_strlen(list->args)
				- (int)ft_strlen(list->digit) - 1;
		else if (list->conv == 'c'
				&& (int)ft_strlen(list->args) == ft_atoi(list->digit) - 1)
			list->size += (int)ft_strlen(list->digit) - 2;
		else if (list->conv == 'c' && list->precision > 0
				&& list->args[0] != '\0')
			list->size += (int)ft_strlen(list->args)
				- (int)ft_strlen(list->digit) - 2;
		else if (list->zero == '0' && list->space > 0)
			list->size = (int)ft_strlen(list->args)
				- (int)ft_strlen(list->digit) - 3;
		else if (list->conv == 'c' && list->precision == 0)
			list->size += (int)ft_strlen(list->args)
				- (int)ft_strlen(list->digit) - 2;
		else if (list->conv == 'c' && list->precision > 0
				&& list->args[0] == '\0')
			list->size += (int)ft_strlen(list->digit) - list->precision - 4;
		else if (list->noconv > 0 && list->zero == '0')
			list->size += (int)ft_strlen(list->args)
				- (int)ft_strlen(list->digit) - 1;
		else if (list->conv == 'p' && list->precision > 0)
			list->size += (int)ft_strlen(list->args)
				- (int)ft_strlen(list->digit) - 2;
		else
			list->size += (int)ft_strlen(list->args)
				- (int)ft_strlen(list->digit) - 2;
	}
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
	{
		if (list->noconv > 0)
			list->size += (int)ft_strlen(list->args)
				- (int)ft_strlen(list->digit) - 2;
		else if (list->sign == 0 && list->space == 0
				&& list->hash == 0 && list->zero == 0)
			list->size += (int)ft_strlen(list->args)
				- (int)ft_strlen(list->digit) - list->left - 2;
		else if (list->precision > 0 && list->sign > 0 && list->hash == 0)
			list->size += (int)ft_strlen(list->args)
				- (int)ft_strlen(list->digit) - list->left - list->sign - 2;
		else if (list->sign > 0 && list->hash == 0 && list->zero == 0)
			list->size += (int)ft_strlen(list->args)
				- (int)ft_strlen(list->digit) - list->left - list->sign - 1;
		else if (list->hash == '#' && list->zero == '0')
			list->size += (int)ft_strlen(list->args)
				- (int)ft_strlen(list->digit) - list->left - 3;
		else if (list->hash == '#' && (int)ft_strlen(list->digit) > 0)
			list->size += (int)ft_strlen(list->args)
				- (int)ft_strlen(list->digit) - list->left - 3;
		else if (list->zero == '0' && list->digit > 0)
			list->size += (int)ft_strlen(list->args)
				- list->left - (int)ft_strlen(list->digit) - 2;
	}
	else if (list->hash == '#' && list->conv != 'c' && list->args != 0)
		list->size += (int)ft_strlen(list->args) - 3;
	else if (list->hash == '#' && list->conv == 'c' && list->args[0] != '\0')
		list->size += (int)ft_strlen(list->args) - 3;
	else if (list->hash == 0 && list->space == 0
			&& list->conv == 'c' && list->args[0] == 0)
		list->size += (int)ft_strlen(list->args) - 1;
	else if (list->space > 0 && (list->conv == 's'))
		list->size += (int)ft_strlen(list->args) - 3;
	else
		list->size += (int)ft_strlen(list->args) - 2;
}

static void		ft_size_percent(t_flags *list)
{
	if (list->digit > 0 && list->zero == 0)
	{
		list->size += (int)ft_strlen(list->args) -
			(int)ft_strlen(list->digit) - 2;
		if (list->left > 0)
			list->size -= 1;
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
