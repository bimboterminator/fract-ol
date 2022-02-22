/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmesseng <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:57:12 by dmesseng          #+#    #+#             */
/*   Updated: 2021/10/15 16:10:21 by dmesseng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;
	size_t	result_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		result_len = 0;
	else if (s_len - start < len)
		result_len = s_len - start;
	else
		result_len = len;
	substr = (char *)malloc(result_len + 1);
	if (substr == NULL)
		return (NULL);
	ft_strlcpy(substr, (const char *)&s[start], result_len + 1);
	substr[result_len] = '\0';
	return (substr);
}
