NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

FILES = main
FILES_B=
UTILS_FILE = lst_utils verif_utils move_utils
INST_FILE = ft_push ft_swap ft_rotate ft_rrotate
# ALGO_FILE = random

#tout les repertoire 
SRCS_DIR = ./
UTILS_DIR = ./utils/
OBJS_DIR = ./objet/
INST_DIR = ./instruction/
LIBFT_PATH = ./libft


#creation du nom complet des files (chemin + nom + extention)
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
UTILS = $(addprefix $(UTILS_DIR), $(addsuffix .c, $(UTILS_FILE)))
INST = $(addprefix $(INST_DIR), $(addsuffix .c, $(INST_FILE)))

#creation du nom complet des objet (chemin + nom + extention)
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))
UTILS_OBJ = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(UTILS_FILE)))
INST_OBJ = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(INST_FILE)))

GREEN = \033[1;32m
BLUE =  \033[1;34m
RED = \033[1;31m
NC = \033[0m 

LIBFT = $(LIBFT_PATH)/libft.a

#creation des .o pour les files generale
$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$@ : $(GREEN)[OK]$(NC)"

#creation des .o pour les files utils
$(OBJS_DIR)%.o: $(UTILS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$@ : $(GREEN)[OK]$(NC)"

#creation des .o pour les files instruction
$(OBJS_DIR)%.o: $(INST_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$@ : $(GREEN)[OK]$(NC)"

$(NAME): $(LIBFT) $(OBJS) $(UTILS_OBJ) $(INST_OBJ)
	@$(CC) $(CFLAGS) $(OBJS) $(UTILS_OBJ) $(INST_OBJ) $(LIBFT) -o $(NAME)
	@echo "$@ : $(BLUE)[READY]$(NC)"
	@echo "\n$(BLUE)================= [ START ] =================$(NC)\n"
	@./push_swap 31 7 32 95 62 11 65 30 13 15 82 78 29 79 6 38 76 98 77 14 21 18 70 99 8 4 86 10 5 83 35 85 51 47 80 37 55 67 49 69 58 3 56 97 90 22 9 44 50 45 100 2 39 42 41 40 72 36 88 89 91 71 17 59 61 75 96 1 52 27 81 12 33 24 43 54 68 48 93 64 73 87 74 66 28 16 84 23 60 53 26 34 19 57 25 63 46 94 20 92
	@echo "\n\n$(BLUE)================= [  END  ] =================$(NC)\n"

$(LIBFT):
	@make -C $(LIBFT_PATH) all
	@clear
	@echo "libft : $(GREEN)[OK]$(NC)"

all: $(NAME)

clean:
	@$(RM) -rf $(OBJS_DIR)
	@make clean -C $(LIBFT_PATH)
	clear
	@echo "$(RED)============== [OBJECT DELETED] ==============$(NC)"

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT_PATH)
	clear
	@echo "$(RED)========== [ OBJECT / EX DELETED ] ==========$(NC)"
re: fclean all

.PHONY: all clean fclean re
