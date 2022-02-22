/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmesseng <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 13:41:14 by dmesseng          #+#    #+#             */
/*   Updated: 2021/10/09 14:15:54 by dmesseng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_clean(t_list *item, void (*del)(void *))
{
	if (item == NULL)
		return ;
	ft_clean(item->next, del);
	(*del)(item->content);
	free(item);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (*lst == NULL)
		return ;
	ft_clean(*lst, del);
	*lst = NULL;
}
