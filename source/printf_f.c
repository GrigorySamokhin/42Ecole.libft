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

long long int		dem_flo_set(long double nbr)
{
	long long int	in;
	int				x;

	x = (int)(nbr * 100) % 10;
	x = (x % 10 > 5) ? (x + 5) / 10 : x / 10;
	in = nbr;
	if (x > 5 && in % 2 == 0)
		in += 1;
	else if (x >= 5 && in % 2 != 0)
		in += 1;
	return (in);
}

char				*dem_fo(t_print *list, long double nbr)
{
	char	*str;

	if (!list->v && list->dot)
	{
		if (nbr < 0)
		{
			nbr *= -1;
			list->neg = 1;
		}
		str = ft_itoa_intmax_base(dem_flo_set(nbr), 10);
		if (list->neg)
		{
			str = ft_buf_strjoin("-", str, 1);
			list->s_len += 1;
		}
		return (str);
	}
	return (NULL);
}

char				*ft_itoa_float2(t_print *list, int *arr, char **fl_s)
{
	fl_s[0][arr[0] + 1] = '\0';
	fl_s[1][arr[1]] = '\0';
	fl_s[0][arr[0]] = '.';
	arr[3] = (!list->v) ? ft_strlen(fl_s[0]) + 6 + 1
			: ft_strlen(fl_s[0]) + list->v + 1;
	ft_helper_itoa(list, fl_s, arr);
	return (fl_s[0]);
}

char				*ft_itoa_float(long double nbr, t_print *list)
{
	char		*fl_s[2];
	int			value;
	int			width;
	int			*arr;

	if (!(arr = (int *)malloc(sizeof(int) + 4)))
		return (NULL);
	if ((fl_s[0] = dem_fo(list, nbr)) != NULL)
		return (fl_s[0]);
	width = ft_itoa_float_set(&nbr, fl_s, arr, list);
	if (nbr < 0)
	{
		nbr = nbr * -1;
		width -= 1;
	}
	if (!(fl_s[1] = (char *)malloc(sizeof(char) * (width + 1))))
		return (0);
	while (width-- >= 0)
	{
		value = nbr * 10;
		fl_s[1][arr[1]++] = value + 48;
		nbr = nbr * 10 - (double)value;
	}
	return (ft_itoa_float2(list, arr, fl_s));
}

t_print				*ft_f(const char *restrict format, \
							t_print *list, va_list ap)
{
	long double		numb;

	ft_set(format, list);
	numb = ft_set_f(list, ap);
	list->p_str = ft_itoa_float(numb, list);
	ft_pos_neg(list);
	list->x = 1;
	(list->minus) ? list->zero = 0 : 0;
	ft_check_nan(list, numb);
	ft_printout(list);
	list->s_len = ft_strlen(list->p_str);
	list->field = list->num1 - list->num0 + 1;
	list->size = list->size + list->s_len - 1;
	list->i = list->field + list->i - 1;
	ft_set_free(list);
	return (list);
}
