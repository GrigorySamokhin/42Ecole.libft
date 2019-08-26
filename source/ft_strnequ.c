/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:29:51 by gmeizo            #+#    #+#             */
/*   Updated: 2019/04/16 15:22:45 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	if (!s1 || !s2)
		return (0);
	if (n == 0)
		return (1);
	i = 0;
	while (s1[i] && s1[i] == s2[i] && i < (n - 1))
		++i;
	if (((unsigned char)s1[i] - (unsigned char)s2[i]) == 0)
		return (1);
	return (0);
}
