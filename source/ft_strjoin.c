/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:57:17 by gmeizo            #+#    #+#             */
/*   Updated: 2019/04/12 15:05:08 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		j;
	size_t		size;
	char		*str;

	if (!s2 || !s1)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	j += i;
	if (!(str = (char *)malloc(sizeof(char) * (j + 1))))
		return (NULL);
	ft_strncpy(str, s1, i);
	size = 0;
	while (size <= ft_strlen(s2))
	{
		str[i] = s2[size];
		size++;
		i++;
	}
	return (str);
}

char			*ft_buf_strjoin(char *str, char *str1, int ret)
{
	char *temp;
	char *temp2;
	char *s;

	temp = (ret == 0) ? str : str1;
	if (ret == 2)
	{
		temp = str;
		temp2 = str1;
	}
	s = ft_strjoin(str, str1);
	ft_strdel(&temp);
	(ret == 2) ? (ft_strdel(&temp2)) : 0;
	return (s);
}

char			*ft_strnjoin(char const *s1, char const *s2, int n)
{
	size_t		i;
	size_t		j;
	size_t		size;
	char		*str;

	if (!s2 || !s1)
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	if ((size_t)n < j)
		j = (size_t)n;
	j += i;
	if (!(str = (char *)malloc(sizeof(char) * (j + 1))))
		return (NULL);
	ft_strncpy(str, s1, i);
	size = 0;
	while (size <= ft_strlen(s2) && n--)
	{
		str[i] = s2[size];
		size++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
