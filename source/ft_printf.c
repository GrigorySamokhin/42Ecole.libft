/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 13:49:29 by gmeizo            #+#    #+#             */
/*   Updated: 2019/06/05 13:49:30 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_print		*ret(t_print *list)
{
	list->field = list->num1 - list->num0;
	list->s_len = ft_strlen(list->p_str);
	list->i = list->i + list->field;
	list->size = list->size + list->s_len - 1;
	ft_set_free(list);
	return (list);
}

int			re(t_print *list, int size)
{
	free(list);
	return (size);
}

int			ft_printf(const char *restrict format, ...)
{
	t_print			*list;
	va_list			ap;

	if (!(list = (t_print *)malloc(sizeof(t_print))))
		return (0);
	ft_set_zero(list);
	va_start(ap, format);
	while (format[++list->i])
	{
		if (format[list->i] == PER)
		{
			if (!ft_disp(format, list, ap))
				return (re(list, 0));
		}
		else
		{
			if (format[list->i] == '\0')
				return (re(list, list->size));
			write(1, &format[list->i], 1);
		}
		list->size++;
	}
	va_end(ap);
	return (re(list, list->size));
}

t_print		*ft_disp2(const char *restrict format, t_print *list, va_list ap)
{
	if (format[list->num1] == 'c')
		return (ft_ch(format, list, ap));
	if (format[list->num1] == '%')
		return (ft_per(format, list));
	if (format[list->num1] == 'u')
		return (ft_u(format, list, ap, 1));
	if (format[list->num1] == 'U')
		return (ft_u(format, list, ap, 2));
	if (format[list->num1] == 'o')
		return (ft_o(format, list, ap));
	if (format[list->num1] == 'b')
		return (ft_b(format, list, ap));
	if (format[list->num1] == 'f')
		return (ft_f(format, list, ap));
	return (NULL);
}

t_print		*ft_disp(const char *restrict format, t_print *list, va_list ap)
{
	list->num0 = list->i;
	list->num1 = list->i;
	while (format[list->num1++] && !ft_isspec(format[list->num1]) \
			&& format[list->num1])
		list->p++;
	if (format[list->num1] == 'd' || format[list->num1] == 'i')
		return (ft_di(format, list, ap));
	if (format[list->num1] == 's' || format[list->num1] == 'S')
		return (ft_s(format, list, ap));
	if (format[list->num1] == 'x')
		return (ft_x(format, list, ap, 1));
	if (format[list->num1] == 'p')
		return (ft_x(format, list, ap, 3));
	if (format[list->num1] == 'X')
		return (ft_x(format, list, ap, 2));
	return (ft_disp2(format, list, ap));
}
