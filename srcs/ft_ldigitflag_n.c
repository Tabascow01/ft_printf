/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldigitflag_n.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 04:11:18 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/27 04:13:17 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ldigitflag_nnnn(t_flags *list, int *size, int *i, char ** newarg)
{
	(*newarg) = NULL;
	(*i) = 0;
	(*size) = (int)ft_strlen(list->args);
}
