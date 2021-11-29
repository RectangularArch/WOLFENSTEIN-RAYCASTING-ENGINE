/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csilverb <csilverb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 16:57:22 by csilverb          #+#    #+#             */
/*   Updated: 2021/01/13 17:01:08 by csilverb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <strings.h>
# include <stdio.h>
# include <stdlib.h>

int					ft_isalnum(int ch);
int					ft_isascii(int ch);
int					ft_isprint(int ch);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
int					ft_tolower(int ch);
int					ft_toupper(int ch);
int					ft_isalpha(int ch);
int					ft_isdigit(int ch);
size_t				ft_strlen(const char *string);
char				*ft_strchr(const char *str, int ch);
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t num, size_t size);
void				*ft_memccpy(void *dst, const void *s, int ch, size_t count);
void				*ft_memchr(void *memptr, int val, size_t num);
int					ft_memcmp(const void *buf1, const void *buf2, size_t count);
void				*ft_memcpy(void *destptr, const void *srcptr, size_t num);
void				*ft_memmove(void *destn, const void *source, size_t count);
void				*ft_memset(void *buf, int ch, size_t count);
char				*ft_strdup(const char *str);
int					ft_strncmp(const char *s1, const char *s2, size_t num);
char				*ft_strnstr(const char *hstck, const char *need, size_t l);
char				*ft_strrchr(const char *str, int ch);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
#endif
