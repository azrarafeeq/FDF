/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:17:29 by arafeeq           #+#    #+#             */
/*   Updated: 2022/11/30 18:37:19 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	number_of_words(const char *s, char c)
{
	int	i;
	int	word_count;

	i = 0;
	word_count = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			word_count++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (word_count);
}

char	*word_append(const char *s, int begin, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = (char *)malloc(sizeof(char) * (end - begin + 1));
	if (!word)
		return (NULL);
	while (i < end - begin && s[i] != '\0')
	{
		word[i] = s[begin + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		integer[3];

	if (!s)
		return (NULL);
	array = malloc(sizeof(char *) * (number_of_words(s, c) + 1));
	if (!array)
		return (NULL);
	integer[0] = 0;
	integer[2] = 0;
	while (s[integer[0]] != '\0')
	{
		while (s[integer[0]] == c)
			integer[0]++;
		if (s[integer[0]] != c && s[integer[0]])
		{
			integer[1] = integer[0];
			while (s[integer[0]] != '\0' && s[integer[0]] != c)
				integer[0]++;
			array[integer[2]++] = word_append(s, integer[1], integer[0]);
		}
	}
	array[integer[2]] = NULL;
	return (array);
}
