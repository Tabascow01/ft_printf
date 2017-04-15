/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 02:57:00 by mchemakh          #+#    #+#             */
/*   Updated: 2017/02/06 00:42:16 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_printf(const char *format, ...)
{
	t_flags		*list;
	va_list		args;
	int			returned;

	va_start(args, format);
	list = NULL;
	list = ft_init_flags(list, format);
	list->format = (char *)ft_memcpy(list->format, format, ft_strlen(format));
	ft_handle(list, args);
	ft_strdel(&list->format);
	returned = list->ret;
	if (list != NULL)
	{
		if (list->wargs != NULL)
			ft_wstrdel(&list->wargs);
		if (list->format != NULL)
			ft_strdel(&list->format);
		if (list->digit != NULL)
			ft_strdel(&list->digit);
		ft_clear_flags(list);
		free(list);
	}
	va_end(args);
	return (returned);
}
