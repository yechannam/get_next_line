/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecnam <yecnam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:19:09 by yecnam            #+#    #+#             */
/*   Updated: 2022/11/30 13:48:31 by yecnam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdlib.h>

typedef struct s_list
{
	int				fd;
	char			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
int		make_arr(char **s, int fd);
int		check_nextline(char *s);
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
int		make_lst(int fd, t_list **lst);
t_list	*lst_addback(t_list *head, t_list *now);
char	*make_return(t_list **lst);
t_list	*get_next(t_list *head, t_list *next, int fd);

#endif