/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 21:16:47 by mchemakh          #+#    #+#             */
/*   Updated: 2016/11/14 21:59:33 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(char const *src)
{
	char	*dup;
	size_t	i;

	i = 0;
	dup = (char*)malloc((ft_strlen(src) + 1) * sizeof(char));
	if (dup == NULL)
		return (0);
	while (i < ft_strlen(src))
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
