/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecnam <yecnam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:19:03 by yecnam            #+#    #+#             */
/*   Updated: 2022/11/29 16:01:39 by yecnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

int	check_nextline(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*make_arr(char *s, int fd)
{
	int		temp;
	char	*buf;

	buf = (char *)malloc((sizeof(char) * BUFFER_SIZE) + 1);
	if (!buf)
		return (0);
	while (check_nextline(buf))
	{
		temp = read(fd, buf, BUFFER_SIZE);
		if (temp == -1)
			return (0);
		if (temp == 0)
			return (s);
		buf[temp] = 0;
		s = ft_strjoin(s, buf);
	}
	return (s);
}

char	*make_return(t_list *lst)
{
	int	i;
	int save;
	char *s;
	char *back;

	i = 0;
	while (lst->content[i] != '\n')
		i++;
	printf("\n%d\n",i);
	s = (char *)malloc(sizeof(char) * (i + 1));
	save = ++i;
	while (i >= 0)
	{
		s[i] = lst->content[i];
		i--;
	}
	i = ft_strlen(lst->content);
	printf("\n%d\n",i);
	back = (char *)malloc(sizeof(char) * (i - save));
	while (save < i)
	{
		*back = lst->content[++save];
		back++;
	}
	back[save] = 0;
	lst->content = back;
	return (s);
}

char	*get_next_line(int fd)
{
	static t_list	*head;
	t_list			*next;
	char			*s;

	if (!head)
		head = make_lst(fd);
	next = head;
	while (next)
	{
		if (next->fd == fd)
			break ;
		next = next->next;
	}
	if (!next)
	{
		next = make_lst(fd);
		head = lst_addback(head, next);
	}
	if (!check_nextline(next->content))
		next->content = make_arr(next->content, fd);
	printf("%s\n", next->content);
	s = make_return(next);
	printf("%s \n\n",s);
	printf("%s\n", next->content);
	return (s);
}

#include <fcntl.h>
int main()
{
	int	fd;
	//int	fd2;

	fd = open("text", O_RDONLY);
	get_next_line(fd);
	//fd2 = open("text2", O_RDONLY);
	//get_next_line(fd2);
	//get_next_line(fd);
	//get_next_line(fd2);
}