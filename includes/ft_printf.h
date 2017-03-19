/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 02:56:18 by mchemakh          #+#    #+#             */
/*   Updated: 2017/03/19 22:47:06 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define BUFF_SIZE 1

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct		s_flags
{
	int			bytes;
	int			size;
	int			percent;
	char		*format;
	int			index;
	int			ret;
	char		option;
	char		dbloption;
	char		conv;
	char		noconv;
	char		*args;
	int			space;
	int			sign;
	char		zero;
	char		hash;
	char		precision;
	int			left;
	wchar_t		*wargs;
	char		*digit;
	int			dig1;
	int			dig2;
}					t_flags;

typedef struct		s_list
{
	struct s_list	*next;
	void			*content;
	size_t			content_size;
}					t_list;


/*----------------------------------------------------
**********************BEGIN OF***********************|
********************REMASTERIZED*********************|
**----------------------------------------------------
*/

void				ft_decompose_digit(t_flags *list);// ft_dec_digit.c
void				ft_cut_lststr(t_flags *list, int start);// ft_cut_str.c
int					ft_verif_noconv(t_flags *list, int idxtmp);
void				ft_clear_flags(t_flags *list);// ft_clear_flags.c
int					ft_isflag(char c);// ft_isflag.c
int					ft_noflags(char c);// ft_noflags.c
int					ft_check_flags(t_flags *list);// ft_check_flags.c
void				ft_return_size(t_flags *list);// ft_return_size.c
void				ft_return_wsize(t_flags *list);// ft_return_wsize.c

void				ft_wldigitflag(t_flags *list);// ft_wldigitflag.c
void				ft_wdigitflag(t_flags *list);// ft_wdigitflag.c
void				ft_spaceflag(t_flags *list);// ft_sapceflag.c
void				ft_digitflag(t_flags *list);// ft_digitflag.c
void				ft_lspaceflag(t_flags *list);// ft_lspaceflag.c
void				ft_ldigitflag(t_flags *list);// ft_ldigitflag.c
void				ft_wzeroflag(t_flags *list);// ft_wzeroflag.c
void				ft_zhashflag(t_flags *list);// ft_zeroflag.c
void				ft_zeroflag(t_flags *list);// ft_zeroflag.c
void				ft_hashflag(t_flags *list);// ft_hashflag.c
void				ft_signflag(t_flags *list);// ft_signflag.c

void				ft_process_sizet(t_flags *list, va_list args, char conv);// ft_process_sizet.c
void				ft_process_intmax(t_flags *list, va_list args, char conv);// ft_process_intmax.c
void				ft_process_short(t_flags *list, va_list args, char conv);// ft_process_short.c
void				ft_process_long(t_flags *list, va_list args, char conv);// ft_process_long.c
void				ft_process_sshort(t_flags *list, va_list args, char conv);// ft_process_sshort.c
void				ft_process_llong(t_flags *list, va_list args, char conv);// ft_process_llong.c
void				ft_process_flags(t_flags *list);// ft_process_flags.c
void				ft_process_option(t_flags *list, va_list args, char conv);// ft_process_option.c
void				ft_process_percent(t_flags *list);// ft_process_percent.c

int					ft_print_wstr(t_flags *list);// ft_process_wstr.c
int					ft_print_wchr(t_flags *list, wchar_t c);// ft_process_wchr.c
int					ft_print_str(t_flags *list);// ft_process_str.c
int					ft_print_ptr(t_flags *list);// ft_process_ptr.c
int					ft_print_chr(t_flags *list, char c);// ft_process_chr.c
int					ft_print_oct(t_flags *list);// ft_process_oct.c
int					ft_print_uint(t_flags *list);// ft_process_uint.c
int					ft_print_hex(t_flags *list);// ft_process_hex.c
int					ft_print_int_up(t_flags *list); // ft_process_int_up.c
int					ft_print_int(t_flags *list);// ft_process_int.c

