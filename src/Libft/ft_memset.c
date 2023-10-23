/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:52:50 by gmarchal          #+#    #+#             */
/*   Updated: 2023/04/27 17:37:30 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, int len)
{
	int				i;
	unsigned char	val;
	unsigned char	*ret;

	i = 0;
	val = (unsigned char)c;
	ret = b;
	while (i < len)
	{
		ret[i] = val;
		i++;
	}
	return (ret);
}
