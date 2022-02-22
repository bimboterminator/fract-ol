/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmesseng <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 17:32:25 by dmesseng          #+#    #+#             */
/*   Updated: 2021/12/04 16:20:04 by dmesseng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*skip_spaces(const char *str)
{
	while (*str == ' ' || *str == '\t' || *str == '\v'
		|| *str == '\r' || *str == '\n' || *str == '\f')
		str++;
	return ((char *)str);
}

long int	ft_atoi(const char *nptr)
{
	long	n;
	int		sign;
	char	*str;

	sign = 1;
	n = 0;
	str = skip_spaces(nptr);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		n = n * 10 + (*str - '0') * sign;
		str++;
	}
	if (n < 0 && sign == 1)
		return (-1);
	else if (n > 0 && sign == -1)
		return (0);
	return (n);
}