void				ft_process_wstr(t_flags *list);// ft_process_wstr.c
void				ft_process_wchr(t_flags *list);// ft_process_wchr.c
void				ft_process_str(t_flags *list);// ft_process_str.c
void				ft_process_ptr(t_flags *list);// ft_process_ptr.c
void				ft_process_chr(t_flags *list);// ft_process_chr.c
void				ft_process_oct(t_flags *list);// ft_process_oct.c
void				ft_process_uint(t_flags *list);// ft_process_uint.c
void				ft_process_hex(t_flags *list);// ft_process_hex.c
void				ft_process_int_up(t_flags *list);// ft_process_int_up.c
void				ft_process_int(t_flags *list);// ft_process_int.c

void				ft_save_wstr(t_flags *list, va_list args);// ft_verif_wstr.c
void				ft_save_wchr(t_flags *list, va_list args);// ft_verif_wchr.c
void				ft_save_str(t_flags *list, va_list args);// ft_verif_str.c
void				ft_save_ptr(t_flags *list, va_list args);//ft_verif_ptr.c
void				ft_save_chr(t_flags *list, va_list args);// ft_verif_chr.c
void				ft_save_oct_up(t_flags *list, va_list args);// ft_verif_oct.c
void				ft_save_oct_low(t_flags *list, va_list args);// ft_verif_oct.c
void				ft_save_uint_up(t_flags *list, va_list args);// ft_verif_uint.c
void				ft_save_uint_low(t_flags *list, va_list args);// ft_verif_uint.c
void				ft_save_hex_up(t_flags *list, va_list args);// ft_verif_hex.c
void				ft_save_hex_low(t_flags *list, va_list args);// ft_verif_hex.c
void				ft_save_int_up(t_flags *list, va_list args);// ft_verif_int_up.c
void				ft_save_int(t_flags *list, va_list args);// ft_verif_int.c

int					ft_verif_wstr(t_flags *list, int idxtmp);// ft_verif_wstr.c
int					ft_verif_wchr(t_flags *list, int idxtmp);// ft_verif_wchr.c
int					ft_verif_str(t_flags *list, int idxtmp);// ft_verif_str.c
int					ft_verif_ptr(t_flags *list, int idxtmp);// ft_verif_ptr.c
int					ft_verif_chr(t_flags *list, int idxtmp);// ft_verif_chr.c
int					ft_verif_oct_up(t_flags *list, int idxtmp);// ft_verif_oct.c
int					ft_verif_oct_low(t_flags *list, int idxtmp);// ft_verif_oct.c
int					ft_verif_uint_up(t_flags *list, int idxtmp);// ft_verif_uint.c
int					ft_verif_uint_low(t_flags *list, int idxtmp);// ft_verif_uint.c
int					ft_verif_hex_up(t_flags *list, int idxtmp);// ft_verif_hex.c
int					ft_verif_hex_low(t_flags *list, int idxtmp);// ft_verif_hex.c
int					ft_verif_int_up(t_flags *list, int idxtmp);// ft_verif_int_up.c;
int					ft_verif_int(t_flags *list, int idxtmp);// ft_verif_int.c

int					ft_verif_percent(t_flags *list, int idxtmp);// ft_verif_percent.c
void				ft_save_spcs(t_flags *list, int idxtmp);// ft_verif_spcs.c
void				ft_save_digit(t_flags *list, int idxtmp);// ft_verif_number.c
void				ft_save_sign(t_flags *list, int idxtmp);// ft_verif_numbersign.c

int					ft_isshort_allowed(t_flags *list, int idxtmp);// ft_verif_short.c
int					ft_isintmax_allowed(t_flags *list, int idxtmp);// ft_verif_sizet.c
int					ft_issizet_allowed(t_flags *list, int idxtmp);// ft_verif_intmax.c
int					ft_islonglong_allowed(t_flags *list, int idxtmp);// ft_verif_longlong.c
int					ft_isshortshort_allowed(t_flags *list, int idxtmp);// ft_verif_shortshort.c
int					ft_islong_allowed(t_flags *list, int idxtmp);// ft_verif_long.c

