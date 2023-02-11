/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:21:01 by arafeeq           #+#    #+#             */
/*   Updated: 2022/05/13 16:21:57 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_in_str(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i++])
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str1;
	size_t	b;
	size_t	e;

	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)s1);
	b = 0;
	e = ft_strlen(s1);
	while (char_in_str(set, s1[b]))
		b++;
	while (char_in_str(set, s1[e - 1]) && b < e)
		e--;
	str1 = (char *)malloc (sizeof(char) * (e - b) + 1);
	if (!str1)
		return (NULL);
	if (str1)
	{
		ft_strlcpy(str1, &s1[b], (e - b) + 1);
		return (str1);
	}
	return (NULL);
}
