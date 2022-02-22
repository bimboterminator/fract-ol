/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmesseng <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 17:24:18 by dmesseng          #+#    #+#             */
/*   Updated: 2021/10/09 15:00:41 by dmesseng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*pos;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s);
	pos = NULL;
	while (i <= len)
	{
		if (s[i] == (char)c)
			pos = (char *)&s[i];
		i++;
	}
	return (pos);
}
