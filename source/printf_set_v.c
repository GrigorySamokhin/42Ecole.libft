/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_set_v.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 13:49:29 by gmeizo            #+#    #+#             */
/*   Updated: 2019/06/05 13:49:30 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_zero_nspace(t_print *list)
{
	int i;

	i = -1;
	while (list->f_str[++i])
	{
		if (list->f_str[i] == '0')
		{
			if ((list->f_str[i] == '0' &&
				!ft_isdigit(list->f_str[i - 1]) && i > 0) || i == 0)
				list->zero = (list->dot) ? 0 : 1;
		}
		if (list->f_str[i] == ' ')
		{
			list->space = 1;
			(list->w < list->v) ? list->w += 1 : 0;
		}
	}
}

void				ft_width_check(const char *format, \
									t_print *list, va_list ap)
{
	int	i;

	i = 1;
	if (format[list->num0 + i] == '*')
	{
		list->w = (int)va_arg(ap, int);
		if (list->w < 0)
		{
			list->w = -list->w;
			list->minus = 1;
		}
		list->w = (ft_isdigit(format[list->num0 + i + 1])) ? 0 : list->w;
		list->x = 10;
		while (ft_isdigit(format[list->num0 + i + 1]))
			list->w = list->w * 10 + (format[list->num0 + i++ + 1] - '0');
	}
	ft_vi_check(format, list, ap);
}

void				ft_vi_check(const char *format, t_print *list, va_list ap)
{
	int		i;
	int		k;

	i = 1;
	k = list->num0 > 0 ? 1 : 2;
	if (ft_strncmp(&format[list->num1 - list->num0 - k], ".", 1) == 0)
	{
		if (format[list->num1 - list->num0 - k + 1] == '*')
		{
			list->v = (int)va_arg(ap, int);
			(list->v < 0) ? list->x = 11 : 0;
			(list->v < 0) ? list->v = list->w : 0;
			while (ft_isdigit(format[list->num1 - list->num0 + i + 1]))
				list->v = list->v * 10 + \
				(format[list->num1 - list->num0 + i++ + 1] - '0');
		}
	}
}

void				ft_dot_vi_w(t_print *list)
{
	int i;
	int vision_w;

	i = -1;
	vision_w = 0;
	if (list->dot == 1)
	{
		while (list->f_str[++i])
			if (list->f_str[i - 1] == '.' && i > 0)
				break ;
		while (ft_isdigit(list->f_str[i]))
			vision_w = (vision_w * 10) + list->f_str[i++] - '0';
		list->v = vision_w;
	}
	else
		list->v = 0;
	i = 0;
	while (list->f_str[i] && (!ft_isdigit(list->f_str[i])
		|| list->f_str[i] == '0') && list->f_str[i] != '.')
		i++;
	if (list->f_str[i] != '.')
		list->w = ft_atoi_pos(&list->f_str[i]);
}
