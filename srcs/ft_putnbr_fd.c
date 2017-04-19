/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 21:05:46 by mchemakh          #+#    #+#             */
/*   Updated: 2016/11/14 21:55:20 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd(int nb, int fd)
{
	char *nbr;

	nbr = "-2147483648";
	if (nb == -2147483648)
		ft_putstr_fd(nbr, fd);
	else
	{
		if (nb < 0 && nb != -2147483648)
		{
			ft_putchar_fd('-', fd);
			nb = nb * -1;
		}
		if (nb > 9)
		{
			ft_putnbr_fd(nb / 10, fd);
			ft_putchar_fd((nb % 10) + '0', fd);
		}
		if (nb >= 0 && nb < 10)
			ft_putchar_fd(nb + '0', fd);
	}
}
