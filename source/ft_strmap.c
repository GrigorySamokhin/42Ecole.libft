/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:12:07 by gmeizo            #+#    #+#             */
/*   Updated: 2019/04/12 14:16:44 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		i;

	i = 0;
	if (s && f && (*s))
	{
		while (s[i])
			i++;
		if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
			return (NULL);
		str[i] = '\0';
		while (i--)
		{
			str[i] = (*f)(s[i]);
		}
		return (str);
	}
	return (NULL);
}