int					ft_iszero_allowed(t_flags *list, int idxtmp);// ft_verif_zero.c
int					ft_isspcs_allowed(t_flags *list, int idxtmp);// ft_verif_spcs.c
int					ft_isleft_allowed(t_flags *list, int idxtmp);// ft_verif_left.c
int					ft_isdigit_allowed(t_flags *list, int idxtmp);// ft_verif_number.c
int					ft_ishash_allowed(t_flags *list, int idxtmp);// ft_verif_hash.c
int					ft_isnbsign_allowed(t_flags *list, int idxtmp);// ft_verif_numbersign.c

int					ft_verif_short(t_flags *list, int idxtmp);// ft_verif_short.c
int					ft_verif_long(t_flags *list, int idxtmp);// ft_verif_long.c
int					ft_verif_shortshort(t_flags *list, int idxtmp);// ft_verif_shortshort.c
int					ft_verif_longlong(t_flags *list, int idxtmp);// ft_verif_longlong.c
int					ft_verif_sizet(t_flags *list, int idxtmp);// ft_verif_sizet.c
int					ft_verif_intmax(t_flags *list, int idxtmp);// ft_verif_intmax.c

int					ft_verif_left(t_flags *list, int idxtmp);// ft_verif_left.c
int					ft_verif_spcs(t_flags *list, int idxtmp);// ft_verif_spcs.c
int					ft_verif_number(t_flags *list, int idxtmp);// ft_verif_number.c
int					ft_verif_zero(t_flags *list, int idxtmp);// ft_verif_zero.c
int					ft_verif_hash(t_flags *list, int idxtmp);// ft_verif_hash.c
int					ft_verif_numbersign(t_flags *list, int idxtmp);// ft_verif_numbersign.c

int					ft_verif_option(t_flags *list);// ft_verif_option.c
int					ft_verif_flags(t_flags *list);// ft_verif_flags.c
int					ft_verif_conv(t_flags *list, va_list args);// ft_verif_conv.c

t_flags				*ft_init_flags(t_flags *list, const char *format);
int					ft_handle(t_flags *list, va_list args);
int					ft_printf(const char *format, ...);

/*----------------------------------------------------
***********************END OF************************|
********************REMASTERIZED*********************|
**----------------------------------------------------
*/

/*
** libft
*/

int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_isspace(char chr);

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

wchar_t				*ft_wstrdup(wchar_t *wstr);
wchar_t				*ft_wstrnew(size_t size);
wchar_t				*ft_wstrjoin(wchar_t *src, wchar_t *dest);
size_t				ft_wstrlen(wchar_t *wstr);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
unsigned long int			ft_atoli(const char *str);
int					ft_ctoi(char c);

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);

void				ft_wstrdel(wchar_t **wstr);
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
char				*ft_itoa(int n);
char				*ft_sitoa_base(short int nb, int base);
char				*ft_llitoa_base(long long int nb, int base);
char				*ft_litoa_base(long int nb, int base);
char				*ft_luitoa_base(unsigned long int num, int base);
char				*ft_ustoa_base(unsigned short int num, int base);
char				*ft_uctoa_base(unsigned char num, int base);
char				*ft_itoa_base(int num, int base);
char				*ft_ctoa_base(char num, int base);
char				*ft_itoo(int num);
char				*ft_imtoa_base(intmax_t num, int base);
char				*ft_stoa_base(size_t num, int base);
char				*ft_uitoa_base(uintmax_t num, int base);
char				*ft_itob(long long int nb, int size);
char				*ft_btoh(char *strbin);

void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
int					ft_wputchar(wchar_t wc);
int					ft_wputstr(wchar_t *wstr);

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

wchar_t				*ft_wreallocf(wchar_t *ptr, size_t size);
char				*ft_reallocf(char *ptr, size_t size);

int					ft_get_next_line(const int fd, char **line);

#endif