/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmesseng <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 17:11:17 by dmesseng          #+#    #+#             */
/*   Updated: 2021/10/07 21:29:53 by dmesseng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		len_src;
	size_t	i;
	int		return_val;

	i = 0;
	len_src = ft_strlen(src);
	if (size == 0)
		return (len_src);
	while (dst[i] != '\0')
	{
		if (i == size - 1)
			return (size + len_src);
		i++;
	}
	return_val = i + len_src;
	while (*src != '\0' && i < size)
	{
		if (i == size - 1)
			break ;
		dst[i++] = *src;
		src++;
	}
	dst[i] = '\0';
	return (return_val);
}
