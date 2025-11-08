/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelgarh <abelgarh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:02:53 by abelgarh          #+#    #+#             */
/*   Updated: 2025/11/01 09:32:06 by abelgarh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*remember;

	remember = NULL;
	while (*s)
	{
		if (*s == (char)c)
			remember = s;
		s++;
	}
	if (*s == (char)c)
		remember = s;
	return ((char *)remember);
}
