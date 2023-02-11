/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 16:48:00 by arafeeq           #+#    #+#             */
/*   Updated: 2022/05/12 10:26:03 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		integer[4];

	integer[0] = 0;
	integer[1] = 0;
	if (!(s1) || !(s2))
		return (NULL);
	integer[2] = ft_strlen(s1);
	integer[3] = ft_strlen(s2);
	str = (char *)malloc (sizeof(char) * (integer[2] + integer[3] + 1));
	if (!(str))
		return (NULL);
	while (s1[integer[0]] != '\0' && integer[0] <= integer[2])
	{
		str[integer[0]] = s1[integer[0]];
		integer[0]++;
	}
	while (s2[integer[1]] != '\0' && integer[0] <= (integer[2] + integer[3]))
	{
		str[integer[0]] = s2[integer[1]];
		integer[0]++;
		integer[1]++;
	}
	str[integer[0]] = '\0';
	return (str);
}
