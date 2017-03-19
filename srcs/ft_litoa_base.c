/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:59:24 by mchemakh          #+#    #+#             */
/*   Updated: 2017/02/27 11:44:22 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_reverse(char *str, int i)
{
	int		j;
	char	*tmp;

	j = 0;
	tmp = ft_strnew(i);
	i -= 1;
	while (i >= 0)
	{
		tmp[j] = str[i];
		i--;
		j++;
	}
	tmp[j] = '\0';
	ft_strdel(&str);
	str = tmp;
	return (str);
}

static void		ft_litoa_nextn(int **bs, int **ng, long int **num, char ***str)
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

static char		*ft_litoa_next(char **str, long int *num, int *base, int *neg)
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
		ft_litoa_nextn(&base, &neg, &num, &str);
	}
	return ((*str));
}

static void		ft_litoa_init(char **str, int *i, int *negative)
{
	(*i) = 0;
	(*negative) = 0;
	(*str) = ft_strnew(64);
}

char			*ft_litoa_base(long int num, int base)
{
	char		*str;
	int			i;
	long int	rem;
	int			negative;
	long int	a;

	a = (9223372036854775807 * -1) - 1;
	ft_litoa_init(&str, &i, &negative);
	str = ft_litoa_next(&str, &num, &base, &negative);
	if (num == a)
		return (ft_strdup("-9223372036854775808"));
	if (str[0] == '0' && str[1] == '\0')
		return (str);
	else if (num < 0 && (base == 2 || base == 16))
		return (str);
	else
	{
		while (num != 0)
		{
			rem = num % base;
			str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
			num = num / base;
		}
		if (negative == 1)
			str[i++] = '-';
		str[i] = '\0';
		str = ft_reverse(str, i);
	}
	return (str);
}
