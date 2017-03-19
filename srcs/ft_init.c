/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 02:04:09 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/02 14:28:26 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags		*ft_init_flags(t_flags *list, const char *format)
{
	t_flags *lst;

	lst = (t_flags *)ft_memalloc(sizeof(t_flags));
	lst->format = ft_strnew(ft_strlen(format));
	lst->percent = 0;
	lst->space = 0;
	lst->left = 0;
	lst->precision = 0;
	lst->conv = 0;
	lst->noconv = 0;
	lst->hash = 0;
	lst->zero = 0;
	lst->digit = 0;
	lst->option = 0;
	lst->dbloption = 0;
	lst->size = 0;
	lst->sign = 0;
	lst->index = 0;
	lst->ret = 0;
	lst->dig1 = 0;
	lst->dig2 = 0;
	list = lst;
	return (list);
}
