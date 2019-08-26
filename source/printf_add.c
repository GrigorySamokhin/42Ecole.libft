/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 13:49:29 by gmeizo            #+#    #+#             */
/*   Updated: 2019/06/05 13:49:30 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_isspec(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' ||
		c == 'i' || c == 'o' || c == 'u' || c == 'x' ||
		c == 'X' || c == 'f' || c == '%' || c == 'U' ||
		c == 'b' || c == 'C' || c == 'U')
		return (1);
	return (0);
}

void		ft_set_zero(t_print *list)
{
	list->zero = 0;
	list->i = -1;
	list->size = 0;
	list->f_str = NULL;
	list->p_str = NULL;
	list->s_len = 0;
	list->field = 0;
	list->minus = 0;
	list->space = 0;
	list->numb = 0;
	list->flag = 0;
	list->grid = 0;
	list->pos = 0;
	list->neg = 0;
	list->dot = 0;
	list->w = 0;
	list->v = 0;
	list->x = 0;
	list->ze = 0;
	list->p = 0;
	list->num0 = 0;
	list->num1 = 0;
	list->sign = 0;
}

void		ft_set_free(t_print *list)
{
	free(list->add);
	free(list->p_str);
	free(list->f_str);
	list->f_str = NULL;
	list->add = NULL;
	list->p_str = NULL;
	list->s_len = 0;
	list->field = 1;
	list->minus = 0;
	list->space = 0;
	list->numb = 0;
	list->flag = 0;
	list->grid = 0;
	list->pos = 0;
	list->neg = 0;
	list->dot = 0;
	list->w = 0;
	list->v = 0;
	list->x = 0;
	list->p = 0;
	list->ze = 0;
	list->num0 = 0;
	list->num1 = 0;
	list->sign = 0;
	list->zero = 0;
}
