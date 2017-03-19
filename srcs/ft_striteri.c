/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 21:17:06 by mchemakh          #+#    #+#             */
/*   Updated: 2016/11/14 22:00:38 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_striteri(char *str, void (*f)(unsigned int, char*))
{
	unsigned int i;

	i = 0;
	if (str == NULL || f == NULL)
		return ;
	while (str[i])
	{
		f(i, &str[i]);
		i++;
	}
}
