.PHONY: clean, fclean, re

.SUFFIXES:

NAME = libftprintf.a

CC = gcc

SRCC = flag.c flag_flag.c ft_printf.c lenmod.c operation.c operation_2.c other.c

SRCO = flag.o flag_flag.o ft_printf.o lenmod.o operation.o operation_2.o other.o

LIB_SRCO = 	ft_itoa.o ft_atoi.o ft_litoa.o ft_dbltoa.o ft_ulitoa.o			\
			ft_initmod.o ft_initlmod.o ft_bin_to_dec.o ft_dec_to_bin.o		\
			ft_dec_to_hex.o ft_dec_to_sci.o ft_hex_to_dec.o ft_ptr_to_hex.o	\
			ft_dec_to_base.o ft_ldec_to_bin.o ft_ldec_to_hex.o				\
			ft_ldec_to_base.o	ft_lstnew.o ft_lstdel.o ft_lstadd.o			\
			ft_lstmap.o ft_lstiter.o ft_lstappend.o ft_lstdelone.o			\
			ft_charswap.o ft_pow.o ft_swap.o ft_wstrlen.o ft_wcharlen.o		\
			ft_putstr.o ft_putnbr.o ft_putlnbr.o ft_putwstr.o ft_putendl.o	\
			ft_putchar.o ft_putnstr.o ft_putwchar.o ft_putxchar.o			\
			ft_putstr_fd.o ft_putnbr_fd.o ft_putendl_fd.o ft_putchar_fd.o	\
			ft_ret_putchar.o												\
			ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o\
			ft_is_wstring.o ft_is_white_space.o	ft_is_wchar.o				\
			ft_strlen.o ft_strdup.o ft_strcpy.o ft_strcat.o ft_strchr.o		\
			ft_strstr.o ft_strcmp.o ft_strrev.o ft_strnew.o ft_strdel.o		\
			ft_strclr.o ft_strmap.o ft_strequ.o ft_strsub.o ft_strncat.o	\
			ft_strlcat.o ft_toupper.o ft_tolower.o ft_strncpy.o ft_strrchr.o\
			ft_strnstr.o ft_strncmp.o ft_striter.o ft_strmapi.o ft_strnequ.o\
			ft_strjoin.o ft_strtrim.o ft_striteri.o ft_strsplit.o			\
			ft_chrjoin_free.o ft_strjoin_free.o								\
			ft_bzero.o ft_memcpy.o ft_memchr.o ft_memcmp.o ft_memset.o		\
			ft_memdel.o ft_memccpy.o ft_memmove.o ft_memalloc.o

SRCO_SUB = objfiles

CFLAGS = -Wall -Wextra -Werror

all: lib $(NAME)

lib:
	make -C ./libft

%.o: %.c
	$(CC) $(CFLAGS) -c $(SRCC)

$(NAME): $(SRCO)
	ar rc $(NAME) $(SRCO) $(addprefix libft/$(SRCO_SUB)/, $(LIB_SRCO)) && ranlib $(NAME)

clean:
	make -C ./libft clean
	rm -f $(SRCO)

fclean: clean
	make -C ./libft fclean
	rm -f $(NAME)

re: fclean all
