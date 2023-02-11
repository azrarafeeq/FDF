/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arafeeq <arafeeq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 12:40:37 by arafeeq           #+#    #+#             */
/*   Updated: 2022/09/30 12:57:33 by arafeeq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		lst_len;
	t_list	*temp;

	lst_len = 0;
	temp = lst;
	if (temp == NULL)
		return (0);
	while (temp->next != NULL)
	{
		temp = temp->next;
		lst_len++;
	}
	if (temp->next == NULL)
		lst_len++;
	return (lst_len);
}
