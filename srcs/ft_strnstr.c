/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 21:18:25 by mchemakh          #+#    #+#             */
/*   Updated: 2016/11/14 22:05:50 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strnstr(const char *dest, const char *to_join, size_t n)
{
	size_t	length;

	if (*to_join == '\0')
		return ((char *)dest);
	length = ft_strlen(to_join);
	while (*dest != '\0' && n >= length)
	{
		if (*dest == *to_join && ft_memcmp(dest, to_join, length) == 0)
			return ((char *)dest);
		dest++;
		n--;
	}
	return (0);
}
