/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldigitflag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 15:57:39 by mchemakh          #+#    #+#             */
/*   Updated: 2017/04/29 15:36:46 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_precs(t_flags *list, char *newarg, t_precs *lst)
{
	if (!ft_ldgt_1(list, lst))
		return ;
	if (list->conv != 's')
	{
		if (list->args[0] == '-' || list->args[0] == '+')
			lst->neg = 1;
		if (list->dig1 > list->dig2 && list->dig1 > lst->size)
			ft_ldgt_3(list, lst);
		if (list->dig2 >= lst->size)
			ft_ldgt_4(list, lst);
		ft_ldgt_5(&newarg, list, lst);
	}
	else
	{
		if (list->dig2 > 0)
			ft_ldgt_7(list, lst);
		else
			ft_bzero(list->args, lst->size);
		if (list->dig1 > 0 && list->dig1 > lst->size)
			ft_ldgt_8(list, lst);
	}
}

static void		ft_ldigit_n(t_flags *list, int i, int digit, char **newarg)
{
	if (((i >= 0 && list->conv != 'p') || ((i > 0 && list->conv == 'p'
			&& digit < 13))) && (int)ft_strlen((*newarg)) > 0)
		(*newarg)[i] = '\0';
	else if (list->conv == 'p' && digit > 12)
		(*newarg)[i] = '\0';
}

static void		ft_ldigit_nn(t_flags *list, char **tmp, char **newarg)
{
	(*tmp) = ft_strjoin(list->args, (*newarg));
	ft_strdel(&list->args);
	ft_strdel((*&newarg));
	if (list->conv == 's')
		ft_strdel(&list->args);
	list->args = ft_reallocf((*tmp), 0);
}

static void		ft_ldgt_nnn(t_flags *list, t_precs *lst, char **newarg)
{
	if (list->conv != 's')
	{
		if (list->dig1 > list->dig2 && list->dig1 > lst->size)
			*newarg = ft_strnew(list->dig1);
		else if (list->dig2 > list->dig1 && list->dig2 > lst->size)
			*newarg = ft_strnew(list->dig2);
		else
			*newarg = ft_strnew(list->dig1 + list->dig2);
	}
}

void			ft_ldigitflag(t_flags *list)
{
	char	*newarg;
	t_precs	*lst;

	newarg = NULL;
	lst = NULL;
	lst = ft_init_precs(lst);
	lst->size = (int)ft_strlen(list->args);
	if ((list->args == NULL || list->args[0] == '\0') && list->conv != 's')
		lst->size += 1;
	if (list->precision == 0)
	{
		newarg = ft_strnew(list->dig1);
		while (lst->i < (list->dig1 - lst->size))
			newarg[lst->i++] = ' ';
		ft_ldigit_n(list, lst->i, list->dig1, &newarg);
		ft_ldigit_nn(list, &lst->tmp, &newarg);
	}
	else
	{
		ft_ldgt_nnn(list, lst, &newarg);
		ft_precs(list, newarg, lst);
	}
	if (list->conv != 's' && list->precision > 0)
		ft_clear_precs(lst);
	free(lst);
}
