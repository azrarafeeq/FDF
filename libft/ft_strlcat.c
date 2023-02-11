/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:48:09 by arafeeq           #+#    #+#             */
/*   Updated: 2022/05/08 10:38:05 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dst_size)
{
	size_t		i;
	size_t		dstlen;
	size_t		srclen;
	size_t		result;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	result = ft_strlen(dst) + srclen;
	i = 0;
	if (dst_size == 0)
		return (srclen);
	if (dst_size < dstlen)
		return (dst_size + srclen);
	while (dstlen < dst_size - 1 && src[i] != '\0')
	{
		dst[dstlen] = src[i];
		dstlen++;
		i++;
	}
	dst[dstlen] = '\0';
	return (result);
}
