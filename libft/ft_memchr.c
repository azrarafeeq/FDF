/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:56:03 by arafeeq           #+#    #+#             */
/*   Updated: 2022/05/29 12:47:38 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	int		i;

	c = c % 256;
	str = (char *)s;
	i = 0;
	while (n != 0)
	{
		if (str[i] == c)
			return ((void *)str + i);
		i++;
		n--;
	}
	return (NULL);
}
