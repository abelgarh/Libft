/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelgarh <abelgarh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:23:53 by ybounite          #+#    #+#             */
/*   Updated: 2025/11/01 17:11:30 by abelgarh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **result, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(result[i]);
		i++;
	}
	free(result);
}

static char	*full_arrys(char const *str, size_t len)
{
	char	*ptr;

	ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, str, len);
	ptr[len] = '\0';
	return (ptr);
}

static size_t	count_word(char const *str, char character)
{
	size_t	count;
	size_t	sign;
	size_t	i;

	i = 0;
	count = 0;
	sign = 1;
	while (str[i])
	{
		if (sign == 1 && (str[i] != character))
		{
			count++;
			sign = 0;
		}
		if (str[i] == character)
			sign = 1;
		i++;
	}
	return (count);
}

static size_t	lenofword(char const *str, char character)
{
	size_t	len;

	len = 0;
	while (str[len] && str[len] != character)
		len++;
	return (len);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	index;
	char	**ptr;

	index = 0;
	i = 0;
	if (!s)
		return (NULL);
	ptr = malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!ptr)
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			ptr[index] = full_arrys(&s[i], lenofword(&s[i], c));
			if (!ptr[index])
				return (ft_free(ptr, index), NULL);
			i += lenofword(&s[i], c);
			index++;
		}
	}
	return ((ptr[index] = (NULL)), ptr);
}
