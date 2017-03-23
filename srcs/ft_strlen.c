/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 21:17:26 by mchemakh          #+#    #+#             */
/*   Updated: 2017/01/12 23:32:38 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_strlen(char const *str)
{
	int nbrchar;

	nbrchar = 0;
	if (str)
	{
		while (str[nbrchar])
			nbrchar++;
	}
	return (nbrchar);
}
