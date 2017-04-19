/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 21:17:58 by mchemakh          #+#    #+#             */
/*   Updated: 2016/11/14 22:04:07 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strncmp(char const *s1, char const *s2, size_t n)
{
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2 && n > 0)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
