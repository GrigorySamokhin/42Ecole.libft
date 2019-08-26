/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 12:23:10 by gmeizo            #+#    #+#             */
/*   Updated: 2019/04/12 15:43:40 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char			*str;
	unsigned char			*str1;

	str = (unsigned char *)dst;
	str1 = (unsigned char *)src;
	while (n--)
	{
		*str = *str1;
		str++;
		str1++;
	}
	return (dst);
}
