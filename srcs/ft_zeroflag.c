/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zeroflag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 15:56:45 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/17 23:23:07 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_zhashflag(t_flags *list)
{
	char	*newarg;
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	newarg = ft_strnew((int)ft_strlen(list->args) + 2);
	while (j < ft_atoi(list->digit) - (int)ft_strlen(list->args) + 2)
		j++;
	tmp = list->args + j;
	while (list->args[i])
	{
		if (list->conv == 'X' && newarg[0] != '0')
			newarg = ft_strcpy(newarg, "0X");
		else if ((list->conv == 'x'|| list->conv == 'p') && newarg[0] != '0')
			newarg = ft_strcpy(newarg, "0x");
		else if ((list->conv == 'o' || list->conv == 'O') && newarg[0] != '0')
			newarg = ft_strcpy(newarg, "0");
		i++;
	}
	newarg = ft_strcat(newarg, tmp);
	ft_strdel(&list->args);
	list->args = ft_reallocf(newarg, 0);
}

void	ft_zeroflag(t_flags *list)
{
	char	*newarg;
	char	*tmp;
	char	*tmparg;
	int		digit;
	int		i;
	int		size;

	i = 0;
	if (list->conv == 'p')
		ft_cut_lststr(list,2);
	size = (int)ft_strlen(list->args);
	digit = ft_atoi(list->digit);
	newarg = ft_strnew(size + digit);
	if (list->args != NULL)
	{
		if (list->args[0] == '-')
			size -= 1;
		if ((list->args[0] == '\0' && list->conv == 'c') || list->space > 0)
			digit -= 1;
	}
	if (list->noconv > 0)
		digit -= 1;
	while (i < (digit - (int)ft_strlen(list->args)))
	{
		newarg[i] = '0';
		i++;
	}
	//printf("dgt[%d]\nsize[%d]\n",ft_atoi(list->digit),size);
	if (digit > 0 && size < digit)
	{
	//	printf("Hoy\n");
		newarg[i] = '\0';
	}
	else if (i > 0)
		newarg[i] = '\0';
	if (list->args != NULL && (list->args[0] == '-' || list->args[0] == '+') && list->noconv == 0)
	{
		tmp = ft_strnew(1);
		if (list->args[0] == '-')
			tmp[0] = '-';
		else
			tmp[0] = '+';
		list->args++;
		tmparg = ft_strjoin(tmp, newarg);
		ft_strdel(&tmp);
		ft_strdel(&newarg);
		newarg = ft_strjoin(tmparg, list->args);
		list->args--;
		tmp = list->args;
	}
	else
	{
		tmparg = newarg;
		tmp = list->args;
		newarg = ft_strjoin(tmparg, list->args);
	}
	ft_strdel(&tmparg);
	ft_strdel(&tmp);
	list->args = ft_reallocf(newarg, 0);
}
