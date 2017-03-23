/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 01:48:50 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/21 20:00:14 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_hdl_one(int *nothing, int *ret, t_flags *list, va_list args)
{
	int not;

	not = 0;
	(*nothing) += 1;
	ft_verif_flags(list);
	if (list->percent == 0)
	{
		ft_verif_option(list);
		(*ret) = ft_verif_conv(list, args);
		if (ret == 0 && list->percent == 0 && !ft_check_flags(list))
		{
			not = 2;
			if (!ft_check_flags(list))
				list->percent = 0;
		}
	}
	else
		list->percent = 0;
	return (not);
}

static void		ft_hdl_two(int *not, t_flags *list)
{
	if (list->noconv > 0 && not == 0)
	{
		not++;
		if (list->left == 0 && list->format[list->index - 1] != '%')
		{
			ft_putstr(list->args);
			ft_putchar(list->format[list->index]);
			ft_return_size(list);
		}
		else if (list->format[list->index - 1] != '%')
		{
			ft_putchar(list->format[list->index]);
			ft_putstr(list->args);
			ft_return_size(list);
		}
		else
			ft_putchar(list->format[list->index]);
	}
	else
		ft_putchar(list->format[list->index]);
}

int				ft_handle(t_flags *list, va_list args)
{
	int		nothing;
	int		not;
	int		ret;

	ret = 0;
	not = 0;
	nothing = 0;
	while (list->format[list->index] != '\0')
	{
		if (list->format[list->index] == '%')
			not = ft_hdl_one(&nothing, &ret, list, args);
		else
			ft_hdl_two(&not, list);
		list->index += 1;
	}
	if (not == 2 && nothing == 1 && list->noconv == 1)
		list->ret = (int)ft_strlen(list->format) - 1;
	else if (nothing == 0 && not == 0)
		list->ret = (int)ft_strlen(list->format);
	return (0);
}
