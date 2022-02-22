/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmesseng <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:29:50 by dmesseng          #+#    #+#             */
/*   Updated: 2021/12/03 17:10:31 by dmesseng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	skip_(char const *str, int i, char sep, int flag)
{
	if (flag == 0)
	{
		while (str[i] != '\0')
		{
			if (str[i] != sep)
				return (i);
			i++;
		}
	}
	else
	{
		while (str[i] != '\0')
		{
			if (str[i] == sep)
				return (i);
			i++;
		}
	}
	return (i);
}

static int	word_count(char const *str, char c)
{
	int	count;
	int	j;
	int	end;

	j = 0;
	count = 0;
	while (str[j] != '\0')
	{
		j = skip_(str, j, c, 0);
		end = skip_(str, j, c, 1);
		if (j < end)
			count += 1;
		j = end;
	}
	return (count);
}

static char	**clear_str(char **res)
{
	int	i;

	i = 0;
	while (res[i])
		free(res[i++]);
	free(res);
	return (NULL);
}

static char	**ft_split_cycle(const char *str, char c, char **res)
{
	int		end;
	int		i;
	int		j;
	char	*str_elem;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		i = skip_(str, i, c, 0);
		end = skip_(str, i, c, 1);
		if (i < end)
		{
			str_elem = (char *) malloc(sizeof(char) * (end - i + 1));
			res[j++] = ft_memcpy(str_elem, str + i, end - i);
			if (!res[j - 1])
				return (clear_str(res));
			res[j - 1][end - i] = '\0';
		}
		i = end;
	}
	res[j] = NULL;
	return (res);
}

char	**ft_split(char const *str, char c)
{
	int		count_;
	char	**res;

	if (!str)
		return (NULL);
	count_ = word_count(str, c);
	if (count_ == 0)
	{
		res = (char **)malloc(sizeof(char *));
		res[0] = NULL;
		return (res);
	}
	res = (char **) malloc (sizeof(char *) * (count_ + 1));
	if (res == NULL)
		return (NULL);
	return (ft_split_cycle(str, c, res));
}
