/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:59:24 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/23 22:02:45 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	return ((*str));
}

static void		ft_luitoa_init(char **str, int *i)
{
	(*i) = 0;
	(*str) = ft_strnew(64);
}

char			*ft_luitoa_base(unsigned long int num, int base)
{
	char				*str;
	int					i;
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
		str = ft_strrev(str, i);
	}
	return (str);
}
