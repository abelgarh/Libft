/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelgarh <abelgarh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:42:25 by abelgarh          #+#    #+#             */
/*   Updated: 2025/11/01 15:13:27 by abelgarh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if ((!big && little) && len == 0)
		return (NULL);
	if (little[0] == '\0')
		return ((char *)big);
	while (big[i] && len > i)
	{
		j = 0;
		while ((big[i + j] && little[j]) && (big[i + j] == little[j]) && (i
				+ j < len))
			j++;
		if (little[j] == '\0')
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
