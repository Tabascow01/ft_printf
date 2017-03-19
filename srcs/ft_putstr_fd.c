/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 21:06:01 by mchemakh          #+#    #+#             */
/*   Updated: 2016/11/14 21:55:51 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_fd(char const *str, int fd)
{
	int i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i])
		write(fd, &str[i++], 1);
}
