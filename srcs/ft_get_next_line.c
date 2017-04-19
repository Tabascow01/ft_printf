/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 18:04:54 by mchemakh          #+#    #+#             */
/*   Updated: 2017/04/06 20:33:53 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_cut_str(char **stock, char *newstr)
{
	int		j;
	char	*tmp;
	size_t	size;
	char	*c;

	size = ft_strlen(newstr);
	tmp = NULL;
	if (((*stock)[size] == '\n' || (*stock)[size + 1] != '\0'))
		size++;
	j = 0;
	if ((*stock)[0] == '\n' && (*stock)[1] == '\0')
		return ;
	if (size > 0)
	{
		tmp = ft_strnew((ft_strlen((*stock)) - size) + 1);
		while ((*stock)[size] != '\0')
		{
			tmp[j++] = (*stock)[size];
			size++;
		}
		tmp[j] = '\0';
		c = (*stock);
		(*stock) = ft_reallocf(tmp, 1);
		ft_strdel(&c);
	}
}

static char		*ft_get_line(char **storage, char *b, int sizeread)
{
	int		i;
	int		j;
	char	*newstr;
	int		size;

	size = 0;
	i = 0;
	j = 0;
	if (ft_strlen(b) > 0)
		if (sizeread == 0)
			while (b[j++])
				b[j] = (b[j] == '\n' && b[j + 1] == '\0') ? '\0' : b[j];
	(*storage) = ft_reallocf((*storage), ft_strlen(b) + 1);
	(*storage) = (b[0] != '\0') ? ft_strcat((*storage), b) : (*storage);
	while (((*storage)[size] != '\n' && (*storage)[size] != '\0'))
		size++;
	newstr = ft_strnew(size);
	j = i;
	while ((*storage)[i] != '\n' && (*storage)[i] != '\0')
		newstr[j++] = (*storage)[i++];
	newstr[i] = '\0';
	if (ft_strlen((*storage)) > 0)
		ft_cut_str(storage, newstr);
	ft_strdel(&b);
	return (newstr);
}

static char		**ft_check_fd(int fd, t_list **list)
{
	t_list *tmp;

	tmp = *list;
	while (tmp && tmp->content_size != (size_t)fd)
		tmp = tmp->next;
	if (tmp)
		return ((char **)(&(tmp->content)));
	tmp = ft_lstnew(NULL, 0);
	tmp->content_size = (size_t)fd;
	ft_lstadd(list, tmp);
	return ((char **)(&(tmp->content)));
}

static void		ft_read_fd(int *sizeread, int *size, int fd, char **buf)
{
	(*buf) = ft_strnew(BUFF_SIZE);
	while (((*sizeread) = read(fd, (*buf) + (*size), BUFF_SIZE)) &&
			(ft_strchr((*buf) + (*size), '\n') == 0))
	{
		if ((*sizeread) == -1)
			return ;
		(*size) += (*sizeread);
		(*buf) = ft_reallocf((*buf), (*sizeread));
	}
	if ((*sizeread) > 0)
	{
		(*size) += (*sizeread);
		(*buf) = ft_reallocf((*buf), (*sizeread));
	}
	(*buf)[(*size)] = '\0';
}

int				ft_get_next_line(const int fd, char **line)
{
	static t_list	*lst = NULL;
	char			**stock;
	int				sizeread;
	int				size;
	char			*buf;

	if (fd < 0)
		return (-1);
	stock = ft_check_fd(fd, &lst);
	sizeread = 0;
	size = 0;
	ft_read_fd(&sizeread, &size, fd, &buf);
	if (sizeread < 0)
		return (-1);
	*line = ft_get_line(stock, buf, sizeread);
	if (ft_strlen((*stock)) > 0 || sizeread != 0 || *line[0] != '\0')
	{
		if (sizeread > 0)
			size = size - 1;
		if ((*stock)[0] == '\n' && (*stock)[1] == '\0' && size <= 0)
			(*stock)[0] = '\0';
		return (1);
	}
	ft_strdel(line);
	return (0);
}
