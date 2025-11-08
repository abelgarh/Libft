/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelgarh <abelgarh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:20:59 by abelgarh          #+#    #+#             */
/*   Updated: 2025/11/01 19:10:37 by abelgarh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	sln;
	size_t	dln;
	size_t	pdst;
	size_t	i;

	if (dstsize == 0 && !dst)
		return (ft_strlen(src));
	sln = ft_strlen(src);
	dln = ft_strlen(dst);
	pdst = dln;
	i = 0;
	if (dstsize <= dln || dstsize == 0)
		return (dstsize + sln);
	while (src[i] != '\0' && i < (dstsize - dln - 1))
	{
		dst[pdst] = src[i];
		pdst++;
		i++;
	}
	dst[pdst] = '\0';
	return (dln + sln);
}
