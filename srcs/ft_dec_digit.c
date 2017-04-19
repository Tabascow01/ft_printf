/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_digit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 14:29:45 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/02 14:39:08 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_decompose_digit(t_flags *list)
{
	int		i;

	i = 0;
	if (list->digit != NULL)
	{
		list->dig1 = ft_atoi(list->digit);
		while (list->digit[i] && list->digit[i] != '.')
			i++;
		if (list->digit[i] == '.')
			i++;
		list->dig2 = ft_atoi(&list->digit[i]);
	}
}
