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

int					ft_itoa_float_set(long double *nbr, char **fl_s, \
										int *arr, t_print *list)
{
	long long int	int_number;
	int				w;

	int_number = *nbr;
	arr[1] = 0;
	(nbr < 0) ? *nbr = *nbr * -1 : 0;
	fl_s[0] = ft_itoa_intmax_base(int_number, 10);
	arr[0] = ft_strlen(fl_s[0]);
	w = (arr[0] + 1 + list->v);
	if (!list->v)
	{
		w = (arr[0] + 1 + 6);
		list->v = 6;
	}
	*nbr -= int_number;
	(*nbr < 0 && (fl_s[0][0] = '-')) ? arr[2]++ : 0;
	return (w);
}

long double			ft_set_f(t_print *list, va_list ap)
{
	long double		nbr;

	if (ft_strchr(list->f_str, 'L'))
		nbr = (long double)va_arg(ap, long double);
	else
		nbr = (double)va_arg(ap, double);
	return (nbr);
}

int					ft_zero_set(char **fl_s, int i, int *y)
{
	if (fl_s[0][i - 1] == '9' && !((fl_s[0][i] - 48) < 5))
		while (i && fl_s[0][i - 1] == '9')
		{
			*y = 1;
			if (fl_s[0][i - 2] == '.')
				break ;
			fl_s[0][--i] = '0';
		}
	return (i);
}

void				ft_check_nan(t_print *list, double numb)
{
	if (ft_isinf(numb))
	{
		list->p_str = ft_strdup("inf");
		list->v = 0;
		list->neg = 0;
	}
	if (ft_isneginf(numb))
	{
		list->p_str = ft_strdup("-inf");
		list->v = 0;
		list->neg = 0;
	}
	if (ft_isnan(numb))
	{
		list->p_str = ft_strdup("nan");
		list->v = 0;
		list->neg = 0;
	}
}

void				ft_helper_itoa(t_print *list, char **fl_s, int *arr)
{
	int		i;
	int		y;

	y = 0;
	fl_s[0] = (list->v < 6) ? ft_strnjoin(fl_s[0],
		fl_s[1], list->v + 1) : ft_strjoin(fl_s[0], fl_s[1]);
	i = arr[0] + list->v + 1;
	i = ft_zero_set(fl_s, i, &y);
	if (((fl_s[0][i] - 48) >= 5 || y))
		if (fl_s[0][i - 1] == '9' && fl_s[0][i - 2] != '.')
		{
			fl_s[0][i - arr[0]] += 1;
			fl_s[0][i - 1] = '0';
		}
		else if (fl_s[0][i - 2] == '.' && fl_s[0][i - 1] == '9')
		{
			fl_s[0][i - 3] += 1;
			fl_s[0][i - 1] = '0';
		}
		else
			fl_s[0][i - 1] += 1;
	else if ((fl_s[0][i] - 48) >= 5 || y)
		fl_s[0][i - 1] += 1;
	fl_s[0][arr[3] - 1] = '\0';
}
