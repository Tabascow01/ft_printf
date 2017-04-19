/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 20:09:06 by mchemakh          #+#    #+#             */
/*   Updated: 2016/11/14 21:49:48 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memccpy(void *dest, void const *src, int c, size_t n)
{
	unsigned char	*cdest;
	unsigned char	*csrc;
	size_t			i;

	cdest = (unsigned char *)dest;
	csrc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		*cdest++ = *csrc;
		if (*csrc++ == (unsigned char)c)
		{
			return (cdest);
		}
		i++;
	}
	return (0);
}
