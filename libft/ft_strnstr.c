/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmesseng <dmesseng@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 17:25:06 by dmesseng          #+#    #+#             */
/*   Updated: 2022/02/08 23:12:02 by dmesseng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	check_len(size_t len)
{
	return (len);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	if ((little[0] == '\0')
		|| (little[0] == '\0' && big[0] == '\0'))
		return ((char *)big);
	i = 0;
	while (big[i] && i < check_len(len))
	{
		if (big[i] == little[0])
		{
			j = 0;
			k = i;
			while (big[k] && little[j] && big[k] == little[j] && k < len)
			{
				k++;
				j++;
			}
			if (little[j] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
