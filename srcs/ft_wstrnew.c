/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 21:18:20 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/16 04:01:36 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t		*ft_wstrnew(size_t size)
{
	wchar_t		*strmemalloc;

	strmemalloc = (wchar_t *)malloc(sizeof(wchar_t) * size + 1);
	if (strmemalloc != NULL)
	{
		ft_bzero(strmemalloc, size + 1);
		return (strmemalloc);
	}
	return (0);
}
