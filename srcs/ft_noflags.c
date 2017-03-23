/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_noflags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 01:11:36 by mchemakh          #+#    #+#             */
/*   Updated: 2017/02/14 01:11:39 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_noflags(char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd'
		|| c == 'D' || c == 'i' || c == 'o' || c == 'O'
		|| c == 'u' || c == 'U' || c == 'x' || c == 'X'
		|| c == 'c' || c == 'C' || c == 'b' || c == 'p')
		return (1);
	return (0);
}
