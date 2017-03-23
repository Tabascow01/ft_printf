/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 01:20:02 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/20 01:36:18 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_countbytes(wchar_t wc)
{
	if (wc <= 0x0000007F)
		return (1);
	else if (wc <= 0x000007FF)
		return (2);
	else if (wc <= 0x0000FFFF)
		return (3);
	else if (wc <= 0x001FFFFF)
		return (4);
	else if (wc <= 0x03FFFFFF)
		return (5);
	else if (wc <= 0x7FFFFFFF)
		return (6);
	else
		return (0);
}

size_t			ft_wstrlen(wchar_t *wstr)
{
	size_t	i;
	int		bytes;

	bytes = 0;
	i = 0;
	while (wstr[i] != '\0')
	{
		bytes += ft_countbytes(wstr[i]);
		i++;
	}
	return (bytes);
}
