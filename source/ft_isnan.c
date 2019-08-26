/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 13:49:29 by gmeizo            #+#    #+#             */
/*   Updated: 2019/06/05 13:49:30 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isnan(double numb)
{
	return (numb != numb);
}

int		ft_isinf(double numb)
{
	if (numb == (10.0 / 0.0))
		return (1);
	return (0);
}

int		ft_isneginf(double numb)
{
	if (numb == (-10.0 / 0.0))
		return (1);
	return (0);
}
