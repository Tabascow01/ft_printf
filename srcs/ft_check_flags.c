/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 01:10:21 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/01 11:24:04 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_flags(t_flags *list)
{
	if (list->space > 0 || list->sign > 0 || list->zero == '0'
			|| list->hash == '#' || list->precision > 0
			|| list->left == 1 || list->digit > 0)
		return (1);
	return (0);
}
