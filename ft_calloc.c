/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelgarh <abelgarh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:11:04 by abelgarh          #+#    #+#             */
/*   Updated: 2025/11/06 19:39:22 by abelgarh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	size_t	total;
	void	*dest;

	total = nelem * elsize;
	if (elsize != 0 && (total / elsize) != nelem)
		return (NULL);
	dest = malloc(total);
	if (!dest)
		return (NULL);
	ft_bzero(dest, total);
	return (dest);
}
