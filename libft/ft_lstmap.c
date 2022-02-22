/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmesseng <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 13:59:44 by dmesseng          #+#    #+#             */
/*   Updated: 2021/10/09 14:15:42 by dmesseng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*new;
	void	*new_cont;

	if (lst == NULL)
		return (NULL);
	new_cont = (*f)(lst->content);
	head = ft_lstnew(new_cont);
	if (head == NULL)
		return (NULL);
	lst = lst->next;
	while (lst != NULL)
	{
		new_cont = (*f)(lst->content);
		new = ft_lstnew(new_cont);
		if (new == NULL)
		{
			ft_lstclear(&head, del);
			break ;
		}
		ft_lstadd_back(&head, new);
		lst = lst->next;
	}
	return (head);
}
