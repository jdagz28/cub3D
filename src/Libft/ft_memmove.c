/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:00:14 by gmarchal          #+#    #+#             */
/*   Updated: 2022/10/10 19:56:52 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*ch_src;
	char	*ch_dest;

	if (!src && !dest)
		return (0);
	if (n == 0)
		return (dest);
	ch_src = (char *)src;
	ch_dest = (char *)dest;
	if (ch_src < ch_dest)
	{
		i = n;
		while (--i > 0)
			ch_dest[i] = ch_src[i];
		ch_dest[i] = ch_src[i];
	}
	else
	{
		i = -1;
		while (++i < n)
			ch_dest[i] = ch_src[i];
	}
	return (dest);
}
