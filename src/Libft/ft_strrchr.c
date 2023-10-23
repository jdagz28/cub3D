/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:35:13 by gmarchal          #+#    #+#             */
/*   Updated: 2022/10/10 14:46:10 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ret;

	i = ft_strlen(s);
	ret = (char *)s;
	while (i >= 0)
	{
		if (s[i] == (char) c)
			return ((char *)&ret[i]);
		i--;
	}
	return (0);
}
