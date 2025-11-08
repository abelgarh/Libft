/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelgarh <abelgarh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 17:37:05 by abelgarh          #+#    #+#             */
/*   Updated: 2025/10/31 12:25:48 by abelgarh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_n(long n)
{
	int	counter;

	counter = 0;
	while (n != 0)
	{
		n = n / 10;
		counter++;
	}
	return (counter);
}

static int	check_sign(long *res)
{
	int	sign;

	sign = 0;
	if (*res < 0)
	{
		sign = 1;
		*res = (*res) * (-1);
	}
	return (sign);
}

char	*ft_itoa(int n)
{
	int		sign;
	int		len;
	char	*ptr;
	long	res;

	res = n;
	if (res == 0)
		return (ft_strdup("0"));
	sign = check_sign(&res);
	len = len_n(res) + sign;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	ptr[len] = '\0';
	while (res != 0)
	{
		ptr[--len] = (res % 10) + '0';
		res = res / 10;
	}
	if (sign == 1)
		ptr[--len] = '-';
	return (ptr);
}
