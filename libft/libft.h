/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvincent <rvincent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:23:39 by rvincent          #+#    #+#             */
/*   Updated: 2022/09/14 21:31:28 by rvincent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdarg.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *s, int c, size_t n);
long				ft_atoi(const char *str);
void				ft_bzero(void *ptr, size_t n);
void				*ft_calloc(size_t elementCount, size_t elementSize);
int					ft_isalnum(char c);
int					ft_isalpha(char c);
int					ft_isascii(int c);
int					ft_isdigit(char c);
int					ft_isprint(int c);
int					ft_isprint(int c);
int					ft_isspace(char c);
char				*ft_itoa(int n);
void				*ft_memchr(const void *memoryBlock, int c, size_t size);
int					ft_memcmp(const void *pointer1, const void *pointer2,
						size_t size);
void				*ft_memcpy(void *destination, const void *source,
						size_t size);
void				*ft_memmove(void *destination, const void *source,
						size_t size);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
char				**ft_split(char const *s, char c);
char				*ft_strchr(const char *str, int c);
char				*ft_strdup(const char *source);
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strmatch(char *str1, char *str2);
int					ft_strncmp(const char *s1, const char *s2, size_t length);
char				*ft_strnstr(const char *str1, const char *str2, size_t len);
char				*ft_strrchr(const char *str, int c);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_tolower(int character);
int					ft_toupper(int character);

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

int					ft_printf(const char *str, ...);
int					ft_putchar(char c);
int					ft_putnbr_hexa(long nbr, int upper);
int					ft_putnbr(int nb);
int					ft_putstr(char *s);
int					ft_putnbr_u(unsigned int nb);
int					ft_putnbr_adress(unsigned long nbr);

char				*get_next_line(int fd);

#endif