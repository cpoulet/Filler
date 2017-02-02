/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 09:52:40 by cpoulet           #+#    #+#             */
/*   Updated: 2017/01/26 19:10:58 by cpoulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include "ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# define BUFF_SIZE 1024

void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(const char *str);
void				ft_putstr_fd(const char *str, int fd);
void				ft_putendl(const char *str);
void				ft_putendl_fd(const char *str, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
int					ft_nblen(long long nb);
int					ft_u_nblen(unsigned long long nb);
int					ft_nblen_b(unsigned long long nb, int base);
size_t				ft_strlen(const char *s);
long int			ft_power(int n, unsigned int p);
unsigned long int	ft_u_power(int n, unsigned int p);
void				ft_swap(int *a, int *b);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *s1, const char *s2, size_t size);
char				*ft_strstr(const char *str, const char *to_find);
char				*ft_strnstr
					(const char *str, const char *to_find, size_t len);
char				*ft_strtoup(char *s1);
char				*ft_strtolow(char *s1);
char				*ft_strdup(const char *s1);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnew(size_t size);
char				**ft_tabnew(size_t height, size_t width);
int					*ft_rangenew(size_t size);
int					**ft_tab_i_new(size_t height, size_t width);
char				*ft_strredim(char *s, size_t size);
void				ft_strdel(char **as);
void				ft_tabdel(char ***at);
void				ft_strslr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strsub(const char *s, unsigned int start, size_t len);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(const char *s);
int					ft_nbword(const char *s, char c);
char				*ft_first_word(const char *s, char c);
char				**ft_strsplit(const char *s, char c);
int					ft_atoi(const char *str);
int					ft_approx(double nb);
int					ft_atoi_skip(char **str);
int					ft_get_hexa(const char *str);
int					ft_get_nb_b(const char *str, int base);
char				*ft_itoa(int n);
char				*ft_itoa_base(long long n, int base);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isalpha(int c);
int					ft_isblank(int c);
int					ft_isdigit(int c);
int					ft_ishexa(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_is_char(const char *s, char c);
void				ft_bzero(void *s, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
wchar_t				*ft_wcharnew(size_t size);
wchar_t				*ft_wcharnew_c(size_t size, char c);
size_t				ft_wstrlen(const wchar_t *s);
int					ft_max(int n, ...);
int					ft_min(int n, ...);

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(const void *content, size_t content_size);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstaddend(t_list **alst, t_list *new);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_tab_to_lst(char **tab, t_list **alst);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

typedef struct		s_gnl
{
	int				fd;
	char			*buffer;
	char			*excess;
	struct s_gnl	*start;
	struct s_gnl	*next;
}					t_gnl;

int					get_next_line(const int fd, char **line);

#endif
