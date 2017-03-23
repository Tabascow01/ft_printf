/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:59:24 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/23 22:05:01 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_ustoa_next(char **str, unsigned short *num)
{
	int i;

	i = 0;
	if ((*num) == 0)
	{
		(*str)[i++] = '0';
		(*str)[i] = '\0';
	}
	return ((*str));
}

char			*ft_ustoa_base(unsigned short num, int base)
{
	char	*str;
	int		i;
	int		rem;

	i = 0;
	str = ft_strnew(64);
	str = ft_ustoa_next(&str, &num);
	if (str[0] == '0' && str[1] == '\0')
		return (str);
	while (num != 0)
	{
		rem = num % base;
		str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		num = num / base;
	}
	str[i] = '\0';
	str = ft_strrev(str, i);
	return (str);
}
