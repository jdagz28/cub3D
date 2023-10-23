/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:04:20 by gmarchal          #+#    #+#             */
/*   Updated: 2022/10/11 14:31:35 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	occ;
	unsigned char	*ret;

	i = 0;
	occ = (unsigned char)c;
	ret = (unsigned char *)s;
	while (i < n)
	{
		if (ret[i] == occ)
			return ((unsigned char *)&ret[i]);
		i++;
	}
	return (0);
}
