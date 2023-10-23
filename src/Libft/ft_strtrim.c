/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:09:49 by gmarchal          #+#    #+#             */
/*   Updated: 2022/10/14 15:49:29 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_in_str(char c, char const *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*ret;

	if (!s1 || !set)
		return (0);
	start = 0;
	while (s1[start] && ft_is_in_str(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_is_in_str(s1[end - 1], set))
		end--;
	ret = malloc(sizeof(char) * (end - start + 1));
	if (!ret)
		return (0);
	i = 0;
	while (start < end)
	{
		ret[i] = s1[start];
		i++;
		start++;
	}
	ret[i] = '\0';
	return (ret);
}
