/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:59:24 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/23 22:05:32 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_uctoa_next(char **str, unsigned char *num)
{
	int i;

	i = 0;
	if ((*num) == 0)
	{
		(*str)[i++] = '0';
		(*str)[i] = '\0';
		return ((*str));
	}
	return ((*str));
}

static void		ft_uctoa_init(char **str, int *i)
{
	(*i) = 0;
	(*str) = ft_strnew(64);
}

char			*ft_uctoa_base(unsigned char num, int base)
{
	char			*str;
	int				i;
	unsigned char	rem;

	ft_uctoa_init(&str, &i);
	str = ft_uctoa_next(&str, &num);
	if (str[0] == '0' && str[1] == '\0')
		return (str);
	else
	{
		while (num != 0)
		{
			rem = num % base;
			str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
			num = num / base;
		}
		str[i] = '\0';
		str = ft_strrev(str, i);
	}
	return (str);
}
