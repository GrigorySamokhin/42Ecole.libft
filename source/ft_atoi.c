/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:19:27 by gmeizo            #+#    #+#             */
/*   Updated: 2019/04/16 18:23:01 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	long long int	result;
	long long int	sign;

	sign = 1;
	result = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (long long int)(*str - '0');
		str++;
	}
	return (sign * result);
}

int			ft_check_digit(const char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (ft_isdigit(str[i]))
			return (1);
	return (0);
}

void		ft_set_sign(long long int *sign, long long int *result)
{
	*sign = 1;
	*result = 0;
}

int			ft_atoi_parse(const char *str, int *arr, int i, int ret)
{
	long long int	result;
	long long int	sign;

	ft_set_sign(&sign, &result);
	while (!ft_isdigit(*str) && *str != '-')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (long long int)(*str - '0');
		str++;
	}
	if (sign == -1 && result == 0)
		return (ft_atoi_parse(str, arr, i, ret));
	else if (result < -2147483648 || result > 2147483647)
		return (-1);
	arr[i] = sign * result;
	if (*str != '\0' && ft_check_digit(str))
		return (ft_atoi_parse(str, arr, i + 1, ret));
	return (i - ret);
}

int			ft_atoi_pos(const char *str)
{
	long long int	result;

	result = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (long long int)(*str - '0');
		str++;
	}
	return (result);
}
