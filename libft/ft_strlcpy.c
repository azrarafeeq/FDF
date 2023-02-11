/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:45:37 by arafeeq           #+#    #+#             */
/*   Updated: 2022/04/22 17:01:39 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size)
{
	size_t	srclen;
	size_t	i;

	srclen = ft_strlen(src);
	i = 0;
	if (dst_size != 0)
	{
		while (src[i] && i < (dst_size - 1))
		{
			dst[i] = src[i];
			i++;
		}
	}
	else
		return (srclen);
	dst[i] = '\0';
	return (srclen);
}
