/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digitflag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 16:38:38 by mchemakh          #+#    #+#             */
/*   Updated: 2017/05/10 04:05:59 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_precs_n(t_flags *list, t_precs *lst)
{
	if (list->space > 0 && list->hash == 0 && lst->neg == 0
			&& list->dig1 < list->dig2)
		ft_spaceflag(list);
}

static void		ft_precs(t_flags *list, char *newarg, t_precs *lst)
{
	if (!ft_dgt_1(list, lst))
		return ;
	if (list->conv != 's')
	{
		if (list->args[0] == '-' || list->args[0] == '+')
			lst->neg = 1;
		if (list->dig1 > list->dig2 && list->dig1 > lst->size)
			ft_dgt_3(list, lst);
		if (list->dig2 >= lst->size)
			ft_dgt_4(list, lst);
		ft_dgt_5(&newarg, list, lst);
		ft_precs_n(list, lst);
	}
	else
	{
		if (list->dig2 > 0)
			ft_dgt_7(list, lst);
		else
			ft_bzero(list->args, lst->size);
		if ((list->dig1 > list->dig2 && list->dig1 > 0)
				|| (list->dig2 >= lst->size && list->dig1 > 0
					&& list->dig1 < list->dig2))
			ft_dgt_8(list, lst);
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
	if (digit > (*size) && list->noconv == 0)
		(*newarg) = ft_strnew(digit - (*size));
	else if (list->args[0] == '%')
		(*newarg) = ft_strnew(list->dig1 + 1);
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
		while (lst->i < (list->dig1 - lst->size))
			newarg[lst->i++] = ' ';
		ft_digit_nn(list, &lst->i, &newarg, &lst->tmp);
	}
	else
	{
		ft_dgt_nnn(list, lst, &newarg);
		ft_precs(list, newarg, lst);
	}
	if (list->conv != 's' && list->precision > 0)
		ft_clear_precs(lst);
	free(lst);
}
