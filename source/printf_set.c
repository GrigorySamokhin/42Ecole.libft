/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 13:49:29 by gmeizo            #+#    #+#             */
/*   Updated: 2019/06/05 13:49:30 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_str_flags(t_print *list, const char *restrict format)
{
	int		i;

	i = -1;
	if (!(list->f_str = (char *)malloc(sizeof(char) \
			* (list->num1 - list->num0))))
		return ;
	ft_sestrcpy(list->f_str, format, list->num0, list->num1);
	while (list->f_str[++i])
	{
		if (list->f_str[i] == 'l')
			list->flag = (list->f_str[i++ + 1] != 'l') ? 1 : 2;
		if (list->f_str[i] == 'h')
			list->flag = (list->f_str[i++ + 1] == 'h') ? 4 : 3;
		(list->f_str[i] == '#') ? list->grid = 2 : 0;
		(list->f_str[i] == 'z') ? list->flag = 5 : 0;
		(list->f_str[i] == 'j') ? list->flag = 6 : 0;
		(list->f_str[i] == '-') ? list->minus = 1 : 0;
		(list->f_str[i] == '.') ? list->dot = 1 : 0;
		(list->f_str[i] == '*') ? list->ze = 1 : 0;
		(list->f_str[i] == '+') ? list->pos = 1 : 0;
	}
}

void			ft_pos_neg(t_print *list)
{
	if (list->p_str[0] == '-')
	{
		list->neg = 1;
		list->pos = 0;
		list->p_str = ft_strdup(&list->p_str[1]);
	}
	list->s_len = ft_strlen(list->p_str);
}

void			ft_set(const char *restrict format, t_print *list)
{
	ft_str_flags(list, format);
	ft_dot_vi_w(list);
	ft_zero_nspace(list);
	list->sign = format[list->num1];
	(list->w < list->s_len) ? list->w = list->s_len : 0;
	list->minus ? list->zero = 0 : 0;
}
