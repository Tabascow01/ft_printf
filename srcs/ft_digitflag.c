/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digitflag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 16:38:38 by mchemakh          #+#    #+#             */
/*   Updated: 2017/04/12 10:00:14 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>//

static void		ft_precs(t_flags *list, char *newarg, t_precs *lst, int digit)
{
	ft_dgt_1(list, lst);
	if (list->conv != 's')
	{
		if(list->args[0] == '-' || list->args[0] == '+')
			lst->neg = 1;
		// Add spaces
		if (list->dig1 > list->dig2 && list->dig1 > lst->size)
			ft_dgt_3(list, lst);
		// Add zero
		if (list->dig2 > lst->size)
			ft_dgt_4(list, lst);
		// Joining string for result
		ft_dgt_5(&newarg, list, lst);
		// ft_dgt_6(list, lst, &newarg);
	}
	else
	{
		if (digit > 0)
			ft_dgt_7(list, lst, &digit);
		else
			ft_bzero(list->args, lst->size);
		if (list->dig1 > 0 && list->dig1 > (int)ft_strlen(list->args))
			ft_dgt_8(list, lst, &list->dig1, &list->dig2);
	}
}

static void		ft_digit_n(t_flags *list, int *size, char **newarg)
{
	int digit;

	digit = list->dig2;
	if ((int)ft_strlen(list->args) == 0 && (list->conv != 's'
				|| list->noconv > 0))
	{
		if (list->noconv > 0)
			list->size += 1;
		(*size) += 1;
	}
	if (digit > (*size))
		(*newarg) = ft_strnew(digit - (*size));
	else
		(*newarg) = ft_strnew(1);
}

static void		ft_digit_nn(t_flags *list, int *i, char **newarg, char **tmp)
{
	if ((*i) >= 0 && list->conv != 'u')
		(*newarg)[(*i)] = '\0';
	else if ((*i) > 0)
		(*newarg)[(*i)] = '\0';
	(*tmp) = ft_strjoin((*newarg), list->args);
	ft_strdel((*&newarg));
	ft_strdel(&list->args);
	list->args = ft_reallocf((*tmp), 0);
}

void			ft_digitflag(t_flags *list)
{
	char	*newarg;
	t_precs	*lst;

	newarg = NULL;
	lst = NULL;
	lst = ft_init_precs(lst);
	lst->size = (int)ft_strlen(list->args);
	if (list->precision == 0)
	{
		ft_digit_n(list, &lst->size, &newarg);
		while (lst->i < (list->dig2 - lst->size))
			newarg[lst->i++] = ' ';
		ft_digit_nn(list, &lst->i, &newarg, &lst->tmp);
	}
	else
	{
		if (list->dig1 > list->dig2 && list->dig1 > lst->size)
			newarg = ft_strnew(list->dig1);
		else if (list->dig2 > list->dig1 && list->dig2 > lst->size)
			newarg = ft_strnew(list->dig2);
		else
			newarg = ft_strnew(list->dig1 + list->dig2);
		ft_precs(list, newarg, lst, list->dig2);
	}
	ft_clear_precs(lst);
	free(lst);
}
