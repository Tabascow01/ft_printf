/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 13:17:17 by mchemakh          #+#    #+#             */
/*   Updated: 2017/01/20 02:15:54 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_reallocf(char *ptr, size_t size)
{
	char	*newptr;
	int		i;

	newptr = NULL;
	while (!(newptr = (char *)malloc(sizeof(char) * size + ft_strlen(ptr) + 1)))
		;
	ft_bzero(newptr, size + 1 + ft_strlen(ptr));
	if (ptr)
	{
		i = 0;
		while (ptr[i])
		{
			newptr[i] = ptr[i];
			i++;
		}
		newptr[i] = '\0';
		free(ptr);
	}
	return (newptr);
}
