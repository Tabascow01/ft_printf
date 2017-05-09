/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 02:56:18 by mchemakh          #+#    #+#             */
/*   Updated: 2017/04/29 16:49:32 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define BUFF_SIZE 1

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>

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
	int			nbleft;
}					t_flags;

typedef struct		s_precs
{
	char		*zero;
	char		*spaces;
	char		*tmp;
	char		*tmpargs;
	wchar_t		*wtmp;
	wchar_t		*wtmpargs;
	int			i;
	int			j;
	int			size;
	int			neg;
	int			null;
	int			flags;
}					t_precs;

typedef struct		s_list
{
	struct s_list	*next;
	void			*content;
	size_t			content_size;
}					t_list;

/*
** ft_printf
*/

int					ft_ishex(char *str);
int					ft_strzhash_n(t_flags *list, char ***str, char **tmp);
void				ft_strzhash_nn(t_flags *list, char **newarg);
void				ft_strzhash_nnn(char **n, char **tp, char **trg, char ***s);
void				ft_strzhash_nnnn(int *i, int *j);

void				ft_wldgt_8(t_flags *lit, t_precs *lst, int *dtmp, int *d);
void				ft_wldgt_7(t_flags *list, t_precs *lst, int *d);
void				ft_wldgt_6(t_flags *list, t_precs *lst, wchar_t **ar);
void				ft_wldgt_5(t_flags *lit, t_precs *lst, int *d);
void				ft_wldgt_4(t_precs *lst, int *dtmp, wchar_t **ar);
void				ft_wldgt_3(t_precs *lst, int *dtmp, wchar_t **ar);
void				ft_wldgt_2(t_flags *lit, t_precs *lst, int *dtmp, int *d);
void				ft_wldgt_1(t_flags *lit, t_precs *lst, int *dtmp);

void				ft_wdgt_7(t_flags *lit, t_precs *lst, int *dtmp, int *d);
void				ft_wdgt_6(t_flags *lit, t_precs *lst, int *d);
void				ft_wdgt_5(t_flags *lit, t_precs *lst, int *d, wchar_t **ar);
void				ft_wdgt_4(t_flags *lit, t_precs *lst, int *d, wchar_t **ar);
void				ft_wdgt_3(t_precs *lst, int *dgtmp, wchar_t **ar);
void				ft_wdgt_2(t_flags *list, t_precs *lst, int *dtmp, int *d);
int					ft_wdgt_1(t_flags *list, t_precs *lst, int *dtmp, int *d);

void				ft_ldgt_8(t_flags *list, t_precs *lst);
void				ft_ldgt_7(t_flags *list, t_precs *lst);
void				ft_ldgt_5(char **ar, t_flags *list, t_precs *lst);
void				ft_ldgt_4(t_flags *list, t_precs *lst);
void				ft_ldgt_3(t_flags *list, t_precs *lst);
int					ft_ldgt_1(t_flags *list, t_precs *lst);

void				ft_dgt_nnn(t_flags *list, t_precs *lst, char **n);
void				ft_dgt_8(t_flags *list, t_precs *lst);
void				ft_dgt_7(t_flags *list, t_precs *lst);
void				ft_dgt_5_n(t_flags *list, t_precs *lst, int *a);
void				ft_dgt_5(char **ar, t_flags *list, t_precs *lst);
void				ft_dgt_4(t_flags *list, t_precs *lst);
void				ft_dgt_3(t_flags *list, t_precs *lst);
int					ft_dgt_1(t_flags *list, t_precs *lst);

void				ft_ldigit_nnnnn(t_flags *l, char **n, int *dgt, t_precs *s);
void				ft_ldigit_nnnn(t_flags *list, int *size, int *i, char **s);
void				ft_return_size_nn(t_flags *list);
void				ft_return_size_nnn(t_flags *list);
void				ft_return_size_nnnn2(t_flags *list);
void				ft_return_size_nnnn(t_flags *list);
void				ft_return_size_nnnnn(t_flags *list);
void				ft_process_flags_nnnn(t_flags *list);

char				*ft_strtolower(char *str);
char				*ft_strtoupper(char *str);
char				*ft_strrev(char *str, int i);
int					ft_argnull(t_flags *list);
void				ft_decompose_digit(t_flags *list);
void				ft_cut_lststr(t_flags *list, int start);
int					ft_verif_noconv(t_flags *list, int idxtmp);
void				ft_clear_precs(t_precs *lst);
void				ft_clear_flags(t_flags *list);
int					ft_isflag(char c);
int					ft_noflags(char c);
int					ft_check_flags(t_flags *list);
void				ft_return_size(t_flags *list);
void				ft_return_wsize(t_flags *list);

void				ft_wldigitflag(t_flags *list);
void				ft_wdigitflag(t_flags *list);
void				ft_spaceflag(t_flags *list);
void				ft_digitflag(t_flags *list);
void				ft_lspaceflag(t_flags *list);
void				ft_ldigitflag(t_flags *list);
void				ft_wzeroflag(t_flags *list);
void				ft_strzhash(t_flags *list, char **str);
void				ft_zhashflag(t_flags *list);
void				ft_zeroflag(t_flags *list);
void				ft_hashflag(t_flags *list);
void				ft_signflag(t_flags *list);

void				ft_process_sizet(t_flags *list, va_list args, char conv);
void				ft_process_intmax(t_flags *list, va_list args, char conv);
void				ft_process_short(t_flags *list, va_list args, char conv);
void				ft_process_long(t_flags *list, va_list args, char conv);
void				ft_process_sshort(t_flags *list, va_list args, char conv);
void				ft_process_llong(t_flags *list, va_list args, char conv);
void				ft_process_flags(t_flags *list);
void				ft_process_option(t_flags *list, va_list args, char conv);
void				ft_process_percent(t_flags *list);

