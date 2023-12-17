/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:28:30 by gmarchal          #+#    #+#             */
/*   Updated: 2023/12/17 05:08:34 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*get_next_line(int fd);
int		ft_strlen_gnl(const char *s);
void	ft_bzero_gnl(void *s, int n);
char	*ft_strdup_mod(char *s1, int *check);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		ft_strlcpy_gnl(char *dst, const char *src, int size);

#endif
