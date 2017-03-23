/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_wchr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 01:06:06 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/20 01:06:45 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_wchr(t_flags *list, wchar_t c)
{
	if (list->left == 0 && (list->wargs[ft_atoi(list->digit) - 1] == 0
			|| list->wargs[0] == '\0'))
	{
		ft_wputstr(list->wargs);
		list->bytes = ft_wputchar(c);
	}
	else if (list->left > 0 && (list->wargs[ft_atoi(list->digit) - 1] == 0
			|| list->wargs[0] == '\0'))
	{
		list->bytes = ft_wputchar(c);
		ft_wputstr(list->wargs);
	}
	else
		list->bytes = ft_wputstr(list->wargs);
	ft_return_wsize(list);
	ft_strdel((void *)&list->wargs);
	if (list->digit > 0)
		ft_strdel(&list->digit);
	ft_clear_flags(list);
	return (0);
}

void	ft_process_wchr(t_flags *list)
{
	wchar_t c;

	if (ft_check_flags(list) && list->space == 0 && list->zero == 0
			&& list->sign == 0)
	{
		c = list->wargs[0];
		ft_process_flags(list);
		ft_print_wchr(list, c);
	}
	else
	{
		list->bytes = ft_wputchar(list->wargs[0]);
		ft_return_wsize(list);
		ft_strdel((void *)&list->wargs);
		ft_clear_flags(list);
		return ;
	}
}
