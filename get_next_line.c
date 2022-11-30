/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecnam <yecnam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:19:03 by yecnam            #+#    #+#             */
/*   Updated: 2022/11/30 18:00:16 by yecnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

int	check_nextline(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	make_arr(char **s, int fd)
{
	int		temp;
	char	*buf;
	char	*tmp;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	while (!check_nextline(*s))
	{
		temp = read(fd, buf, BUFFER_SIZE);
		if (temp == 0 || temp == -1)
		{
			free(buf);
			if (temp == 0)
				return (1);
			return (0);
		}
		buf[temp] = 0;
		tmp = *s;
		*s = ft_strjoin(tmp, buf);
		free(tmp);
		if (!*s)
		{
			free(buf);
			return (0);
		}
	}
	free(buf);
	return (1);
}

char	*make_return(t_list **lst)
{
	int		i;
	int		j;
	int		save;
	char	*s;
	char	*back;

	i = 0;
	if (!(*lst)->content || (*lst)->content[0] == 0)
		return (0);
	while ((*lst)->content[i] != '\n' && (*lst)->content[i])
		i++;
	s = (char *)malloc(sizeof(char) * (i + 1));
	if (!s)
		return (0);
	save = ++i;
	while (--i >= 0)
		s[i] = (*lst)->content[i];
	s[save - 1] = 0;
	i = ft_strlen((*lst)->content);
	back = (char *)malloc(sizeof(char) * (i - save + 1));
	j = 0;
	while (save < i + 1)
		back[j++] = (*lst)->content[save++];
	(*lst)->content = back;
	return (s);
}

t_list	*get_next(t_list *head, t_list *next, int fd)
{
	while (next)
	{
		if (next->fd == fd)
			break ;
		next = next->next;
	}
	if (!next)
	{
		if (!make_lst(fd, &next))
			return (0);
		head = lst_addback(head, next);
	}
	return (next);
}

char	*get_next_line(int fd)
{
	static t_list	*head;
	t_list			*next;
	char			*s;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
		return (0);
	if (!head)
		if (!make_lst(fd, &head))
			return (0);
	next = head;
	next = get_next(head, next, fd);
	if (!next)
		return (0);
	if (!check_nextline(next->content))
		if (!make_arr(&next->content, fd))
			return (0);
	s = make_return(&next);
	while (head && !s)
	{
		next = head;
		free(next->content);
		free(next);
		head = head->next;
	}
	return (s);
}

//#include <fcntl.h>
//int main()
//{
//	int	fd;
//	// int	fd2;
//	int	i;
//	char *str;

//	i = 0;
//	fd = open("text", O_RDONLY);
//	// fd2 = open("text2", O_RDONLY);
	
//	while (fd)
//	{
//		str = get_next_line(fd);
//		printf("str: %s\n", str);
//		if (!str)
//			return (0);
//		// printf("fd  %d: %s\n", i, get_next_line(fd));
//		// printf("fd2 %d: %s\n", i, get_next_line(fd2));
//		i++;
//	}

//}