/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return_size_n.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 02:18:05 by mchemakh          #+#    #+#             */
/*   Updated: 2017/04/29 16:44:00 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_return_size_nnnnn(t_flags *list)
{
	if (list->hash == 0 && list->space == 0
			&& list->conv == 'c' && list->args[0] == 0)
		list->size += (int)ft_strlen(list->args) - 1;
	else if (list->space > 0 && (list->conv == 's'))
		list->size += (int)ft_strlen(list->args) - 3;
	else
		list->size += (int)ft_strlen(list->args) - 2;
}

void	ft_return_size_nnnn(t_flags *list)
{
	if (list->noconv > 0)
		list->size += (int)ft_strlen(list->args)
			- (int)ft_strlen(list->digit) - 2;
	else if (list->conv == 's' && ft_strlen(list->digit) > 0)
		list->size += (int)ft_strlen(list->args) - (int)ft_strlen(list->digit)
			- list->nbleft - 2;
	else if (list->sign == 0 && list->space == 0
			&& list->hash == 0 && list->zero == 0 && ft_atoi(list->args) != 0)
		list->size += (int)ft_strlen(list->args)
			- (int)ft_strlen(list->digit) - list->nbleft - 2;
	else if (list->precision > 0 && list->sign > 0 && list->hash == 0)
		list->size += (int)ft_strlen(list->args)
			- (int)ft_strlen(list->digit) - list->nbleft - list->sign - 2;
	else if (list->sign > 0 && list->hash == 0 && list->zero == 0)
		list->size += (int)ft_strlen(list->args)
			- (int)ft_strlen(list->digit) - list->nbleft - list->sign - 2;
	else if (list->hash == '#' && list->zero == '0')
		list->size += (int)ft_strlen(list->args)
			- (int)ft_strlen(list->digit) - list->nbleft - 3;
	else if (list->hash == '#' && (int)ft_strlen(list->digit) > 0)
		list->size += (int)ft_strlen(list->args)
			- (int)ft_strlen(list->digit) - list->nbleft - 3;
	else
		ft_return_size_nnnn2(list);
}

void	ft_return_size_nnn2(t_flags *list)
{
	if (list->conv == 'p' && list->precision > 0)
		list->size += (int)ft_strlen(list->args)
			- (int)ft_strlen(list->digit) - 2;
	else
		list->size += (int)ft_strlen(list->args)
			- (int)ft_strlen(list->digit) - 2;
}

void	ft_return_size_nnn(t_flags *list)
{
	if (list->left > 1)
		list->size += (int)ft_strlen(list->args) - (int)ft_strlen(list->digit)
			- list->nbleft - 2;
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
	else
		ft_return_size_nnn2(list);
}

void	ft_return_size_nn(t_flags *list)
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
	{
		list->size += (int)ft_strlen(list->args)
			- (int)ft_strlen(list->digit) - 3;
	}
	else if (list->conv == 'c' && list->args[ft_atoi(list->digit) - 1] == '\0')
		list->size += (int)ft_strlen(list->args)
			- (int)ft_strlen(list->digit) - 1;
	else
		ft_return_size_nnn(list);
}
