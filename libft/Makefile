# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: heinfalt <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/09 12:59:15 by heinfalt          #+#    #+#              #
#    Updated: 2016/12/05 12:47:28 by heinfalt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#PHONY allow rules to be done even w/ files w/ the same name in the dir.

.PHONY: clean, fclean, re, open, reset, all, cleared

#~~~~~~~~~~~~~~~~COLORS~~~~~~~~~~~~~~

BLACK = \033[30m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
PINK = \033[35m
CYAN = \033[36m
GREY = \033[37m

NORMAL = \033[0m

#target file which needs to be opened by the rule "open"

TARGET = NONE

#Name of the build (here a lib)

NAME = libft.a

#Compiler

CC = gcc

#Paths are the location of every .c files

PATH_IS = ft_is/

PATH_MEM = ft_mem/

PATH_PUT = ft_put/

PATH_STR = ft_str/

PATH_LST = ft_lst/

PATH_CONV = conv/

PATH_OTHR = other/

#Path of the location of every .o files

OBJDIR = objfiles

#Objs will be the fills we need to create to do the lib

SRCO_MEM =	ft_bzero.o ft_memcpy.o ft_memchr.o ft_memcmp.o ft_memset.o		\
			ft_memdel.o ft_memccpy.o ft_memmove.o ft_memalloc.o

SRCC_MEM =	ft_bzero.c ft_memcpy.c ft_memchr.c ft_memcmp.c ft_memset.c		\
			ft_memdel.c ft_memccpy.c ft_memmove.c ft_memalloc.c

SRCO_STR =	ft_strlen.o ft_strdup.o ft_strcpy.o ft_strcat.o ft_strchr.o		\
			ft_strstr.o ft_strcmp.o ft_strrev.o ft_strnew.o ft_strdel.o		\
			ft_strclr.o ft_strmap.o ft_strequ.o ft_strsub.o ft_strncat.o	\
			ft_strlcat.o ft_toupper.o ft_tolower.o ft_strncpy.o ft_strrchr.o\
			ft_strnstr.o ft_strncmp.o ft_striter.o ft_strmapi.o ft_strnequ.o\
			ft_strjoin.o ft_strtrim.o ft_striteri.o ft_strsplit.o			\
			ft_chrjoin_free.o ft_strjoin_free.o ft_strdup_free.o			\
			ft_strchange.o

SRCC_STR =	ft_strlen.c ft_strdup.c ft_strcpy.c ft_strcat.c ft_strchr.c		\
			ft_strstr.c ft_strcmp.c ft_strrev.c ft_strnew.c ft_strdel.c		\
			ft_strclr.c ft_strmap.c ft_strequ.c ft_strsub.c ft_strncat.c	\
			ft_strlcat.c ft_toupper.c ft_tolower.c ft_strncpy.c ft_strrchr.c\
			ft_strnstr.c ft_strncmp.c ft_striter.c ft_strmapi.c ft_strnequ.c\
			ft_strjoin.c ft_strtrim.c ft_striteri.c ft_strsplit.c			\
			ft_chrjoin_free.c ft_strjoin_free.c ft_strdup_free.c			\
			ft_strchange.c

SRCO_IS =	ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o\
			ft_is_wstring.o ft_is_white_space.o	ft_is_wchar.o

SRCC_IS =	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
			ft_is_wstring.c ft_is_white_space.c	ft_is_wchar.c

SRCO_PUT =	ft_putstr.o ft_putnbr.o ft_putlnbr.o ft_putwstr.o ft_putendl.o	\
			ft_putchar.o ft_putnstr.o ft_putwchar.o ft_putxchar.o			\
			ft_putstr_fd.o ft_putnbr_fd.o ft_putendl_fd.o ft_putchar_fd.o	\
			ft_ret_putchar.o

SRCC_PUT =	ft_putstr.c ft_putnbr.c ft_putlnbr.c ft_putwstr.c ft_putendl.c	\
			ft_putchar.c ft_putnstr.c ft_putwchar.c ft_putxchar.c			\
			ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c ft_putchar_fd.c	\
			ft_ret_putchar.c

SRCO_LST =	ft_lstnew.o ft_lstdel.o ft_lstadd.o ft_lstmap.o ft_lstiter.o	\
			ft_lstappend.o ft_lstdelone.o

SRCC_LST =	ft_lstnew.c ft_lstdel.c ft_lstadd.c ft_lstmap.c ft_lstiter.c	\
			ft_lstappend.c ft_lstdelone.c

SRCO_CONV =	ft_itoa.o ft_atoi.o ft_litoa.o ft_dbltoa.o ft_ulitoa.o			\
			ft_initmod.o ft_initlmod.o ft_bin_to_dec.o ft_dec_to_bin.o		\
			ft_dec_to_hex.o ft_dec_to_sci.o ft_hex_to_dec.o ft_ptr_to_hex.o	\
			ft_dec_to_base.o ft_ldec_to_bin.o ft_ldec_to_hex.o				\
			ft_ldec_to_base.o

SRCC_CONV = ft_itoa.c ft_atoi.c ft_litoa.c ft_dbltoa.c ft_ulitoa.c			\
			ft_initmod.c ft_initlmod.c ft_bin_to_dec.c ft_dec_to_bin.c		\
			ft_dec_to_hex.c ft_dec_to_sci.c ft_hex_to_dec.c ft_ptr_to_hex.c	\
			ft_dec_to_base.c ft_ldec_to_bin.c ft_ldec_to_hex.c				\
			ft_ldec_to_base.c

SRCO_OTHR =	ft_charswap.o ft_pow.o ft_swap.o ft_wstrlen.o ft_wcharlen.o		\
			ft_ret_free.o ft_nbrlen.o

SRCC_OTHR = ft_charswap.c ft_pow.c ft_swap.c ft_wstrlen.c ft_wcharlen.c		\
			ft_ret_free.c ft_nbrlen.c

#Compiler flags

CFLAGS = -Wall -Wextra -Werror

# ---------------------------------------
# 	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#				   RULES
# 	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# ---------------------------------------

#Master rule : "One Rule to rule them all !!"

all: $(NAME)

#Those ones display colored infos

reset:
	@ echo "\n\t$(GREY)~~~~[°Reseting the lib°]~~~~$(NORMAL)"

cleared:
	@ echo "\n\t$(RED)~~~~[°Deleting objs files°]~~~~\n$(NORMAL)"

#Those rules creats .o from .c if the obj is older than the src

$(OBJDIR)/%.o: $(PATH_STR)%.c
	@ echo "$(YELLOW)Creating ~~~> $^$(NORMAL)"
	@ mkdir -p $(OBJDIR)
	@ $(CC) $(CFLAGS) -c $^
	@ mv ./$(notdir $@) ./$(OBJDIR)/

$(OBJDIR)/%.o: $(PATH_LST)%.c
	@ echo "$(YELLOW)Creating ~~~> $^$(NORMAL)"
	@ mkdir -p $(OBJDIR)
	@ $(CC) $(CFLAGS) -c $^
	@ mv ./$(notdir $@) ./$(OBJDIR)/

$(OBJDIR)/%.o: $(PATH_PUT)%.c
	@ echo "$(YELLOW)Creating ~~~> $^$(NORMAL)"
	@ mkdir -p $(OBJDIR)
	@ $(CC) $(CFLAGS) -c $^
	@ mv ./$(notdir $@) ./$(OBJDIR)/

$(OBJDIR)/%.o: $(PATH_IS)%.c
	@ echo "$(YELLOW)Creating ~~~> $^$(NORMAL)"
	@ mkdir -p $(OBJDIR)
	@ $(CC) $(CFLAGS) -c $^
	@ mv ./$(notdir $@) ./$(OBJDIR)/

$(OBJDIR)/%.o: $(PATH_MEM)%.c
	@ echo "$(YELLOW)Creating ~~~> $^$(NORMAL)"
	@ mkdir -p $(OBJDIR)
	@ $(CC) $(CFLAGS) -c $^
	@ mv ./$(notdir $@) ./$(OBJDIR)/

$(OBJDIR)/%.o: $(PATH_CONV)%.c
	@ echo "$(YELLOW)Creating ~~~> $^$(NORMAL)"
	@ mkdir -p $(OBJDIR)
	@ $(CC) $(CFLAGS) -c $^
	@ mv ./$(notdir $@) ./$(OBJDIR)/

$(OBJDIR)/%.o: $(PATH_OTHR)%.c
	@ echo "$(YELLOW)Creating ~~~> $^$(NORMAL)"
	@ mkdir -p $(OBJDIR)
	@ $(CC) $(CFLAGS) -c $^
	@ mv ./$(notdir $@) ./$(OBJDIR)/

#This one build the lib

$(NAME): $(addprefix $(OBJDIR)/, $(SRCO_MEM) $(SRCO_STR) $(SRCO_PUT) $(SRCO_LST) $(SRCO_IS) $(SRCO_CONV) $(SRCO_OTHR))
	@ echo "\n\t$(GREEN)~~~~[°Creating the lib°]~~~~\n$(NORMAL)"
	ar rc $(NAME) $^ && ranlib $(NAME)

open:
	open $(TARGET)

# ---------------------------------------
# 	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#				  CLEANING
# 	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# ---------------------------------------

#Cleaning obj files

clean: cleared
	rm -f $(addprefix $(OBJDIR)/, $(SRCO_MEM) $(SRCO_STR) $(SRCO_PUT) $(SRCO_LST) $(SRCO_IS) $(SRCO_CONV) $(SRCO_OTHR))

#Cleaning obj files and the lib

fclean: clean
	@ echo "\n\t$(RED)~~~~[°Deleting .a file°]~~~~\n$(NORMAL)"
	rm -f $(NAME)

#Reset the compil : "Cleaning to rebuild everything better"

re: reset fclean all
