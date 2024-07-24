# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/01 15:15:00 by jle-doua          #+#    #+#              #
#    Updated: 2024/07/24 13:00:40 by jle-doua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

FILES = ft_memset \
		ft_bzero \
		ft_memcpy \
		ft_memmove \
		ft_memchr \
		ft_memcmp \
		ft_strlen \
		ft_strlcpy \
		ft_strlcat \
		ft_strchr \
		ft_strrchr \
		ft_strnstr \
		ft_strncmp \
		ft_atoi \
		ft_isalpha \
		ft_isdigit \
		ft_isalnum \
		ft_isascii \
		ft_isprint \
		ft_toupper \
		ft_tolower \
		ft_calloc \
		ft_strdup \
		ft_substr \
		ft_strjoin \
		ft_strtrim \
		ft_split \
		ft_itoa \
		ft_strmapi \
		ft_putchar_fd \
		ft_putstr_fd \
		ft_putendl_fd \
		ft_putnbr_fd \
		ft_striteri \
		ft_printf \
		ft_putstr \
		ft_putnbr \
		ft_putunsigned \
		ft_putnbrbase \
		ft_putchar \
		ft_putadresse \

FILES_B= ft_lstnew \
	  	 ft_lstadd_front \
	  	 ft_lstsize \
	  	 ft_lstlast \
	  	 ft_lstadd_back \
	  	 ft_lstdelone \
	  	 ft_lstclear \
	  	 ft_lstiter \
	  	 ft_lstmap

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
SRCS_B = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES_B)))

OBJS_DIR = ./objet/
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))
OBJS_B = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES_B)))

MAIN_DIR = ./
MAIN = main

EXE = test

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	$(CC) $(CFLAGS) -c -o $@ $< 


$(NAME): $(LIBFT) $(OBJS_DIR) $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(LIBFT):
	make -C $(LIBFT_PATH) all

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

all: $(NAME)

clean:
	$(RM) -rf $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME) $(EXE) main.o

re: fclean all

test : $(OBJS)
	$(CC) $(CFLAGS) -c $(MAIN_DIR)$(MAIN).c -o $(MAIN_DIR)$(MAIN).o
	$(CC) -o $(EXE) $(OBJS) $(MAIN_DIR)$(MAIN).o -L./libft/ -lft

.PHONY: bonus all clean fclean re libft