#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>

int ft_isalpha(int a);
void ft_bzero(void *a, size_t b);
int	ft_isalnum(int a);
int	ft_isascii(int a);
int	ft_isdigit(int a);
int	ft_isprint(int a);
void* ft_memcpy(void* dest, const void* src, size_t a);
void* ft_memmove(void *b, const void *a, size_t n);
void* ft_memset(void *b, int c, size_t d);
char *ft_strchr(const char *s, int c);
size_t ft_strlcat(char* b, const char* a, size_t sizeb);
size_t ft_strlcpy(char *b, const char *a, size_t len);
size_t	ft_strlen(const char *str);
int ft_tolower(int a);
int ft_toupper(int a);
int ft_strncmp(const char *a, const char *b, size_t n);
char* ft_strrchr (const char *b, int a);
void* ft_memchr(const void *s, int c, size_t n);
int ft_memcmp(const void* s1, const void* s2, size_t n);
char* ft_strnstr(const char* hay, const char* needle, size_t n);
int ft_atoi(const char *str);
void* ft_calloc(size_t nmemb, size_t size);
char* ft_strdup(const char *s);
char *ft_substr(char const *s, unsigned int start, size_t len);
char *ft_strjoin(char const *s1, char const *s2);

#endif
