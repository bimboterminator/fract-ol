/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmesseng <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 17:29:44 by dmesseng          #+#    #+#             */
/*   Updated: 2021/10/15 15:20:17 by dmesseng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmeb, size_t size)
{
	void	*memseg;

	memseg = malloc(nmeb * size);
	if (memseg == NULL)
		return (memseg);
	if (nmeb != 0 && size != 0)
		ft_memset(memseg, 0, nmeb * size);
	return (memseg);
}
