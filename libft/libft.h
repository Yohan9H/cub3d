/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apernot <apernot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:23:30 by yohan.h           #+#    #+#             */
/*   Updated: 2024/10/15 15:16:55 by apernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "../include/cub3d.h"

int		ft_atoi(const char *str);

void	ft_bzero(void *s, size_t n);

void	*ft_calloc(size_t nmemb, size_t size);

int		ft_isalnum(int c);

int		ft_isalpha(int c);

int		ft_isascii(int c);

int		ft_isdigit(int c);

int		ft_isprint(int c);

char	*ft_itoa(int nb);

void	*ft_memchr(const void *s, int c, size_t n);

int		ft_memcmp(const void *s1, const void *s2, size_t n);

void	*ft_memcpy(void *dest, const void *src, size_t size);

void	*ft_memmove(void *dest, const void *src, size_t len);

void	*ft_memset(void *b, int c, size_t len);

void	ft_putendl_fd(char *s, int fd);

void	ft_putnbr_fd(int n, int fd);

void	ft_putstr_fd(char *s, int fd);

char	**ft_split(char const *s, char c);

char	*ft_strchr(const char *s, int c);

char	*ft_strdup(const char *s1);

void	ft_striteri(char *s, void (*f)(unsigned int, char*));

char	*ft_strjoin(const char *s1, const char *s2);

size_t	ft_strlcat(char *dst, const char *src, size_t destsize);

size_t	ft_strlcpy(char *dst, const char *src, size_t dstlen);

size_t	ft_strlen(const char *s);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int		ft_strncmp(const char *s1, const char *s2, size_t n);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

char	*ft_strrchr(const char *s, int c);

char	*ft_strtrim(char const *s1, char const *set);

char	*ft_substr(char const *s, unsigned int start, size_t len);

int		ft_tolower(int c);

int		ft_toupper(int c);

void	ft_putchar_fd(char c, int fd);

int		verif_nil(unsigned long nb, char *base, unsigned long size_b);

int		ft_fprintf(const char *format, ...);

char	*get_next_line(int fd);

int		ft_isspace(char c);

char	*ft_strdup_esc(const char *s1);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

t_map	*ft_lstnew(char *str);

void	ft_lstadd_front(t_map **lst, t_map *new);

int		ft_lstsize(t_map *lst);

t_map	*ft_lstlast(t_map *lst);

void	ft_lstadd_back(t_map **lst, t_map *new);

void	ft_lstdelone(t_map *lst);

void	ft_lstclear(t_map **lst);

void	ft_lstiter(t_map *lst);

t_map	*ft_lstmap(t_map *lst);

#endif