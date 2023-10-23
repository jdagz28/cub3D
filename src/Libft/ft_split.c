/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarchal <gmarchal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:54:23 by gmarchal          #+#    #+#             */
/*   Updated: 2022/10/19 15:06:00 by gmarchal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *str, char sep)
{
	size_t	n_word;

	n_word = 0;
	while (*str)
	{
		while (*str && (*str == sep))
			str++;
		if (*str)
			n_word++;
		while (*str && (*str != sep))
			str++;
	}
	return (n_word);
}

static char	*ft_word(char const *str, char c)
{
	int		i;
	int		len_word;
	char	*word;

	i = 0;
	len_word = 0;
	while (str[len_word] && str[len_word] != c)
		len_word++;
	word = malloc((sizeof(char) * (len_word)) + 1);
	if (!word)
		return (NULL);
	while (i < len_word)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**ft_insert_to_tab(char **tab, char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		while (*s && (c == *s))
			s++;
		if (*s)
		{
			tab[i] = ft_word(s, c);
			if (!tab[i])
			{
				i = 0;
				while (tab[i])
					free(tab[i++]);
				free(tab);
				return (NULL);
			}
			i++;
		}
		while (*s && (c != *s))
			s++;
	}
	tab[i] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (0);
	tab = malloc(sizeof(char const *) * (ft_count_words(s, c) + 1));
	if (!tab)
		return (NULL);
	return (ft_insert_to_tab(tab, s, c));
}
