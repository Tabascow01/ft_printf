/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 21:16:53 by mchemakh          #+#    #+#             */
/*   Updated: 2016/11/14 21:59:48 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strequ(char const *str1, char const *str2)
{
	if (str1 == NULL || str2 == NULL)
		return (0);
	if (ft_strcmp((char *)str1, (char *)str2) == 0)
		return (1);
	return (0);
}
