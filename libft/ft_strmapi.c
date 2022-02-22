/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmesseng <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 19:24:43 by dmesseng          #+#    #+#             */
/*   Updated: 2021/10/08 19:34:27 by dmesseng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*copy;
	size_t	len;
	size_t	i;

	if (s == NULL)
		return (NULL);
	copy = ft_strdup(s);
	if (copy == NULL)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	while (i < len)
	{
		copy[i] = (*f)((unsigned int)i, copy[i]);
		i++;
	}
	return (copy);
}
