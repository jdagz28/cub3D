/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:43:55 by gmarchal          #+#    #+#             */
/*   Updated: 2022/10/10 14:34:10 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ret;

	i = 0;
	ret = (char *)s;
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *)&ret[i]);
		i++;
	}
	if (s[i] == (char) c)
		return ((char *)&ret[i]);
	return (0);
}
