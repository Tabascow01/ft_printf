/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:59:24 by mchemakh          #+#    #+#             */
/*   Updated: 2017/01/31 12:25:48 by mchemakh         ###   ########.fr       */
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
/*
static void		ft_luitoa_nextn(int **bs, int **ng, unsigned long int **num, char ***str)
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
*/
static char		*ft_luitoa_next(char **str, unsigned long int *num)
{
	int i;

	i = 0;
	if ((*num) == 0)
	{
		(*str)[i++] = '0';
		(*str)[i] = '\0';
		return ((*str));
	}
	//ft_luitoa_nextn(&base, &neg, &num, &str);
	return ((*str));
}

static void		ft_luitoa_init(char **str, int *i)
{
	(*i) = 0;
	(*str) = ft_strnew(64);
}

char			*ft_luitoa_base(unsigned long int num, int base)
{
	char		*str;
	int			i;
	unsigned long int	rem;

	ft_luitoa_init(&str, &i);
	str = ft_luitoa_next(&str, &num);
	if (str[0] == '0' && str[1] == '\0')
		return (str);
	else
	{
		while (num > 0)
		{
			rem = num % base;
			str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
			num = num / base;
		}
		str[i] = '\0';
		str = ft_reverse(str, i);
	}
	return (str);
}
