/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:43:34 by arafeeq           #+#    #+#             */
/*   Updated: 2022/05/29 11:27:26 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dstptr;
	char	*srcptr;
	size_t	i;

	if (!dst && !src)
		return (NULL);
	dstptr = (char *)dst;
	srcptr = (char *)src;
	i = 0;
	if (srcptr < dstptr)
	{
		while (len-- > 0)
			dstptr[len] = srcptr[len];
	}
	else
	{
		while (i < len)
		{
			dstptr[i] = srcptr[i];
			i++;
		}
	}
	return (dst);
}
