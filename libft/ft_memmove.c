/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmesseng <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 17:20:49 by dmesseng          #+#    #+#             */
/*   Updated: 2021/10/06 19:14:38 by dmesseng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*c_dest;
	char	*c_src;

	c_dest = dest;
	c_src = (char *)src;
	if (dest == NULL && src == NULL)
		return (dest);
	while (n > 0)
	{
		if (c_dest - c_src > 0)
			*(c_dest + n - 1) = *(c_src + n - 1);
		else
		{
			*c_dest = *c_src;
			c_dest++;
			c_src++;
		}
		n--;
	}
	return (dest);
}
