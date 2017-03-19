/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 21:17:12 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/16 01:20:38 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t		*ft_wstrjoin(wchar_t *str1, wchar_t *str2)
{
	wchar_t		*mstr;
	wchar_t		*mstriter;

	if (str1 == NULL && str2 == NULL)
		return (ft_wstrnew(0));
	else if (str1 == NULL)
		return (ft_wstrdup(str2));
	else if (str2 == NULL)
		return (ft_wstrdup(str1));
	mstr = ft_wstrnew(ft_wstrlen(str1) + ft_wstrlen(str2));
	if (mstr == NULL)
		return (0);
	mstriter = mstr;
	while (*str1 != '\0')
		*mstriter++ = *str1++;
	while (*str2 != '\0')
		*mstriter++ = *str2++;
	*mstriter = '\0';
	return (mstr);
}
