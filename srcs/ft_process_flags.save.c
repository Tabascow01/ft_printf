/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 01:12:04 by mchemakh          #+#    #+#             */
/*   Updated: 2017/05/07 22:52:39 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_process_flags_n(t_flags *list)
{
	if (list->digit != 0)
	{
		if (list->digit[0] == '0' && list->precision == 0)
			list->zero = '0';
		else if (list->digit[0] == '0' && list->precision > 0
				&& (list->conv == 'c' || list->conv == 's' || list->noconv > 0
					|| list->conv == 'C' || list->conv == 'S'))
			list->zero = '0';
	}
	if (list->sign > 0 && list->conv != 'p' && list->conv != 'c'
			&& list->conv != 's' && list->conv != 'C')
		ft_signflag(list);
	if (list->hash == '#' && ft_ishex(list->args) != 0
			&& ((list->zero == 0 || list->left > 0) && list->conv != 'p'
				&& list->conv != 'c') && (((list->precision == 0))
					|| (list->precision > 0
					&& list->dig1 <= (int)ft_strlen(list->args)
					&& list->dig2 <= (int)ft_strlen(list->args))))
	{
		ft_hashflag(list);
		if (list->dig2 > 0 && list->precision > 0)
			list->hash = 0;
	}
}

static void		ft_process_flags_nn(t_flags *list)
{
	if (list->conv == 'p' && (int)ft_strlen(list->args) < 3
			&& (int)ft_strlen(list->digit) > 1 && list->digit[1] != '0')
	{
		ft_bzero(list->args, ft_strlen(list->args));
		list->hash = '#';
	}
	else if (list->conv == 'p' && (int)ft_strlen(list->args) > 2
			&& (int)ft_strlen(list->digit) > 2
			&& (list->dig1 < list->dig2))
	{
		ft_cut_lststr(list, 2);
		list->hash = '#';
	}
}

static void		ft_process_flags_nnext(t_flags *list)
{
	if (list->conv == 'p' && (int)ft_strlen(list->args) < 3
			&& (int)ft_strlen(list->digit) > 1 && list->digit[1] != '0')
		list->hash = 0;
	else if (list->conv == 'p' && (int)ft_strlen(list->args) > 3
			&& (int)ft_strlen(list->digit) > 2)
		list->hash = 0;
}

static void		ft_process_flags_nnn(t_flags *list)
{
	if ((list->dig1 > 0 || list->dig2 > 0
			|| (list->dig1 > 0 && list->dig2 > 0))
			&& list->left == 0 && list->conv != 'S'
			&& list->conv != 'C' && list->noconv == 0)
	{
		ft_process_flags_nn(list);
		if ((list->conv == 'C' || list->conv == 'c') && list->precision > 0)
			return ;
		else
			ft_digitflag(list);
		ft_process_flags_nnext(list);
	}
	else if (list->space > 0 && list->conv != 'S')
	{
		if (list->args[0] == '-' || list->sign > 0 ||
				list->conv == 's' || list->conv == 'p'
				|| list->conv == 'x' || list->conv == 'X'
				|| list->conv == 'o' || list->conv == 'O')
			return ;
		if (list->percent == 0 && list->args[0] != '\0')
			ft_spaceflag(list);
	}
	else
		ft_process_flags_nnnn(list);
}

void			ft_process_flags(t_flags *list)
{
	ft_decompose_digit(list);
	ft_process_flags_n(list);
	if (list->left > 0 && list->conv != 'S' && list->conv != 'C'
		&& list->noconv == 0)
	{
		if (list->dig1 > 0 || list->dig2 > 0 || list->precision > 0 ||
				(list->dig1 > 0 && list->dig2 > 0 && list->precision > 0))
			ft_ldigitflag(list);
		else if (list->space > 0)
			ft_lspaceflag(list);
	}
	else if (list->zero == '0' && (list->precision == 0 || list->conv == 'c'
				|| (list->conv == 's' || list->noconv > 0))
			&& list->conv != 'C' && list->conv != 'S')
	{
		ft_zeroflag(list);
		if (list->hash == '#' || list->conv == 'p')
			ft_zhashflag(list);
		if (list->space > 0)
			ft_spaceflag(list);
	}
	else
		ft_process_flags_nnn(list);
}
