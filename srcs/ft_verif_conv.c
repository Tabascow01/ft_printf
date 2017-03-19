/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 01:12:28 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/15 20:10:42 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_verif_conv(t_flags *list, va_list args)
{
	int		idxtmp;
	int		pass;
	int		passnoconv;

	pass = 0;
	passnoconv = 0;
	idxtmp = list->index;
	while (list->format[idxtmp] != '\0' && pass == 0)
	{
		if (ft_verif_noconv(list, idxtmp))
			pass = ft_verif_noconv(list, idxtmp);
		else if (ft_verif_int(list, idxtmp))
		{
			//printf("(d)\n");
			list->index += 1;
			ft_save_int(list, args);
			pass++;
			return (1);
		}
		else if (ft_verif_hex_low(list, idxtmp))
		{
			//printf("(x)\n");
			list->index += 1;
			ft_save_hex_low(list, args);
			pass++;
			return (1);
		}
		else if (ft_verif_hex_up(list, idxtmp))
		{
			//printf("(X)\n");
			list->index += 1;
			ft_save_hex_up(list, args);
			pass++;
			return (1);
		}
		else if (ft_verif_uint_low(list, idxtmp))
		{
			//printf("(u)\n");
			list->index += 1;
			ft_save_uint_low(list, args);
			pass++;
			return (1);
		}
		else if (ft_verif_uint_up(list, idxtmp))
		{
			//printf("(U)\n");
			list->index += 1;
			ft_save_uint_up(list, args);
			pass++;
			return (1);
		}
		else if (ft_verif_oct_low(list, idxtmp))
		{
			//printf("(o)\n");
			list->index += 1;
			ft_save_oct_low(list, args);
			pass++;
			return (1);
		}
		else if (ft_verif_oct_up(list, idxtmp))
		{
			//printf("(O)\n");
			list->index += 1;
			ft_save_oct_up(list, args);
			pass++;
			return (1);
		}
		else if (ft_verif_chr(list, idxtmp))
		{
			//printf("(c)\n");
			list->index += 1;
			ft_save_chr(list, args);
			pass++;
			return (1);
		}
		else if (ft_verif_ptr(list, idxtmp))
		{
			//printf("(p)\n");
			list->index += 1;
			ft_save_ptr(list, args);
			pass++;
			return (1);
		}
		else if (ft_verif_str(list, idxtmp))
		{
			//printf("(s)\n");
			list->index += 1;
			ft_save_str(list, args);
			pass++;
			return (1);
		}
		else if (ft_verif_int_up(list, idxtmp))
		{
			//printf("(D)\n");
			list->index += 1;
			ft_save_int_up(list, args);
			pass++;
			return (1);
		}
		else if (ft_verif_wchr(list, idxtmp) && list->conv != 'c')
		{
			//printf("(C)\n");
			list->index += 1;
			ft_save_wchr(list, args);
			pass++;
			return (1);
		}
		else if (ft_verif_wstr(list, idxtmp) && list->conv != 's')
		{
			//printf("(S)\n");
			list->index += 1;
			ft_save_wstr(list, args);
			pass++;
			return (1);
		}
		idxtmp++;
	}
	if ((pass == 'Z' || pass == 'R') && ft_check_flags(list) && list->space == 0)
		ft_process_flags(list);
	else if (pass == 0 && !ft_check_flags(list))
		list->noconv = 1;
	return (0);
}