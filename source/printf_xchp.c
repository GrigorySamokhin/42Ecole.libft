/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 13:49:29 by gmeizo            #+#    #+#             */
/*   Updated: 2019/06/05 13:49:30 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t	ft_set_number_x(va_list ap, t_print *list)
{
	intmax_t	num;

	(list->flag == 1 || list->sign == 'p') ?
			num = va_arg(ap, unsigned long) : 0;
	(list->flag == 1 || list->sign == 'p') ? list->flag = 1 : 0;
	(list->flag == 2) ? num = va_arg(ap, unsigned long long) : 0;
	(list->flag == 3) ? num = (unsigned short)va_arg(ap, int) : 0;
	(list->flag == 4) ? num = (unsigned char)va_arg(ap, int) : 0;
	(list->flag == 6) ? num = (size_t)va_arg(ap, uintmax_t) : 0;
	((!list->flag) && list->sign != 'b') ?
			num = (unsigned int)va_arg(ap, unsigned int) : 0;
	list->sign == 'b' ? num = va_arg(ap, int) : 0;
	return (num);
}

t_print		*ft_x(const char *restrict format, \
					t_print *list, va_list ap, int pos)
{
	int i;

	i = -1;
	ft_set(format, list);
	if (list->ze)
		ft_width_check(format, list, ap);
	list->numb = ft_set_number_x(ap, list);
	list->p_str = ft_itoa_uintmax_base(list->numb, 16);
	ft_pos_neg(list);
	list->x = (pos == 1 || pos == 3) ? 1 : 2;
	if (list->x == 2)
		while (list->p_str[++i])
			if (!ft_isdigit(list->p_str[i]))
				list->p_str[i] = ft_toupper(list->p_str[i]);
	(list->minus) ? list->zero = 0 : 0;
	(list->p_str[0] == '0' && !list->v && list->dot)
	? list->p_str = ft_strdup("") : 0;
	(list->grid && !(list->p_str[0] == '0')
		&& !(list->p_str[0] == '\0')) ? list->w -= 2 : 0;
	(pos == 3) ? list->w -= 2 : 0;
	list->pos = 0;
	ft_printout(list);
	return (ret(list));
}

void		ft_ch_zero(t_print *list)
{
	(list->dot && list->v > list->s_len) ? list->v = 0 : 0;
	if (list->p_str[0] == '\0')
	{
		list->s_len = 1;
		list->w -= 1;
		list->v = 0;
		if (list->x == 10)
		{
			write(1, "\0", 1);
			list->s_len += 1;
		}
	}
}

t_print		*ft_ch(const char *restrict format, t_print *list, va_list ap)
{
	char *str;

	list->p_str = ft_strnew(2);
	ft_set(format, list);
	if (list->ze)
		ft_width_check(format, list, ap);
	list->p_str[0] = (char)va_arg(ap, int);
	str = list->p_str;
	list->space = 0;
	ft_pos_neg(list);
	ft_ch_zero(list);
	if (list->minus && str[0] == '\0')
	{
		write(1, "\0", 1);
		list->x = 2;
	}
	ft_printout(list);
	list->s_len = ft_strlen(list->p_str);
	(list->x != 10 && list->x != 2 && str[0] == '\0') ? write(1, "\0", 1) : 0;
	(str[0] == '\0' || list->x == 10) ? list->s_len += 1 : 0;
	list->field = list->num1 - list->num0;
	list->i = list->field + list->i;
	list->size = list->size + list->s_len - 1;
	ft_set_free(list);
	return (list);
}

t_print		*ft_per(const char *restrict format, t_print *list)
{
	list->p_str = ft_strnew(2);
	list->p_str[0] = '%';
	ft_set(format, list);
	if (ft_count_chr(format, '%') == 1)
		return (list);
	ft_pos_neg(list);
	list->pos = 0;
	list->space = 0;
	list->dot = 0;
	list->v = 0;
	ft_printout(list);
	return (ret(list));
}
