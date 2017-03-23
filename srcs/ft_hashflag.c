/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashflag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 15:52:28 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/19 22:37:00 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hashflag(t_flags *list)
{
	char	*newarg;
	char	*tmp;
	int		i;

	i = 0;
	newarg = ft_strnew((int)ft_strlen(list->args) + 2);
	while (list->args[i])
	{
		if ((list->conv == 'o' || list->conv == 'O') && newarg[0] != '0')
			newarg = ft_strcpy(newarg, "0");
		else if (list->conv == 'X' && newarg[0] != '0')
			newarg = ft_strcpy(newarg, "0X");
		else if (list->conv == 'x' && newarg[0] != '0')
			newarg = ft_strcpy(newarg, "0x");
		i++;
	}
	newarg = ft_strcat(newarg, list->args);
	tmp = list->args;
	list->args = ft_reallocf(newarg, 0);
	ft_strdel(&tmp);
}
