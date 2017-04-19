/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 21:19:01 by mchemakh          #+#    #+#             */
/*   Updated: 2016/11/14 22:09:28 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strsub(char const *str, unsigned int start, size_t n)
{
	size_t	i;
	char	*mstr;

	mstr = ft_strnew(n);
	if (mstr == NULL || str == NULL)
		return (0);
	str = str + start;
	i = 0;
	while (n > 0)
	{
		mstr[i] = str[i];
		n--;
		i++;
	}
	return (mstr);
}
