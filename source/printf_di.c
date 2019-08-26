/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_di.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 13:49:29 by gmeizo            #+#    #+#             */
/*   Updated: 2019/06/05 13:49:30 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_pvalue(t_print *list)
{
	(list->pos) ? (list->p_str = ft_buf_strjoin("+", list->p_str, 1)) : 0;
	(list->neg) ? (list->p_str = ft_buf_strjoin("-", list->p_str, 1)) : 0;
	if (list->grid && list->numb > 0 && list->x == 1)
	{
		list->p_str = ft_buf_strjoin("0x", list->p_str, 1);
		list->grid = 0;
	}
	if (list->sign == 'p')
	{
		list->p_str = ft_buf_strjoin("0x", list->p_str, 1);
		list->grid = 0;
	}
	if (list->grid && list->numb > 0 && list->x == 2)
	{
		list->p_str = ft_buf_strjoin("0X", list->p_str, 1);
		list->grid = 0;
	}
	if (list->grid && list->numb > 0 && list->x == 3)
	{
		list->p_str = ft_buf_strjoin("0", list->p_str, 1);
		list->s_len += 1;
		list->grid = 0;
	}
}

void				ft_printout(t_print *list)
{
	char		*ad;

	(list->p_str[0] == 0) ? list->s_len = 0 : 0;
	if (list->v > list->s_len)
	{
		ad = ft_cv('0', list);
		list->p_str = ft_buf_strjoin(ad, list->p_str, 2);
	}
	!list->zero ? ft_pvalue(list) : 0;
	list->neg ? list->space = 0 : 0;
	list->w = list->w - list->neg - list->pos - list->space;
	list->w = (list->s_len) ? list->w - list->s_len : list->w - list->v;
	list->w < 0 ? list->w = 0 : 0;
	list->add = (list->zero) ? ft_c('0', list) : ft_c(' ', list);
	list->p_str = (list->minus == 1) ? ft_buf_strjoin(list->p_str,
			list->add, 0) : ft_buf_strjoin(list->add, list->p_str, 1);
	if (list->space && !(list->neg) && !(list->pos))
		list->p_str = ft_buf_strjoin(" ", list->p_str, 1);
	(list->zero || list->grid) ? ft_pvalue(list) : 0;
	ft_putstr(list->p_str);
}

intmax_t			ft_set_number(va_list ap, t_print *list)
{
	intmax_t	num;

	(list->flag == 1) ? num = va_arg(ap, long int) : 0;
	(list->flag == 2) ? num = va_arg(ap, long long int) : 0;
	(list->flag == 3) ? num = (short)va_arg(ap, int) : 0;
	(list->flag == 5) ? num = (size_t)va_arg(ap, size_t) : 0;
	(list->flag == 6) ? num = va_arg(ap, uintmax_t) : 0;
	if (list->flag == 4)
	{
		num = (unsigned char)va_arg(ap, int);
		if (num >= 128)
			num = (num > 128) ? num - 256 : num * -1;
	}
	(!list->flag) ? num = (int)va_arg(ap, int) : 0;
	return (num);
}

t_print				*ft_di(const char *restrict format, \
								t_print *list, va_list ap)
{
	ft_set(format, list);
	if (list->ze)
		ft_width_check(format, list, ap);
	list->p_str = ft_itoa_intmax_base(ft_set_number(ap, list), 10);
	ft_pos_neg(list);
	if (list->p_str[0] == '0' && !list->v && list->dot)
	{
		ft_strdel(&list->p_str);
		list->p_str = ft_strdup("");
	}
	(list->v > list->w) ? list->w = list->v : 0;
	ft_printout(list);
	return (ret(list));
}
