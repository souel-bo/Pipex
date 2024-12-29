/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souel-bo <souel-bo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:32:48 by souel-bo          #+#    #+#             */
/*   Updated: 2024/12/28 21:08:42 by souel-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static size_t	count_word(char const *s, char c)
{
	size_t	i;
	size_t	counter;

	i = 0;
	counter = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if ((i > 0) && (s[i - 1] != c) && (s[i] == c))
			counter++;
		i++;
	}
	if (i > 0 && (s[i - 1] != c))
		counter++;
	return (counter);
}

static char	*ft_splitcopy(char const *s, int start, int finish)
{
	int		i;
	int		size;
	char	*word;

	i = 0;
	size = finish - start;
	word = (char *)malloc(sizeof(char) * (size + 1));
	if (!word)
		return (NULL);
	while (start < finish)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

static void	ft_free(char **split, size_t words)
{
	size_t	i;

	i = 0;
	while (i < words)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static char	**split_help(char **splited, char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;

	i = -1;
	j = 0;
	index = -1;
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if (((s[i] == c || i >= ft_strlen(s)) && (index >= 0)))
		{
			splited[j] = ft_splitcopy(s, index, i);
			if (!splited[j])
			{
				ft_free(splited, j);
				return (NULL);
			}
			j++;
			index = -1;
		}
	}
	splited[j] = NULL;
	return (splited);
}

char	**ft_split(char const *s, char c)
{
	char	**splited;
	size_t	word_count;

	if (!s || s[0] == '\0')
	{
		splited = (char **)malloc(sizeof(char *));
		if (!splited)
			return (NULL);
		splited[0] = NULL;
		return (splited);
	}
	word_count = count_word(s, c);
	splited = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!splited)
		return (NULL);
	splited = split_help(splited, s, c);
	if (!splited)
		return (NULL);
	return (splited);
}
