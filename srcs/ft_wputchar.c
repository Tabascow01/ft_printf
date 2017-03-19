/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wputchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 14:20:16 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/14 00:51:02 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_wputchar(wchar_t wc)
{
	if (wc <= 0x0000007F)
	{
		ft_putchar(wc);
		return (1);
	}
	else if (wc <= 0x000007FF)
	{
		ft_putchar(0xC0 | (wc >> 6));
		ft_putchar(0x80 | (wc & 0x3F));
		return (2);
	}
	else if (wc <= 0x0000FFFF)
	{
		ft_putchar(0xE0 | (wc >> 12));
		ft_putchar(0x80 | (wc >> 6 & 0x3F));
		ft_putchar(0x80 | (wc & 0x3F));
		return (3);
	}
	else if (wc <= 0x001FFFFF)
	{
		ft_putchar(0xF0 | (wc >> 18));
		ft_putchar(0x80 | (wc >> 12 & 0x3F));
		ft_putchar(0x80 | (wc >> 6 & 0x3F));
		ft_putchar(0x80 | (wc & 0x3F));
		return (4);
	}
	else if (wc <= 0x03FFFFFF)
	{
		ft_putchar(0xF8 | (wc >> 24));
		ft_putchar(0x80 | (wc >> 18 & 0x3F));
		ft_putchar(0x80 | (wc >> 12 & 0x3F));
		ft_putchar(0x80 | (wc >> 6 & 0x3F));
		ft_putchar(0x80 | (wc & 0x3F));
		return (5);
	}
	else if (wc <= 0x7FFFFFFF)
	{
		ft_putchar(0xFC | (wc >> 30));
		ft_putchar(0x80 | (wc >> 24 & 0x3F));
		ft_putchar(0x80 | (wc >> 18 & 0x3F));
		ft_putchar(0x80 | (wc >> 12 & 0x3F));
		ft_putchar(0x80 | (wc >> 6 & 0x3F));
		ft_putchar(0x80 | (wc & 0x3F));
		return (6);
	}
	return (0);
}
