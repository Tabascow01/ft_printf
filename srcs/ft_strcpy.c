/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 21:16:28 by mchemakh          #+#    #+#             */
/*   Updated: 2016/11/14 22:11:29 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char const *src)
{
	int i;
	int j;

	j = 0;
	i = 0;
	if ((*dest == 0 && *src == 0))
		return (dest);
	while (src[i])
	{
		if (i < j)
			return (dest);
		if (i > j)
		{
			dest[i] = src[j];
		}
		else
			dest[i] = src[i];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
