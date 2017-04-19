/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wputchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 14:20:16 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/23 23:17:29 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_verif_utf(wchar_t wc)
{
	if (MB_CUR_MAX < 2)
	{
		ft_putchar(wc);
		return (1);
	}
	return (0);
}

static int		ft_wputchar_nnext(wchar_t wc)
{
	if (wc <= 0x03FFFFFF)
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

static int		ft_wputchar_next(wchar_t wc)
{
	int ret;

	ret = 0;
	if (wc <= 0x0000FFFF)
	{
		ft_putchar(0xE0 | (wc >> 12));
		ft_putchar(0x80 | (wc >> 6 & 0x3F));
		ft_putchar(0x80 | (wc & 0x3F));
		ret = 3;
	}
	else if (wc <= 0x001FFFFF)
	{
		ft_putchar(0xF0 | (wc >> 18));
		ft_putchar(0x80 | (wc >> 12 & 0x3F));
		ft_putchar(0x80 | (wc >> 6 & 0x3F));
		ft_putchar(0x80 | (wc & 0x3F));
		ret = 4;
	}
	else
		ret = ft_wputchar_nnext(wc);
	return (ret);
}

int				ft_wputchar(wchar_t wc)
{
	int ret;

	ret = 0;
	if (ft_verif_utf(wc))
		return (1);
	if (wc <= 0x0000007F)
	{
		ft_putchar(wc);
		ret = 1;
	}
	else if (wc <= 0x000007FF)
	{
		ft_putchar(0xC0 | (wc >> 6));
		ft_putchar(0x80 | (wc & 0x3F));
		ret = 2;
	}
	else
		ret = ft_wputchar_next(wc);
	return (ret);
}
