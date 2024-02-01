/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialzein <ialzein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 08:11:56 by ialzein           #+#    #+#             */
/*   Updated: 2023/11/23 09:52:50 by ialzein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

int		ft_strlen(const char *input);
char	*ft_strchr(const char *s, int c);
char	*ft_str_init(void);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_read(int fd, char *str);
char	*get_rest(char *file);
char	*ft_get_line(char *str);
char	*get_next_line(int fd);

#endif