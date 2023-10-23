/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <gmarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 10:57:25 by gmarchal          #+#    #+#             */
/*   Updated: 2023/04/24 12:33:43 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, int start, int len)
{
	char	*ret;
	char	*src;

	src = (char *)s;
	if (!src)
		return (0);
	if (ft_strlen(src) < start)
		len = 0;
	else if (ft_strlen(src + start) < len)
		len = ft_strlen(src + start);
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	if (ft_strlen(src) < start)
		ret[0] = '\0';
	else
		ft_strlcpy(ret, src + start, len + 1);
	return (ret);
}
