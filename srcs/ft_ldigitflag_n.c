/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldigitflag_n.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 04:11:18 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/28 23:50:58 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ldigit_nnnn(t_flags *list, int *size, int *i, char **newarg)
{
	(*newarg) = NULL;
	(*i) = 0;
	(*size) = (int)ft_strlen(list->args);
}

void	ft_ldigit_nnnnn(t_flags *list, char **newarg, int *digit, t_precs *lst)
{
	(*digit) = ft_atoi(list->digit);
	(*newarg) = ft_strnew((*digit) - lst->size);
}
