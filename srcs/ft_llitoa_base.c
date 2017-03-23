/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:59:24 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/23 22:13:33 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		llitoa_n(int **bs, int **ng, long long int **num, char ***str)
{
	if ((**bs) == 10)
	{
		(**ng) = 1;
		(**num) = -(**num);
	}
	else if ((**bs) == 2)
	{
		ft_strdel(&(**str));
		(**str) = ft_itob((**num), 31);
	}
	else if ((**bs) == 16)
	{
		ft_strdel(&(**str));
		(**str) = ft_btoh(ft_itob((**num), 31));
	}
}

static char		*llitoa_nxt(char **str, long long *num, int *base, int *neg)
{
	int i;

	i = 0;
	if ((*num) == 0)
	{
		(*str)[i++] = '0';
		(*str)[i] = '\0';
		return ((*str));
	}
	if ((*num) < 0)
	{
		llitoa_n(&base, &neg, &num, &str);
	}
	return ((*str));
}

static int		ft_llitoa_base_n(long long int *num)
{
	long long int a;

	a = (9223372036854775807 * -1) - 1;
	if ((*num) == a)
		return (1);
	return (0);
}

static void		ft_llitoa_init(char **str, int *i, int *negative)
{
	(*i) = 0;
	(*negative) = 0;
	(*str) = ft_strnew(64);
}

char			*ft_llitoa_base(long long num, int bs)
{
	char			*str;
	int				i;
	long int		rem;
	int				negative;

	ft_llitoa_init(&str, &i, &negative);
	str = llitoa_nxt(&str, &num, &bs, &negative);
	if (ft_llitoa_base_n(&num))
		return (ft_strdup("-9223372036854775808"));
	if ((str[0] == '0' && str[1] == '\0') || (num < 0 && (bs == 2 || bs == 16)))
		return (str);
	else
	{
		while (num != 0)
		{
			rem = num % bs;
			str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
			num = num / bs;
		}
		if (negative == 1)
			str[i++] = '-';
		str[i] = '\0';
		str = ft_strrev(str, i);
	}
	return (str);
}
