/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_letters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:13:03 by gmeizo            #+#    #+#             */
/*   Updated: 2019/04/11 19:21:25 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_letters(char *str, char c)
{
	int count;

	count = 0;
	if (!str)
		return (0);
	while (*str != c && *str)
	{
		str++;
		count++;
	}
	return (count);
}
