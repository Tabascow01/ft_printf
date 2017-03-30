# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/16 04:30:58 by mchemakh          #+#    #+#              #
#    Updated: 2017/03/29 04:29:22 by mchemakh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS_NAME = ft_atoi.c ft_bzero.c ft_islower.c ft_isupper.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_itoa_base.c ft_sitoa_base.c ft_llitoa_base.c ft_litoa_base.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c ft_reallocf.c ft_get_next_line.c ft_printf.c ft_handle.c ft_init.c ft_isflag.c ft_itob.c ft_btoh.c ft_wputchar.c ft_wputstr.c ft_isspace.c ft_ctoi.c ft_verif_conv.c ft_verif_flags.c ft_verif_percent.c ft_verif_numbersign.c ft_verif_hash.c ft_verif_zero.c ft_verif_int.c ft_verif_left.c ft_verif_number.c ft_verif_spcs.c ft_process_int.c ft_process_percent.c ft_noflags.c ft_check_flags.c ft_return_size.c ft_process_flags.c ft_signflag.c ft_hashflag.c ft_ldigitflag.c ft_lspaceflag.c ft_zeroflag.c ft_digitflag.c ft_spaceflag.c ft_verif_option.c ft_process_option.c ft_verif_sizet.c ft_verif_intmax.c ft_verif_short.c ft_verif_long.c ft_verif_shortshort.c ft_verif_longlong.c ft_process_sizet.c ft_process_intmax.c ft_process_short.c ft_process_long.c ft_process_sshort.c ft_process_llong.c ft_verif_hex.c ft_process_hex.c ft_verif_uint.c ft_process_uint.c ft_uitoa_base.c ft_luitoa_base.c ft_ustoa_base.c ft_process_oct.c ft_verif_oct.c ft_verif_chr.c ft_process_chr.c ft_verif_ptr.c ft_process_ptr.c ft_verif_str.c ft_process_str.c ft_clear_flags.c ft_verif_int_up.c ft_process_int_up.c ft_stoa_base.c ft_imtoa_base.c ft_itoo.c ft_cut_str.c ft_dec_digit.c ft_verif_wchr.c ft_verif_wstr.c ft_process_wchr.c ft_process_wstr.c ft_wstrlen.c ft_verif_noconv.c ft_return_wsize.c ft_wdigitflag.c ft_wldigitflag.c ft_wstrnew.c ft_wstrjoin.c ft_wstrdup.c ft_wreallocf.c ft_wstrdel.c ft_wzeroflag.c ft_atoli.c ft_uctoa_base.c ft_vrf_cv_n.c ft_argnull.c ft_strrev.c ft_process_flags_n.c ft_return_size_n.c ft_ldigitflag_n.c ft_dgt_n.c ft_dgt_nn.c ft_ldgt_n.c ft_ldgt_nn.c ft_wdgt_n.c ft_wdgt_nn.c ft_wldgt_n.c ft_wldgt_nn.c
SRCS_PATH = srcs/

OBJ_NAME = $(SRCS_NAME:.c=.o)
OBJ_PATH = objs/

INC_PATH = -I includes/

SRC = $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[1;31m[OBJS]\033[0m"
	@echo "\033[1;32m[Created]\033[0m"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[1;31m[libftprintf.a]\033[0m"
	@echo "\033[1;32m[Created]\033[0m"

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INC_PATH) -g -o $@ -c $<
#	@echo "\033[32m█\033[0m\c"

clean: 
	@rm -rf $(OBJ_PATH)
	@echo "\033[1;31m[OBJS]\033[0m"
	@echo "\033[1;35m[Deleted]\033[0m"

fclean: clean
	@/bin/rm -rf $(NAME)
	@echo "\033[1;31m[libftprintf.a]\033[0m"
	@echo "\033[1;35m[Deleted]\033[0m"

re: fclean all

.PHONY: all, clean, fclean, re
