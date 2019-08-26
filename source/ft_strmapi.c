/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:12:07 by gmeizo            #+#    #+#             */
/*   Updated: 2019/04/12 14:13:27 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
			str[i] = (*f)(i, s[i]);
		}
		return (str);
	}
	return (NULL);
}
