# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdrouet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 08:31:45 by cdrouet           #+#    #+#              #
#    Updated: 2015/12/02 14:56:58 by cdrouet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_isascii.c \
   	  ft_memchr.c \
   	  ft_putnbr_fd.c \
	  ft_strcmp.c \
  	  ft_striter.c \
   	  ft_strmapi.c \
   	  ft_strnstr.c \
   	  ft_tolower.c \
      ft_isdigit.c \
   	  ft_memcmp.c \
  	  ft_putchar.c \
   	  ft_putstr.c \
  	  ft_strcpy.c \
  	  ft_striteri.c \
	  ft_strncat.c \
   	  ft_strrchr.c \
   	  ft_toupper.c \
	  ft_atoi.c \
	  ft_isprint.c \
   	  ft_memcpy.c \
  	  ft_putchar_fd.c \
	  ft_putstr_fd.c  \
	  ft_strctrim.c \
	  ft_strjoin.c \
	  ft_strncmp.c \
   	  ft_strsplit.c \
	  ft_bzero.c \
 	  ft_itoa.c \
	  ft_memdel.c \
  	  ft_putendl.c \
   	  ft_strcat.c \
  	  ft_strdel.c \
  	  ft_strlcat.c \
   	  ft_strncpy.c \
	  ft_strstr.c \
	  ft_isalnum.c \
   	  ft_memalloc.c \
	  ft_memmove.c \
   	  ft_putendl_fd.c \
	  ft_strchr.c \
  	  ft_strdup.c \
  	  ft_strlen.c \
  	  ft_strnequ.c \
   	  ft_strsub.c \
	  ft_isalpha.c \
   	  ft_memccpy.c \
   	  ft_memset.c \
  	  ft_putnbr.c \
  	  ft_strclr.c \
  	  ft_strequ.c \
  	  ft_strmap.c \
  	  ft_strnew.c \
  	  ft_strtrim.c \
	  ft_lstnew.c \
	  ft_lstdelone.c \
	  ft_lstdel.c \
	  ft_lstadd.c \
	  ft_lstiter.c \
	  ft_lstmap.c

BIN = ft_isascii.o \
	  ft_memchr.o \
	  ft_putnbr_fd.o \
	  ft_strcmp.o \
	  ft_striter.o \
	  ft_strmapi.o \
	  ft_strnstr.o \
	  ft_tolower.o \
	  ft_isdigit.o \
	  ft_memcmp.o \
	  ft_putchar.o \
	  ft_putstr.o \
	  ft_strcpy.o \
	  ft_striteri.o \
	  ft_strncat.o \
	  ft_strrchr.o \
	  ft_toupper.o \
	  ft_atoi.o \
	  ft_isprint.o \
	  ft_memcpy.o \
      ft_putchar_fd.o \
      ft_putstr_fd.o  \
      ft_strctrim.o \
      ft_strjoin.o \
      ft_strncmp.o \
      ft_strsplit.o \
      ft_bzero.o \
      ft_itoa.o \
      ft_memdel.o \
      ft_putendl.o \
      ft_strcat.o \
      ft_strdel.o \
      ft_strlcat.o \
      ft_strncpy.o \
      ft_strstr.o \
      ft_isalnum.o \
      ft_memalloc.o \
      ft_memmove.o \
      ft_putendl_fd.o \
      ft_strchr.o \
      ft_strdup.o \
      ft_strlen.o \
      ft_strnequ.o \
      ft_strsub.o \
      ft_isalpha.o \
      ft_memccpy.o \
      ft_memset.o \
      ft_putnbr.o \
      ft_strclr.o \
      ft_strequ.o \
      ft_strmap.o \
      ft_strnew.o \
      ft_strtrim.o \
	  ft_lstnew.o \
	  ft_lstdelone.o \
	  ft_lstdel.o \
	  ft_lstadd.o \
	  ft_lstiter.o \
	  ft_lstmap.o

FLAG = -Wall -Wextra -Werror

$(NAME) : 
	gcc $(FLAG) -c $(SRC) ; ar rc $(NAME) $(BIN) ; ranlib $(NAME)

all : $(NAME)

clean :
	rm -f $(BIN)

fclean : clean
	rm -f $(NAME)

re : fclean all
