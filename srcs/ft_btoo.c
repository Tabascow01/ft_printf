/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btoo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 15:25:37 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/18 05:45:11 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_reverse2(char *str, int i)
{
	int		j;
	char	*tmp;

	j = 0;
	tmp = ft_strnew(i);
	i -= 1;
	while (i >= 0)
	{
		tmp[j] = str[i];
		i--;
		j++;
	}
	tmp[j] = '\0';
	ft_strdel(&str);
	str = tmp;
	return (str);
}

static void		ft_btoo_nnext(char **strtmp, char **strbin, int *i, int *j)
{
	if ((*i) == 1)
		(*strtmp)[(*j)] = (*strbin)[(*i) - 1] * 2 + (*strbin)[(*i)] + 48;
	else if ((*i) == 0)
		(*strtmp)[(*j)] = (*strbin)[(*i)] + 48;
	else
		(*j)--;
}

static void		ft_btoo_next(char **strbin, int *i)
{
	while ((*strbin)[(*i)])
	{
		(*strbin)[(*i)] = (*strbin)[(*i)] - 48;
		(*i)++;
	}
	(*i)--;
}

char			*ft_btoo(char *strbin)
{
	char		*strhex;
	char		*strtmp;
	int			tmp;
	int			i;
	int			j;

	i = 0;
	j = 0;
	strtmp = ft_strnew(ft_strlen(strbin));
	ft_btoo_next(&strbin, &i);
	while ((i - 2) >= 0)
	{
		tmp = strbin[i - 2] * 4 + strbin[i - 1] * 2 + strbin[i];
		strtmp[j++] = tmp + 48;
		i -= 4;
	}
	ft_btoo_nnext(&strtmp, &strbin, &i, &j);
	strhex = ft_reallocf(strtmp, (int)ft_strlen(strtmp));
	strhex = ft_reverse2(strhex, (int)ft_strlen(strhex));
	ft_strdel(&strbin);
	return (strhex);
}
