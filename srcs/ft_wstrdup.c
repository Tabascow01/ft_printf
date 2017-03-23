/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 21:16:47 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/16 01:20:28 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t		*ft_wstrdup(wchar_t *src)
{
	wchar_t		*dup;
	size_t		i;

	i = 0;
	dup = (wchar_t *)malloc((ft_wstrlen(src) + 1) * sizeof(wchar_t));
	if (dup == NULL)
		return (0);
	while (i < ft_wstrlen(src))
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
