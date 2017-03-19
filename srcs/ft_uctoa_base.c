/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:59:24 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/19 22:20:57 by mchemakh         ###   ########.fr       */
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
		str = ft_reverse(str, i);
	}
	return (str);
}
