/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmesseng <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 17:20:02 by dmesseng          #+#    #+#             */
/*   Updated: 2021/10/06 19:13:43 by dmesseng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*c_dest;
	char	*c_src;

	c_dest = dest;
	c_src = (char *)src;
	if ((dest == NULL && src == NULL) || n == 0)
		return (dest);
	while (n--)
		*c_dest++ = *c_src++;
	return (dest);
}
