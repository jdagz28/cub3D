/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:10:52 by gmarchal          #+#    #+#             */
/*   Updated: 2022/10/14 12:56:59 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*ret;

	if (!s1 || !s2)
		return (0);
	ret = malloc (sizeof(char const) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ret)
		return (0);
	i = 0;
	j = 0;
	while (s1[i])
	{
		ret[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		ret[j++] = s2[i];
		i++;
	}
	ret[j] = '\0';
	return (ret);
}
