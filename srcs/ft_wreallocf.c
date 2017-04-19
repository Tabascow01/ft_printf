/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 13:17:17 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/16 01:35:37 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t		*ft_wreallocf(wchar_t *ptr, size_t size)
{
	wchar_t		*newptr;
	int			i;

	newptr = NULL;
	while (!(newptr = malloc(sizeof(wchar_t) * size + ft_wstrlen(ptr) + 1)))
		;
	ft_bzero(newptr, size + 1 + ft_wstrlen(ptr));
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
