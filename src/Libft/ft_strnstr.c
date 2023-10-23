/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:19:42 by gmarchal          #+#    #+#             */
/*   Updated: 2023/04/24 12:31:25 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, int len)
{
	int		i;
	int		j;
	char	*ret;

	i = -1;
	ret = (char *) haystack;
	if (ft_strlen(needle) == 0)
		return (ret);
	if (len == 0)
		return (0);
	while (haystack[++i])
	{
		j = -1;
		while (needle[++j])
		{
			if (haystack[i + j] == needle[j] && i + j < len)
			{
				if (j == ft_strlen(needle) - 1)
					return (&ret[i]);
			}
			else
				break ;
		}
	}
	return (0);
}
