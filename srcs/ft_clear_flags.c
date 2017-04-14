/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 01:10:31 by mchemakh          #+#    #+#             */
/*   Updated: 2017/04/06 02:31:53 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_clear_precs(t_precs *lst)
{
	if (lst->zero != NULL)
		ft_strdel(&lst->zero);
	if (lst->spaces != NULL)
		ft_strdel(&lst->spaces);
	if (lst->tmp != NULL)
		ft_strdel(&lst->tmp);
	if (lst->tmpargs != NULL)
		ft_strdel(&lst->tmpargs);
	if (lst->wtmp != NULL)
		ft_wstrdel(&lst->wtmp);
	if (lst->wtmpargs != NULL)
		ft_wstrdel(&lst->wtmpargs);
	lst->i = 0;
	lst->j = 0;
	lst->size = 0;
	lst->neg = 0;
	lst->null = 0;
	lst->flags = 0;
}

void	ft_clear_flags(t_flags *list)
{
	list->percent = 0;
	list->conv = 0;
	list->noconv = 0;
	list->precision = 0;
	list->left = 0;
	list->space = 0;
	list->option = 0;
	list->dbloption = 0;
	list->sign = 0;
	list->zero = 0;
	list->hash = 0;
	list->dig1 = 0;
	list->dig2 = 0;
	list->bytes = 0;
	list->nbleft = 0;
}
