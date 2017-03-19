/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:59:24 by mchemakh          #+#    #+#             */
/*   Updated: 2017/01/22 22:56:14 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		ft_size_int(int n)
{
	if (n < 0)
		n = -n;
	if (n < 10)
		return (1);
	else
		return (ft_size_int(n / 10) + 1);
}

char			*ft_itoa(int nb)
{
	char			*str;
	int				size;
	int				neg;

	neg = 0;
	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	if (nb == 0)
		return (ft_strdup("0"));
	if (nb < 0)
	{
		neg = 1;
		nb = -nb;
	}
	size = neg ? ft_size_int(nb) : ft_size_int(nb) - 1;
	if ((str = ft_strnew(size + 1)) == NULL)
		return (0);
	while (size >= 0)
	{
		str[size--] = (nb % 10) + '0';
		nb /= 10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
