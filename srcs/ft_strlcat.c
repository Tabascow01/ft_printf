/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 21:17:19 by mchemakh          #+#    #+#             */
/*   Updated: 2016/11/14 22:11:52 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlcat(char *dest, char const *src, size_t size)
{
	size_t i;

	i = ft_strlen(dest);
	if (size <= i)
		return (size + ft_strlen(src));
	dest = ft_strncat(dest, src, size - ft_strlen(dest) - 1);
	return (i + ft_strlen(src));
}
