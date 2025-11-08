/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelgarh <abelgarh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 09:16:55 by abelgarh          #+#    #+#             */
/*   Updated: 2025/10/31 12:27:15 by abelgarh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checker(char s, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	end;
	size_t	i;
	size_t	st;
	size_t	len;
	char	*dest;

	st = 0;
	if (!s1 || !set)
		return (NULL);
	end = ft_strlen(s1);
	while (s1[st] && checker(s1[st], set))
		st++;
	while (end > st && checker(s1[end - 1], set))
		end--;
	len = end - st;
	if (len == 0)
		return (ft_strdup(""));
	dest = (char *)malloc(len + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (st < end)
		dest[i++] = s1[st++];
	dest[i] = '\0';
	return (dest);
}
