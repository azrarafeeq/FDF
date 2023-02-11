/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:17:46 by arafeeq           #+#    #+#             */
/*   Updated: 2022/10/07 12:32:23 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	number_length(int n)
{
	int	intlen;

	intlen = 1;
	n = n / 10;
	while (n)
	{
		n = n / 10;
		intlen++;
	}
	return (intlen);
}

char	*number_conversion(int num, char *str, int len)
{
	while (num)
	{
		str[--len] = (num % 10) + '0';
		num = num / 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char				*str;
	int					len;
	unsigned int		num;

	num = n;
	len = number_length(n);
	if (n < 0)
	{
		len++;
		num = n * -1;
	}
	str = (char *)malloc (sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	str[--len] = (num % 10) + '0';
	num = num / 10;
	number_conversion(num, str, len);
	if (n < 0)
		str[0] = '-';
	return (str);
}
