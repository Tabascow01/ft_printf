/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 21:18:14 by mchemakh          #+#    #+#             */
/*   Updated: 2016/11/14 22:04:54 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strnequ(char const *str1, char const *str2, size_t n)
{
	if (str1 == NULL || str2 == NULL)
		return (0);
	return (ft_strncmp(str1, str2, n) == 0 ? 1 : 0);
}
