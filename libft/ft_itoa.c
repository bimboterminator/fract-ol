/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmesseng <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:07:12 by dmesseng          #+#    #+#             */
/*   Updated: 2021/10/08 21:19:19 by dmesseng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	get_num(int *buf, char *dest, size_t pos, int sign)
{
	size_t	j;
	int		tmp_pos;

	tmp_pos = (int)pos;
	j = 0;
	if (sign == -1)
		j = 1;
	while (tmp_pos >= 0)
	{
		dest[j++] = buf[tmp_pos--] + '0';
	}
	dest[j] = '\0';
}

static char	*allocate_memory(int sign, size_t i)
{
	char	*result;

	if (sign == -1)
	{
		result = (char *)malloc(i + 2);
		if (result == NULL)
			return (NULL);
		result[0] = '-';
		result[i + 1] = '\0';
	}
	else
	{
		result = (char *)malloc(i + 1);
		if (result == NULL)
			return (NULL);
		result[i] = '\0';
	}
	return (result);
}

char	*ft_itoa(int n)
{
	int		buf[64];
	size_t	i;
	char	*result;
	int		sign;

	sign = 1;
	if (n < 0)
		sign = -1;
	i = 0;
	if (n == 0)
		buf[i++] = 0;
	while (n != 0)
	{
		buf[i++] = sign * (n % 10);
		n /= 10;
	}
	result = allocate_memory(sign, i);
	if (result == NULL)
		return (NULL);
	get_num(buf, result, i - 1, sign);
	return (result);
}
