/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signflags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 15:47:05 by mchemakh          #+#    #+#             */
/*   Updated: 2017/04/12 08:27:17 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_signflag(t_flags *list)
{
	char	*newarg;
	char	*tmp;

	if (ft_atoi(list->args) >= 0)
	{
		newarg = ft_strnew((int)ft_strlen(list->args) + 1);
		newarg[0] = '+';
		tmp = ft_strjoin(newarg, list->args);
		ft_strdel(&newarg);
		ft_strdel(&list->args);
		list->args = ft_reallocf(tmp, 0);
	}
	else
		return ;
}
