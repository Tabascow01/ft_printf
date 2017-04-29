/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zeroflag_n.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 15:45:33 by mchemakh          #+#    #+#             */
/*   Updated: 2017/04/29 16:22:21 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strzhash_n(t_flags *list, char ***str, char **tmparg)
{
	if (ft_strchr((**str), '0') && (list->conv == 'o' || list->conv == 'O'))
		return (1);
	if (list->dig1 > (int)ft_strlen(list->args) + list->dig2)
		(*tmparg) = ft_strnew(list->dig1);
	else
		(*tmparg) = ft_strnew(list->dig2);
	return (0);
}

void	ft_strzhash_nn(t_flags *list, char **newarg)
{
	(*newarg) = ft_strnew((int)ft_strlen(list->args) + 2);
	if (list->conv == 'x')
		(*newarg) = ft_strcpy((*newarg), "0x");
	else if (list->conv == 'X')
		(*newarg) = ft_strcpy((*newarg), "0X");
	else if ((list->conv == 'o' || list->conv == 'O')
			&& list->dig2 <= (int)ft_strlen(list->args)
			&& list->dig1 > (int)ft_strlen(list->args))
		(*newarg) = ft_strcpy((*newarg), "0");
}

void	ft_strzhash_nnn(char **newarg, char **tmp, char **tmparg, char ***str)
{
	(*newarg) = ft_strjoin((*newarg), (*tmp));
	(**str) = ft_strjoin((*tmparg), (*newarg));
	ft_strdel(&(*tmparg));
	ft_strdel(&(*newarg));
	(**str) = ft_reallocf((**str), 0);
}

void	ft_strzhash_nnnn(int *i, int *j)
{
	*i = 0;
	*j = 0;
}