int					ft_print_wstr(t_flags *list);
int					ft_print_wchr(t_flags *list, wchar_t c);
int					ft_print_str(t_flags *list);
int					ft_print_ptr(t_flags *list);
int					ft_print_chr(t_flags *list, char c);
int					ft_print_oct(t_flags *list);
int					ft_print_uint(t_flags *list);
int					ft_print_hex(t_flags *list);
int					ft_print_int_up(t_flags *list);
int					ft_print_int(t_flags *list);

void				ft_process_wstr(t_flags *list);
void				ft_process_wchr(t_flags *list);
void				ft_process_str(t_flags *list);
void				ft_process_ptr(t_flags *list);
void				ft_process_chr(t_flags *list);
void				ft_process_oct(t_flags *list);
void				ft_process_uint(t_flags *list);
void				ft_process_hex(t_flags *list);
void				ft_process_int_up(t_flags *list);
void				ft_process_int(t_flags *list);

void				ft_save_wstr(t_flags *list, va_list args);
void				ft_save_wchr(t_flags *list, va_list args);
void				ft_save_str(t_flags *list, va_list args);
void				ft_save_ptr(t_flags *list, va_list args);
void				ft_save_chr(t_flags *list, va_list args);
void				ft_save_oct_up(t_flags *list, va_list args);
void				ft_save_oct_low(t_flags *list, va_list args);
void				ft_save_uint_up(t_flags *list, va_list args);
void				ft_save_uint_low(t_flags *list, va_list args);
void				ft_save_hex_up(t_flags *list, va_list args);
void				ft_save_hex_low(t_flags *list, va_list args);
void				ft_save_int_up(t_flags *list, va_list args);
void				ft_save_int(t_flags *list, va_list args);

int					ft_verif_wstr(t_flags *list, int idxtmp);
int					ft_verif_wchr(t_flags *list, int idxtmp);
int					ft_verif_str(t_flags *list, int idxtmp);
int					ft_verif_ptr(t_flags *list, int idxtmp);
int					ft_verif_chr(t_flags *list, int idxtmp);
int					ft_verif_oct_up(t_flags *list, int idxtmp);
int					ft_verif_oct_low(t_flags *list, int idxtmp);
int					ft_verif_uint_up(t_flags *list, int idxtmp);
int					ft_verif_uint_low(t_flags *list, int idxtmp);
int					ft_verif_hex_up(t_flags *list, int idxtmp);
int					ft_verif_hex_low(t_flags *list, int idxtmp);
int					ft_verif_int_up(t_flags *list, int idxtmp);
int					ft_verif_int(t_flags *list, int idxtmp);

int					ft_verif_percent(t_flags *list, int idxtmp);
void				ft_save_spcs(t_flags *list, int idxtmp);
void				ft_save_digit(t_flags *list, int idxtmp);
void				ft_save_sign(t_flags *list, int idxtmp);
void				ft_save_left(t_flags *list, int idxtmp);

int					ft_isshort_allowed(t_flags *list, int idxtmp);
int					ft_isintmax_allowed(t_flags *list, int idxtmp);
int					ft_issizet_allowed(t_flags *list, int idxtmp);
int					ft_islonglong_allowed(t_flags *list, int idxtmp);
int					ft_isshortshort_allowed(t_flags *list, int idxtmp);
int					ft_islong_allowed(t_flags *list, int idxtmp);

int					ft_iszero_allowed(t_flags *list, int idxtmp);
int					ft_isspcs_allowed(t_flags *list, int idxtmp);
int					ft_isleft_allowed(t_flags *list, int idxtmp);
int					ft_isdigit_allowed(t_flags *list, int idxtmp);
int					ft_ishash_allowed(t_flags *list, int idxtmp);
int					ft_isnbsign_allowed(t_flags *list, int idxtmp);

int					ft_verif_short(t_flags *list, int idxtmp);
int					ft_verif_long(t_flags *list, int idxtmp);
int					ft_verif_shortshort(t_flags *list, int idxtmp);
int					ft_verif_longlong(t_flags *list, int idxtmp);
int					ft_verif_sizet(t_flags *list, int idxtmp);
int					ft_verif_intmax(t_flags *list, int idxtmp);

int					ft_verif_left(t_flags *list, int idxtmp);
int					ft_verif_spcs(t_flags *list, int idxtmp);
int					ft_verif_number(t_flags *list, int idxtmp);
int					ft_verif_zero(t_flags *list, int idxtmp);
int					ft_verif_hash(t_flags *list, int idxtmp);
int					ft_verif_numbersign(t_flags *list, int idxtmp);

int					ft_verif_option(t_flags *list);
int					ft_verif_flags(t_flags *list);
int					ft_vrf_cv_nnnnn(t_flags *lst, int *i, va_list args);
int					ft_verif_conv(t_flags *list, va_list args);

t_precs				*ft_init_precs(t_precs *lst);
t_flags				*ft_init_flags(t_flags *list, const char *format);
int					ft_handle(t_flags *list, va_list args);
int					ft_printf(const char *format, ...);

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
unsigned long int	ft_atoli(const char *str);
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
void				ft_lstadd(t_list **alst, t_list *n);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

wchar_t				*ft_wreallocf(wchar_t *ptr, size_t size);
char				*ft_reallocf(char *ptr, size_t size);

int					ft_get_next_line(const int fd, char **line);

#endif
