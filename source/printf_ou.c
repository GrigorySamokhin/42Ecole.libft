/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_ou.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 13:49:29 by gmeizo            #+#    #+#             */
/*   Updated: 2019/06/05 13:49:30 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_print		*ft_u(const char *restrict format, \
					t_print *list, va_list ap, int r)
{
	ft_set(format, list);
	r == 2 ? list->flag = 6 : 0;
	list->numb = ft_set_number_x(ap, list);
	list->p_str = ft_itoa_uintmax_base(list->numb, 10);
	(list->numb == 0 && !list->v && list->dot) \
		? list->p_str = ft_strdup("") : 0;
	ft_pos_neg(list);
	list->space = 0;
	list->pos = 0;
	ft_printout(list);
	return (ret(list));
}

t_print		*ft_o(const char *restrict format, t_print *list, va_list ap)
{
	ft_set(format, list);
	list->numb = ft_set_number_x(ap, list);
	list->p_str = ft_itoa_uintmax_base(list->numb, 8);
	(list->p_str[0] == '0' && !list->grid && !list->v && list->dot) \
		? list->p_str = ft_strdup("") : 0;
	(list->p_str[0] == 0) ? list->s_len = 0 : 0;
	ft_pos_neg(list);
	list->x = 3;
	(list->minus) ? list->zero = 0 : 0;
	(list->grid && list->numb > 0 && list->x == 3) ? list->v -= 1 : 0;
	(list->zero) ? list->grid = 0 : 0;
	ft_printout(list);
	list->field = list->num1 - list->num0;
	list->i += list->field;
	list->s_len = ft_strlen(list->p_str);
	list->size = list->size + list->s_len - 1;
	ft_set_free(list);
	return (list);
}

t_print		*ft_b(const char *restrict format, t_print *list, va_list ap)
{
	ft_set(format, list);
	list->numb = ft_set_number_x(ap, list);
	list->p_str = ft_itoa_uintmax_base(list->numb, 2);
	(list->p_str[0] == '0' && !list->grid && !list->v && list->dot) \
		? list->p_str = ft_strdup("") : 0;
	(list->p_str[0] == 0) ? list->s_len = 0 : 0;
	ft_pos_neg(list);
	list->x = 3;
	(list->minus) ? list->zero = 0 : 0;
	(list->grid && list->numb > 0 && list->x == 3) ? list->v -= 1 : 0;
	ft_printout(list);
	list->field = list->num1 - list->num1;
	list->s_len = ft_strlen(list->p_str);
	list->i += list->field;
	ft_set_zero(list);
	return (list);
}
