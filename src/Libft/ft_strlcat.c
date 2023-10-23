/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:34:44 by gmarchal          #+#    #+#             */
/*   Updated: 2022/10/07 14:17:42 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	srcsize;
	size_t	dstsize2;

	i = 0;
	srcsize = 0;
	srcsize = ft_strlen(src);
	if (dstsize == 0)
		return (srcsize);
	dstsize2 = ft_strlen(dst);
	i = dstsize2;
	j = 0;
	if (dstsize < i)
		return (srcsize + dstsize);
	while (i < dstsize - 1 && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (srcsize + dstsize2);
}
