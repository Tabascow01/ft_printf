/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 14:34:15 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/17 23:36:31 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itob(long long int nb, int buf_size)
{
	int		i;
	char	*buffer;

	if (nb > 0 && buf_size <= 7)
		buf_size = 7;
	i = buf_size;
	buffer = ft_strnew(buf_size);
	while (i >= 0)
	{
		buffer[i--] = (nb & 1) + '0';
		nb >>= 1;
	}
	buffer[buf_size + 1] = '\0';
	return (buffer);
}
