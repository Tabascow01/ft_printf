/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signflags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 15:47:05 by mchemakh          #+#    #+#             */
/*   Updated: 2017/02/15 03:23:39 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_signflag(t_flags *list)
{
	char	*newarg;
	char	*tmp;

	if (ft_atoi(list->args) >= 0)
	{
		newarg = ft_strnew((int)ft_strlen(list->args) + 1);
		newarg[0] = '+';
		tmp = newarg;
		newarg = ft_strjoin(tmp, list->args);
		ft_strdel(&tmp);
		ft_strdel(&list->args);
		list->args = ft_reallocf(newarg, 0);
	}
	else
		return ;
}
