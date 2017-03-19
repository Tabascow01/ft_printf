
#include "ft_printf.h"
#include <wchar.h>

int		ft_print_wstr(t_flags *list)
{
	list->bytes = ft_wputstr(list->wargs);
	ft_return_wsize(list);
	ft_strdel((void *)&list->wargs);
	if (list->digit > 0)
		ft_strdel(&list->digit);
	ft_clear_flags(list);
	return (0);
}

void	ft_process_wstr(t_flags *list)
{
	if (ft_check_flags(list))
	{
		ft_process_flags(list);
		ft_print_wstr(list);
	}
	else
	{
		list->bytes = ft_wputstr(list->wargs);
		ft_return_wsize(list);
		if (ft_strcmp((char *)list->wargs, "(null)") == 0)
			ft_strdel((void *)&list->wargs);
		ft_clear_flags(list);
		return ;
	}
}
