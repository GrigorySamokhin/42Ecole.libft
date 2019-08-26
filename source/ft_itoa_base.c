/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:44:49 by gmeizo            #+#    #+#             */
/*   Updated: 2019/04/10 17:48:12 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_set_base(int base, uintmax_t num)
{
	if (base == 16)
	{
		if (num % base + '0' == '?')
			return ('f');
		if (num % base + '0' == '>')
			return ('e');
		if (num % base + '0' == '=')
			return ('d');
		if (num % base + '0' == '<')
			return ('c');
		if (num % base + '0' == ';')
			return ('b');
		if (num % base + '0' == ':')
			return ('a');
	}
	return (num % base + '0');
}

char			*ft_itoa_uintmax_base(uintmax_t num, int base)
{
	int			length;
	char		*str;

	if (num == 0)
		return (ft_strdup("0"));
	length = ft_numbsize_uintmax(num, base);
	str = (char *)malloc(sizeof(char) * (length + 1));
	str[length] = ENDL;
	while (num > 0)
	{
		str[--length] = ft_set_base(base, num);
		num /= base;
	}
	return (str);
}

char			*ft_itoa_intmax_base(intmax_t num, int base)
{
	int			length;
	char		*str;
	int			neg;
	uintmax_t	max;

	neg = 0;
	max = num;
	if (num < 0)
	{
		neg++;
		max = num * -1;
	}
	if (num == 0)
		return (ft_strdup("0"));
	length = ft_numbsize_intmax(max, base);
	str = (char *)malloc(sizeof(char) * (length + 1));
	str[length] = ENDL;
	while (max > 0)
	{
		str[--length] = ft_set_base(base, max);
		max /= base;
	}
	if (neg)
		str = ft_buf_strjoin("-", str, 1);
	return (str);
}
