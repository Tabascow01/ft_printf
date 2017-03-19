/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:59:24 by mchemakh          #+#    #+#             */
/*   Updated: 2017/02/27 05:58:47 by mchemakh         ###   ########.fr       */
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

char			*ft_sitoa_base(short int num, int base)
{
	char		*str;
	int			i;
	long int	rem;
	int			negative;

	ft_sitoa_init(&str, &i, &negative);
	str = ft_sitoa_next(&str, &num, &base, &negative);
	if (num == -32768)
		return (ft_strdup("-32768"));
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
