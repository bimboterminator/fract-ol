/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmesseng <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 21:32:22 by dmesseng          #+#    #+#             */
/*   Updated: 2021/10/15 16:41:35 by dmesseng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	calc_size(char const *s1, char const *set, size_t ln, size_t *s)
{
	size_t	size;
	size_t	i;

	i = 0;
	size = 0;
	while (ft_strchr(set, s1[i]) != NULL && s1[i])
	{
		size++;
		i++;
	}
	*s = i;
	i = ln - 1;
	if (size == ln)
	{
		*s = 0;
		return (0);
	}
	while (ft_strchr(set, s1[i]) != NULL && s1[i])
	{
		size++;
		i--;
	}
	return (ln - size);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	len;
	size_t	res_len;
	size_t	start;

	if (s1 == NULL || set == NULL)
		return (NULL);
	len = ft_strlen(s1);
	res_len = calc_size(s1, set, len, &start);
	trimmed = ft_substr(s1, start, res_len);
	return (trimmed);
}
