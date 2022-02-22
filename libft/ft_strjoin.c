/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmesseng <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 21:13:07 by dmesseng          #+#    #+#             */
/*   Updated: 2021/10/08 17:31:20 by dmesseng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*concat;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	concat = (char *)malloc(len_s1 + len_s2 + 1);
	if (concat == NULL)
		return (concat);
	concat[0] = '\0';
	ft_strlcat(concat, s1, len_s1 + len_s2 + 1);
	ft_strlcat(concat, s2, len_s2 + len_s1 + 1);
	return (concat);
}
