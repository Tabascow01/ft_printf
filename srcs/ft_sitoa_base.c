/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:59:24 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/23 22:17:44 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_sitoa_nextn(int **bs, int **ng, short int **num, char ***str)
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

static char		*ft_sitoa_next(char **str, short int *num, int *base, int *neg)
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
		ft_sitoa_nextn(&base, &neg, &num, &str);
	}
	return ((*str));
}

static void		ft_sitoa_init(char **str, int *i, int *negative)
{
	(*i) = 0;
	(*negative) = 0;
	(*str) = ft_strnew(64);
}

char			*ft_sitoa_base(short int num, int bs)
{
	char		*str;
	int			i;
	long int	rem;
	int			negative;

	ft_sitoa_init(&str, &i, &negative);
	str = ft_sitoa_next(&str, &num, &bs, &negative);
	if (num == -32768)
		return (ft_strdup("-32768"));
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
