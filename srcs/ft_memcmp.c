/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 20:09:16 by mchemakh          #+#    #+#             */
/*   Updated: 2016/11/14 21:51:02 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_memcmp(void const *str1, void const *str2, size_t n)
{
	unsigned char	*cstr1;
	unsigned char	*cstr2;

	cstr1 = (unsigned char *)str1;
	cstr2 = (unsigned char *)str2;
	while (n > 0 && *cstr1 == *cstr2)
	{
		cstr1++;
		cstr2++;
		n--;
	}
	if (n == 0)
		return (0);
	else
		return (*cstr1 - *cstr2);
}
