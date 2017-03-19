/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 01:10:31 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/15 20:06:09 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_clear_flags(t_flags *list)
{
	list->percent = 0;
	list->conv = 0;
	list->noconv = 0;
	list->precision = 0;
	list->left = 0;
	list->space = 0;
	list->option = 0;
	list->dbloption = 0;
	list->sign = 0;
	list->zero = 0;
	list->hash = 0;
	list->dig1 = 0;
	list->dig2 = 0;
	list->bytes = 0;
}
