/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wputstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 09:25:29 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/14 01:09:35 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_wputstr(wchar_t *wstr)
{
	int		i;
	int		tmp;
	int		bytes;

	i = 0;
	tmp = 0;
	bytes = 0;
	while (wstr[i] != '\0')
		bytes += ft_wputchar(wstr[i++]);
	return (bytes);
}
