NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

FILES = main
FILES_B=
UTILS_FILE = lst_utils verif_utils
INST_FILE = ft_push ft_swap ft_rotate ft_rrotate
ALGO_FILE = triforce five_num undred_num turk_sort
# ALGO_FILE = random

#tout les repertoire 
SRCS_DIR = ./
UTILS_DIR = ./utils/
OBJS_DIR = ./objet/
INST_DIR = ./instruction/
ALGO_DIR = ./algo/
LIBFT_PATH = ./includes/libft


#creation du nom complet des files (chemin + nom + extention)
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
UTILS = $(addprefix $(UTILS_DIR), $(addsuffix .c, $(UTILS_FILE)))
INST = $(addprefix $(INST_DIR), $(addsuffix .c, $(INST_FILE)))
ALGO = $(addprefix $(ALGO_DIR), $(addsuffix .c, $(ALGO_FILE)))

#creation du nom complet des objet (chemin + nom + extention)
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))
UTILS_OBJ = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(UTILS_FILE)))
INST_OBJ = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(INST_FILE)))
ALGO_OBJ = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(ALGO_FILE)))

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

$(OBJS_DIR)%.o: $(ALGO_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$@ : $(GREEN)[OK]$(NC)"

$(NAME): $(LIBFT) $(OBJS) $(UTILS_OBJ) $(INST_OBJ) $(ALGO_OBJ)
	@$(CC) $(CFLAGS) $(OBJS) $(UTILS_OBJ) $(INST_OBJ) $(ALGO_OBJ) $(LIBFT) -o $(NAME)
	@echo "$@ : $(BLUE)[READY]$(NC)"
	@echo "\n$(BLUE)================= [ START ] =================$(NC)\n"
	@./push_swap 61 7 20 36 30 69 91 100 1 72 81 28 9 70 10 79 96 60 35 24 34 23 87 67 75 45 40 73 88 93 14 94 44 19 38 58 65 54 82 83 8 3 63 89 32 78 71 86 29 17 77 4 39 13 48 49 57 6 11 41 2 15 59 22 37 62 97 52 5 43 21 31 33 47 84 46 85 26 27 74 55 92 99 98 12 51 68 50 53 80 56 95 76 18 25 16 90 64 42 66

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
