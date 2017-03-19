/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 15:25:37 by mchemakh          #+#    #+#             */
/*   Updated: 2017/02/27 08:00:53 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_reverse(char *str, int i)
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

static void		ft_btoh_nnext(char **strtmp, char **strbin, int *i, int *j)
{
	if ((*i) == 1)
		(*strtmp)[(*j)] = (*strbin)[(*i) - 1] * 2 + (*strbin)[(*i)] + 48;
	else if ((*i) == 0)
		(*strtmp)[(*j)] = (*strbin)[(*i)] + 48;
	else
		(*j)--;
}

static void		ft_btoh_next(char **strbin, int *i)
{
	while ((*strbin)[(*i)])
	{
		(*strbin)[(*i)] = (*strbin)[(*i)] - 48;
		(*i)++;
	}
	(*i)--;
}

char			*ft_btoh(char *strbin)
{
	char		*strhex;
	char		*strtmp;
	int			tmp;
	int			i;
	int			j;

	i = 0;
	j = 0;
	strtmp = ft_strnew(ft_strlen(strbin));
	ft_btoh_next(&strbin, &i);
	while ((i - 2) >= 0)
	{
		tmp = strbin[i - 3] * 8 + strbin[i - 2] * 4 + strbin[i - 1] * 2 +
			strbin[i];
		if (tmp > 9)
			strtmp[j++] = tmp + 55;
		else
			strtmp[j++] = tmp + 48;
		i -= 4;
	}
	ft_btoh_nnext(&strtmp, &strbin, &i, &j);
	strhex = ft_reallocf(strtmp, (int)ft_strlen(strtmp));
	strhex = ft_reverse(strhex, (int)ft_strlen(strhex));
	ft_strdel(&strbin);
	return (strhex);
}
