/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spaceflag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 16:43:05 by mchemakh          #+#    #+#             */
/*   Updated: 2017/02/15 00:46:09 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_spaceflag(t_flags *list)
{
	char	*newarg;
	char	*tmp;
	char	*addspace;

	addspace = ft_strnew(1);
	addspace[0] = ' ';
	newarg = ft_strnew((int)ft_strlen(list->args) + (int)ft_strlen(addspace));
	newarg = ft_strcpy(newarg, addspace);
	ft_strdel(&addspace);
	tmp = ft_strjoin(newarg, list->args);
	ft_strdel(&list->args);
	ft_strdel(&newarg);
	list->args = ft_reallocf(tmp, 0);
}
