/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaric <mmaric@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:03:30 by mmaric            #+#    #+#             */
/*   Updated: 2021/12/09 13:29:57 by mmaric           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

int	ft_word_count(char const *str, char sep)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == sep)
			i++;
		else
		{
			count++;
			while (str[i] != '\0' && str[i] != sep)
				i++;
		}
	}
	return (count);
}

char	*ft_sep(char *s, char c)
{
	while (*s == c)
		s++;
	return (s);
}

int	ft_len_word(char *s, char c, int len)
{
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	int		word_len;
	int		nb_word;
	char	**words;

	if (!s)
		return (NULL);
	words = malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (!words)
		return (NULL);
	nb_word = 0;
	while (*s != '\0' && ft_word_count(s, c))
	{
		word_len = 0;
		s = ft_sep((char *)s, c);
		word_len = ft_len_word((char *)s, c, word_len);
		s = s + word_len;
		words[nb_word] = malloc(sizeof(**words) * (word_len + 1));
		if (!words[nb_word])
			return (ft_free(words));
		ft_strlcpy(words[nb_word++], s - word_len, word_len + 1);
	}
	words[nb_word] = NULL;
	return (words);
}
