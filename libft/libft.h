/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 09:56:32 by heinfalt          #+#    #+#             */
/*   Updated: 2017/03/22 13:08:40 by heinfalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <wchar.h>

# define ABS(value) (value < 0) ? -value : value
# define NEG(value) (value < 0) ? 1 : 0

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef	struct		s_itoa
{
	unsigned int	nbr;
	unsigned int	mod;
	int				i;
	int				negativ;
}					t_itoa;

typedef struct		s_wordi
{
	int				i;
	int				word;
	int				lenw;
}					t_wordi;

typedef	struct		s_dblbbl
{
	size_t			i;
	size_t			j;
}					t_dblbbl;

int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_ret_putchar(int c);
int					ft_is_wchar(wint_t c);
int					ft_putwchar(wchar_t c);
int					ft_putwstr(wint_t *str);
int					ft_atoi(const char *str);
int					ft_putxchar(char c, int x);
int					ft_is_wstring(wchar_t *str);
int					ft_is_white_space(char const c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strequ(char const *s1, char const *s2);
int					ft_initmod(unsigned int nbr, unsigned int mod);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
unsigned int		ft_hex_to_dec(const char *str, const char conv);
unsigned int		ft_bin_to_dec(const char *str);
char				*ft_itoa(int n);
char				*ft_ulitoa(unsigned long long nbr);
char				*ft_strrev(char *str);
char				*ft_strnew(size_t size);
char				*ft_ptr_to_hex(void *ptr);
char				*ft_strtrim(const char *s);
char				*ft_strdup(const char *str);
char				*ft_strndup(const char *str, int n);
char				*ft_litoa(long long nbr);
char				*ft_dbltoa(double nbr, int pre);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				**ft_strsplit(char const *s, char c);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_dec_to_base(unsigned int nbr, char *flag, int b, int p);
char				*ft_dec_to_hex(unsigned int nbr, char type, int pre);
char				*ft_dec_to_bin(unsigned int nbr);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strncpy(char *dest, char *src, size_t n);
char				*ft_strstr(const char *big, const char *lil);
char				*ft_dec_to_sci(double nbr, char type, int pre);
char				*ft_strjoin_free(char *s1, char *s2, char flag);
char				*ft_chrjoin_free(char *s, const char c, int flag);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_ldec_to_base(unsigned long long nbr, char *flag,\
					long long base, int pre);
char				*ft_ldec_to_hex(unsigned long long nbr, char type, int pre);
char				*ft_ldec_to_bin(unsigned long long nbr);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strnstr(const char *big, const char *lil, size_t len);
double				ft_pow(int nbr, int power);
unsigned long long	ft_initlmod(unsigned long long nbr, unsigned long long mod);
void				ft_putnbr(int n);
void				ft_strclr(char *s);
void				ft_putchar(char c);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
void				ft_putlstr(int *s);
wchar_t				*ft_strwdup(const wchar_t *str);
void				ft_swap(int *a, int *b);
void				ft_putendl(char const *s);
void				ft_putstr(char const *s);
void				*ft_memalloc(size_t size);
void				ft_putlnbr(long long int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_bzero(void *s, size_t n);
void				ft_putchar_fd(char c, int fd);
void				ft_charswap(char *chr1, char *chr2);
void				ft_putstr_fd(char const *s, int fd);
void				*ft_memset(void *s, int c, size_t n);
void				ft_putendl_fd(char const *s, int fd);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_striter(char *s, void (*f)(char *));
void				ft_putnstr(const char *str, int n);
void				ft_lstappend(t_list **alst, t_list *new);
void				*ft_memchr(const void *s, int c, size_t n);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
size_t				ft_strlen(const char *str);
size_t				ft_wcharlen(wint_t c);
size_t				ft_wstrlen(wint_t *str);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);

#endif
