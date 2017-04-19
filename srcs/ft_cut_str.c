/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 14:01:52 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/02 14:19:25 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_cut_lststr(t_flags *list, int start)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_strnew(ft_strlen(list->args));
	while (list->args[start])
		str[i++] = list->args[start++];
	if (list->args != NULL)
		ft_strdel(&list->args);
	list->args = ft_reallocf(str, 0);
}
