
#include "ft_printf.h"

int		ft_verif_noconv(t_flags *list, int idxtmp)
{
	if (list->format[idxtmp] == 'Z' || list->format[idxtmp] == 'R')
	{
		list->noconv = 1;
		return (list->format[idxtmp]);
	}
	return (0);
}
