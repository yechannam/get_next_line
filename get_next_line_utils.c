/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecnam <yecnam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:19:06 by yecnam            #+#    #+#             */
/*   Updated: 2022/11/29 15:27:53 by yecnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	size;

	size = 0;
	if (!s)
		return (size);
	while (s[size] != 0)
		size++;
	return (size);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		len1;
	int		len2;
	int		i;

	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!str)
		return (0);
	while (i < len1 && s1)
	{
		str[i] = s1[i];
		i++;
	}
	while (i < len1 + len2 && s2)
	{
		str[i] = s2[i - len1];
		i++;
	}
	str[i] = 0;
	return (str);
}

int	make_lst(int fd, t_list **lst)
{
	*lst = (t_list *)malloc(sizeof(t_list));
	if (!(*lst))
		return (0);
	(*lst)->fd = fd;
	return (1);
}

t_list	*lst_addback(t_list *head, t_list *now)
{
	t_list	*lst;

	lst = head;
	while (lst->next)
		lst = lst->next;
	lst->next = now;
	return (head);
}