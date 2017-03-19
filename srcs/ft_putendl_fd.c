/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 21:05:25 by mchemakh          #+#    #+#             */
/*   Updated: 2016/11/17 13:38:25 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putendl_fd(char const *str, int fd)
{
	if (str == NULL)
		return ;
	ft_putstr_fd(str, fd);
	ft_putchar_fd('\n', fd);
}
