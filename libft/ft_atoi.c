/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:59:29 by arafeeq           #+#    #+#             */
/*   Updated: 2022/10/24 16:14:59 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ws_and_sign_check(const char *str, int *i, int *ve)
{
	while (str[*i] == '\t' || str[*i] == '\n' || str[*i] == '\v'
		|| str[*i] == '\f' || str[*i] == '\r' || str[*i] == ' ')
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*ve = -1;
		(*i)++;
	}
	return ;
}

int	ft_atoi(const char *str)
{
	int				i;
	int				ve;
	unsigned long	num;

	i = 0;
	ve = 1;
	num = 0;
	ws_and_sign_check(str, &i, &ve);
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
		if (num > 2147483647 && ve == 1)
			return (-1);
		if (num > 2147483648 && ve == -1)
			return (0);
	}
	return (num * ve);
}
