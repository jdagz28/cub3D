/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 18:02:38 by gmarchal          #+#    #+#             */
/*   Updated: 2022/10/07 16:25:15 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	c1;
	unsigned char	c2;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] - s2[i] != 0)
		{
			c1 = (unsigned char)s1[i];
			c2 = (unsigned char)s2[i];
			return (c1 - c2);
		}
		i++;
	}
	i--;
	return (0);
}
