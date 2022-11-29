/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecnam <yecnam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:19:09 by yecnam            #+#    #+#             */
/*   Updated: 2022/11/29 13:57:32 by yecnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

typedef struct s_list
{
	int				fd;
	char			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
char	*make_arr(char *s, int fd);
int		check_nextline(char *s);
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
t_list	*make_lst(int fd);
t_list	*lst_addback(t_list *head, t_list *now);
char	*make_return(t_list *lst);

#endif