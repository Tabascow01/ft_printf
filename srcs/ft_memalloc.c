/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 20:08:27 by mchemakh          #+#    #+#             */
/*   Updated: 2017/01/08 17:02:27 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memalloc(size_t size)
{
	void	*memalloc;

	if ((memalloc = malloc(size)) != NULL)
	{
		ft_bzero(memalloc, size);
		return (memalloc);
	}
	return (0);
}
