/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 21:18:51 by mchemakh          #+#    #+#             */
/*   Updated: 2016/11/14 22:09:00 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strstr(char const *str, char const *to_find)
{
	int i;
	int j;

	i = 0;
	if (*to_find == 0)
		return ((char *)str);
	while (str[i])
	{
		j = 0;
		while (to_find[j] == str[i + j] && to_find[j] != 0)
			j++;
		if (to_find[j] == '\0')
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}
