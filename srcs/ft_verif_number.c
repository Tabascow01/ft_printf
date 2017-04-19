/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 17:59:22 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/23 23:14:47 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_save_digit_n(t_flags *list, int *idxtmp, int *ret, int *i)
{
	if (ft_isdigit(list->format[(*idxtmp)]
			&& (list->format[(*idxtmp) + 1] == ' '
			|| list->format[(*idxtmp) + 1] == '#'
			|| list->format[(*idxtmp) + 1] == '-'
			|| list->format[(*idxtmp) + 1] == '+')))
		(*ret) = 1;
	if ((*ret) == 1)
	{
		ft_strdel(&list->digit);
		return (0);
	}
	if ((ft_isdigit(list->format[(*idxtmp)])
		|| (list->format[(*idxtmp)] == '.')))
	{
		list->digit[(*i)++] = list->format[(*idxtmp)];
		list->index += 1;
		if (list->format[(*idxtmp)] == '.')
			(*ret) = 2;
	}
	return (1);
}

void			ft_save_digit(t_flags *list, int idxtmp)
{
	int		i;
	int		ret;

	i = (int)ft_strlen(list->digit);
	ret = 0;
	if (list->digit != 0)
		i++;
	if (list->digit == NULL)
		list->digit = ft_strnew(12);
	while (list->format[idxtmp] && list->format[idxtmp] != '%'
			&& ft_isflag(list->format[idxtmp]))
	{
		if (!ft_save_digit_n(list, &idxtmp, &ret, &i))
			return ;
		idxtmp++;
	}
	list->digit[i] = '\0';
	if (ret == 2)
		list->precision = 1;
}

int				ft_isdigit_allowed(t_flags *list, int idxtmp)
{
	int count;
	int counter;

	count = 0;
	counter = 0;
	if (ft_isdigit(list->format[idxtmp]) && list->format[idxtmp + 1] != ' ')
		count++;
	if (ft_isdigit(list->format[idxtmp]))
		counter++;
	while (list->format[idxtmp] != '%' && list->format[idxtmp]
			&& ft_isflag(list->format[idxtmp]))
	{
		if ((ft_isdigit(list->format[idxtmp]) || list->format[idxtmp] == '.')
			&& list->format[idxtmp + 1] != ' ')
			count++;
		if (ft_isdigit(list->format[idxtmp]) || list->format[idxtmp] == '.')
			counter++;
		idxtmp++;
	}
	if (count == counter)
		return (1);
	return (0);
}

int				ft_verif_number(t_flags *list, int idxtmp)
{
	while (list->format[idxtmp] != '%' && list->format[idxtmp]
			&& ft_isflag(list->format[idxtmp]))
	{
		if (ft_isdigit(list->format[idxtmp]) || list->format[idxtmp] == '.')
			return (1);
		idxtmp++;
	}
	return (0);
}
