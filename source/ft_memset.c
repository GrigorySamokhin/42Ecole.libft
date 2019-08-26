/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:36:54 by gmeizo            #+#    #+#             */
/*   Updated: 2019/04/10 13:41:05 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*temp;
	int				size;

	temp = (unsigned char *)b;
	size = 0;
	while (len > 0)
	{
		temp[size] = (unsigned char)c;
		len--;
		size++;
	}
	return (temp);
}
