/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zeroflag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 15:56:45 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/16 04:51:56 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_wzeroflag(t_flags *list)
{
	wchar_t		*newarg;
	wchar_t		*tmp;
	wchar_t		*tmparg;
	int			digit;
	int			i;
	int			size;

	i = 0;
	size = (int)ft_wstrlen(list->wargs);
	digit = ft_atoi(list->digit);
	newarg = ft_wstrnew(size + digit);
	if (list->wargs != NULL)
	{
		if (list->wargs[0] == '-')
			size -= 1;
		if ((list->wargs[0] == '\0' && list->conv == 'C') || list->space > 0)
			digit -= 1;
	}
	if (list->noconv > 0)
		digit -= 1;
	while (i < (digit - (int)ft_wstrlen(list->wargs)))
		newarg[i++] = '0';
	if (digit > 0 && size < digit)
		newarg[i] = '\0';
	else if (i > 0)
		newarg[i] = '\0';
	if (list->wargs != NULL && (list->wargs[0] == '-' || list->wargs[0] == '+') && list->noconv == 0)
	{
		tmp = ft_wstrnew(1);
		if (list->wargs[0] == '-')
			tmp[0] = '-';
		else
			tmp[0] = '+';
		list->wargs++;
		tmparg = ft_wstrjoin(tmp, newarg);
		ft_wstrdel(&tmp);
		ft_wstrdel(&newarg);
		newarg = ft_wstrjoin(tmparg, list->wargs);
		list->wargs--;
		tmp = list->wargs;
	}
	else
	{
		tmparg = newarg;
		tmp = list->wargs;
		newarg = ft_wstrjoin(tmparg, list->wargs);
	}
	//ft_wstrdel(&tmparg);
	ft_wstrdel(&tmp);
	list->wargs = ft_wreallocf(newarg, 0);
}
