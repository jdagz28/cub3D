/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:25:16 by gmarchal          #+#    #+#             */
/*   Updated: 2022/10/18 16:41:57 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_digits(int n, int *is_neg)
{
	size_t		len;
	long int	nb;

	*is_neg = 0;
	len = 1;
	nb = n;
	if (nb < 0)
	{
		*is_neg = 1;
		nb *= -1;
	}
	while (nb >= 10)
	{
		nb /= 10;
		len++;
	}
	return (len + *is_neg);
}

char	*ft_itoa(int n)
{
	long int	nb;
	int			len;
	int			is_neg;
	char		*str;

	nb = n;
	len = ft_count_digits(nb, &is_neg);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len] = '\0';
	len--;
	if (nb < 0)
		nb *= -1;
	while (len >= 0)
	{
		str[len] = (nb % 10) + '0';
		nb /= 10;
		--len;
	}
	if (is_neg)
		str[0] = '-';
	return (str);
}
/*
#include <stdio.h>
int	main(void)
{
	int	n;
	
	n = -25;
	while (n < 1101)
	{
		printf("%s,	", ft_itoa(n));
		n++;
	}
	return (0);
}
*/
