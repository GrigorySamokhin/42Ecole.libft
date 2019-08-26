/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmeizo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 14:54:51 by gmeizo            #+#    #+#             */
/*   Updated: 2019/04/16 13:02:23 by gmeizo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdint.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <math.h>
# include <limits.h>
# include <fcntl.h>

# define ENDL		'\0'
# define PER		'%'
# define BUFF_SIZE_GNL 3
# define TRUE 1
# define FALSE 0

typedef struct		s_list
{
    void			*content;
    size_t			content_size;
    struct s_list	*next;
}					t_list;

typedef struct			s_printf_list
{
	char				*p_str;
	char				*f_str;
	int					s_len;
	int					field;
	int					minus;
	int					space;
	intmax_t			numb;
	int					flag;
	int					grid;
	int					zero;
	int					pos;
	int					neg;
	int					dot;
	int					w;
	int					v;
	int					x;
	int					i;
	int					num0;
	int					num1;
	int					size;
	char				sign;
	char				*add;
	int					p;
	int					ze;
}						t_print;


char 					*ft_strsplit_char(char *line, char ch);
long double				ft_set_f(t_print *list, va_list ap);
void					ft_zero_nspace(t_print *list);
void					ft_check_nan(t_print *list, double numb);
void					ft_helper_itoa(t_print *list, char **dem_flo, int *arr);
int						re(t_print *list, int size);
void					ft_set_free(t_print *list);
void					ft_str_flags(t_print *list, \
							const char *restrict format);
void					ft_width_check(const char *format, \
							t_print *list, va_list ap);
void					ft_vi_check(const char *format, \
							t_print *list, va_list ap);
void					ft_dot_vi_w(t_print *list);
void					ft_set(const char *restrict format, t_print *list);
t_print					*ft_b(const char *restrict format, \
							t_print *list, va_list ap);
t_print					*ft_x(const char *restrict format, \
							t_print *list, va_list ap, int pos);
t_print					*ft_ch(const char *restrict format, \
							t_print *list, va_list ap);
t_print					*ft_per(const char *restrict format, \
							t_print *list);
t_print					*ft_s(const char *restrict format, \
							t_print *list, va_list ap);
t_print					*ret(t_print *list);
t_print					*ft_di(const char *restrict format, \
							t_print *list, va_list ap);
t_print					*ft_disp(const char *restrict format, \
							t_print *list, va_list ap);
void					ft_set_zero(t_print *list);
void					get_str(t_print *list);
intmax_t				ft_set_number_x(va_list ap, t_print *list);
t_print					*ft_o(const char *restrict format, \
							t_print *list, va_list ap);
t_print					*ft_u(const char *restrict format, \
								t_print *list, va_list ap, int r);
int						ft_printf(const char *restrict format, ...);
void					ft_pvalue(t_print *list);
void					ft_pos_neg(t_print	*list);
void					ft_printout(t_print *list);
void					ft_pvalue(t_print *list);
int						ft_isspec(char c);
char					*ft_c(char c, t_print *list);
char					*ft_cv(char c, t_print *list);
int						ft_itoa_float_set(long double *nbr, char **dem_flo, \
							int *dot_index, t_print *list);
int						ft_zero_set(char **dem_flo, int i, int *y);
char					*ft_itoa_float(long double nbr, t_print *list);
t_print					*ft_f(const char *restrict format, t_print *list, \
							va_list ap);
int					ft_isallchar(char *str);
char				*ft_strndup(const char *s1, size_t n);
int					get_next_line(const int fd, char **line);
int					ft_atoi_parse(const char *str, int *arr, int i, int ret);
void				ft_sestrcpy(char *str, const char *restrict s, \
						int start, int end);
char				*ft_buf_strjoin(char *str, char *str1, int ret);
int					ft_isneginf(double numb);
int					ft_isinf(double numb);
int					ft_isnan(double numb);
int					ft_atoi_pos(const char *str);
char				*ft_itoa(int nbr);
int					ft_sqrt(int nb);
int					ft_recursive_factorial(int nb);
int					ft_is_prime(int nb);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_count_word(char *str, char c);
void				ft_tzero(int *j, int *i);
int					ft_count_letters(char *str, char c);
int					ft_count_num(int n);
void				ft_bzero(void *s, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
size_t				ft_strlen(const char *s);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack,
						const char *needle, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_count_chr(const char *temp, char c);
int					ft_numbsize_long_long(long long num, int base);
int					ft_numbsize_uintmax(uintmax_t num, int base);
int					ft_numbsize_long(long num, int base);
int					ft_numbsize_int(int num, int base);
int					ft_numbsize_intmax(intmax_t num, int base);
char				*ft_itoa_uintmax_base(uintmax_t num, int base);
char				*ft_itoa_intmax_base(intmax_t num, int base);
char				*ft_strnjoin(char const *s1, char const *s2, int n);

#endif
