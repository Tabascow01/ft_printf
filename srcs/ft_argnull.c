/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argnull.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 21:46:28 by mchemakh          #+#    #+#             */
/*   Updated: 2017/05/10 04:09:15 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_argnull(t_flags *list)
{
	if (list->precision > 0 && (int)ft_strlen(list->digit) > 0
			&& !ft_ishex(list->args) && list->zero == 0)
	{
		ft_bzero(list->args, ft_strlen(list->args) + 1);
		return (1);
	}
	return (0);
}
