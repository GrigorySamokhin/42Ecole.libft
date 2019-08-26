/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:59:10 by gmeizo            #+#    #+#             */
/*   Updated: 2019/04/11 19:17:32 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_words(const char *str, char c)
{
	int word;
	int i;

	i = 0;
	word = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c)
			word++;
		i++;
	}
	if (str[0] != '\0')
		word++;
	return (word);
}

static char		*ft_word(const char *str, char c, int *i)
{
	char	*s;
	int		k;

	if (!(s = (char *)malloc(sizeof(s) * (ft_strlen(str)))))
		return (NULL);
	k = 0;
	while (str[*i] != c && str[*i])
	{
		s[k] = str[*i];
		k++;
		*i += 1;
	}
	s[k] = '\0';
	while (str[*i] == c && str[*i])
		*i += 1;
	return (s);
}

static void		ft_free(char **s, int n)
{
	int i;

	i = 0;
	while (i < n)
		free(s[i]);
	free(s);
}

char			**ft_strsplit(const char *str, char c)
{
	int		i;
	int		j;
	int		wrd;
	char	**s;

	i = 0;
	j = 0;
	wrd = ft_count_words(str, c);
	if (!str || (!(s = (char **)malloc(sizeof(s) *
		(ft_count_words(str, c) + 2)))))
		return (NULL);
	while (str[i] == c && str[i])
		i++;
	while (j < wrd && str[i])
	{
		s[j] = ft_word(str, c, &i);
		if (s[j] == NULL)
		{
			ft_free(s, j);
			return (NULL);
		}
		j++;
	}
	s[j] = NULL;
	return (s);
}

char 		*ft_strsplit_char(char *line, char ch)
{
	int 	i;
	char	*str;
	int		size;

	i = -1;
	size = 0;
	while (line[++i] != ch)
		size++;
	i = -1;
	str = (char *)malloc(sizeof(char) * (size + 1));
	while (line[++i] != ch)
		str[i] = line[i];
	str[i] = '\0';
	return (str);
}