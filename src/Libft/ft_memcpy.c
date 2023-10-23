/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:04:54 by gmarchal          #+#    #+#             */
/*   Updated: 2022/10/10 17:59:38 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*ch_src;
	char	*ch_dest;

	i = 0;
	if (!dest && !src)
		return (NULL);
	ch_src = (char *)src;
	ch_dest = (char *)dest;
	while (i < n)
	{
		ch_dest[i] = ch_src[i];
		i++;
	}
	return (ch_dest);
}
