/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zeroflag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 15:56:45 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/27 02:56:37 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>//

static void		ft_zeroflag_nn(t_flags *list, char **tmparg, char **newarg)
{
	char *tmp;

	if (list->args != NULL && (list->args[0] == '-' || list->args[0] == '+')
			&& list->noconv == 0)
	{
		tmp = ft_strnew(1);
		if (list->args[0] == '-')
			tmp[0] = '-';
		else
			tmp[0] = '+';
		list->args++;
		(*tmparg) = ft_strjoin(tmp, (*newarg));
		ft_strdel(&tmp);
		ft_strdel((*&newarg));
		(*newarg) = ft_strjoin((*tmparg), list->args);
		list->args--;
		tmp = list->args;
	}
	else
	{
		(*tmparg) = (*newarg);
		tmp = list->args;
		(*newarg) = ft_strjoin((*tmparg), list->args);
	}
	ft_strdel(&tmp);
}

static void		ft_zeroflag_n(t_flags *list, int *size, int *digit)
{
	if (list->args != NULL)
	{
		if (list->args[0] == '-')
			(*size) -= 1;
		if ((list->args[0] == '\0' && list->conv == 'c') || list->space > 0)
			(*digit) -= 1;
	}
	if (list->noconv > 0)
		(*digit) -= 1;
}

void			ft_zeroflag(t_flags *list)
{
	char	*newarg;
	char	*tmparg;
	int		digit;
	int		i;
	int		size;

	i = 0;
	if (list->conv == 'p')
		ft_cut_lststr(list, 2);
	size = (int)ft_strlen(list->args);
	digit = ft_atoi(list->digit);
	newarg = ft_strnew(size + digit);
	ft_zeroflag_n(list, &size, &digit);
	while (i < (digit - (int)ft_strlen(list->args)))
		newarg[i++] = '0';
	if (digit > 0 && size < digit)
		newarg[i] = '\0';
	else if (i > 0)
		newarg[i] = '\0';
	ft_zeroflag_nn(list, &tmparg, &newarg);
	ft_strdel(&tmparg);
	list->args = ft_reallocf(newarg, 0);
}

void			ft_zhashflag(t_flags *list)
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
		else if ((list->conv == 'x' || list->conv == 'p') && newarg[0] != '0')
			newarg = ft_strcpy(newarg, "0x");
		else if ((list->conv == 'o' || list->conv == 'O') && newarg[0] != '0')
			newarg = ft_strcpy(newarg, "0");
		i++;
	}
	newarg = ft_strcat(newarg, tmp);
	ft_strdel(&list->args);
	list->args = ft_reallocf(newarg, 0);
}

void			ft_strzhash(t_flags *list, char **str)
{
	char	*newarg;
	int		i;
	char	*tmp;
	char	*tmparg;

	i = 0;
	tmparg = ft_strnew(list->dig2);
	while ((*str)[i] && (*str)[i] == ' ')
	{
		tmparg[i] = (*str)[i];
		i++;
	}
	tmp = &(*str)[i];
	newarg = ft_strnew((int)ft_strlen(list->args) + 2);
	if (list->conv == 'x')
		newarg = ft_strcpy(newarg, "0x");
	else if (list->conv == 'X')
		newarg = ft_strcpy(newarg, "0X");
	else if ((list->conv == 'o' || list->conv == 'O')
			&& list->dig2 <= (int)ft_strlen(list->args)
			&& list-> dig1 > (int)ft_strlen(list->args))
		newarg = ft_strcpy(newarg, "0");
	newarg = ft_strjoin(newarg, tmp);
	(*str) = ft_strjoin(tmparg, newarg);
	ft_strdel(&tmparg);
	ft_strdel(&newarg);
	(*str) = ft_reallocf((*str), 0);
	return ;
}
