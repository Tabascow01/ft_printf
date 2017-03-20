/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:31:03 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/19 23:44:14 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			ft_is_spec(char c)
{
	if (c == '\t' || c == '\n' || c == '\r' || c == ' ' || c == '\v'
			|| c == '\f')
		return (1);
	return (0);
}

unsigned long int	ft_atoli(char const *str)
{
	int					i;
	int					sign;
	unsigned long int	num;

	i = 0;
	sign = 1;
	num = 0;
	if (str != NULL)
	{
		while (ft_is_spec(str[i]))
			i++;
		if (str[i] == '+' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
			i++;
		if (str[i] == '-' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
		{
			sign = -1;
			i++;
		}
		while (str[i] >= '0' && str[i] <= '9')
		{
			num = (num * 10) + (str[i] - '0');
			i++;
		}
	}
	return (num * sign);
}
