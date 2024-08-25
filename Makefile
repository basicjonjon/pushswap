NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

FILES = main
FILES_B =
UTIL_FILE = cost_utils display_utils hit_utils lst_utils move_utils target_utils verif_utils
INST_FILE = ft_push ft_swap ft_rotate ft_rrotate
ALGO_FILE = triforce turk_sort
VERI_FILE = value_verification repeat_verification
# ALGO_FILE = random

#tout les repertoire 
SRCS_DIR = ./
UTIL_DIR = ./utils/
OBJS_DIR = ./objet/
INST_DIR = ./instruction/
ALGO_DIR = ./algo/
VERI_DIR = ./verification/
LIBFT_PATH = ./includes/libft


#creation du nom complet des files (chemin + nom + extention)
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
UTIL = $(addprefix $(UTIL_DIR), $(addsuffix .c, $(UTIL_FILE)))
INST = $(addprefix $(INST_DIR), $(addsuffix .c, $(INST_FILE)))
ALGO = $(addprefix $(ALGO_DIR), $(addsuffix .c, $(ALGO_FILE)))
VERI = $(addprefix $(VERI_DIR), $(addsuffix .c, $(VERI_FILE)))

#creation du nom complet des objet (chemin + nom + extention)
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))
UTIL_OBJ = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(UTIL_FILE)))
INST_OBJ = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(INST_FILE)))
ALGO_OBJ = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(ALGO_FILE)))
VERI_OBJ = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(VERI_FILE)))

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

#creation des .o pour les files UTIL
$(OBJS_DIR)%.o: $(UTIL_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$@ : $(GREEN)[OK]$(NC)"

#creation des .o pour les files instruction
$(OBJS_DIR)%.o: $(INST_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$@ : $(GREEN)[OK]$(NC)"

#creation des .o pour les files ALGO
$(OBJS_DIR)%.o: $(ALGO_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$@ : $(GREEN)[OK]$(NC)"

#creation des .o pour les files verification
$(OBJS_DIR)%.o: $(VERI_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$@ : $(GREEN)[OK]$(NC)"

$(NAME): $(LIBFT) $(OBJS) $(UTIL_OBJ) $(INST_OBJ) $(ALGO_OBJ) $(VERI_OBJ)
	@$(CC) $(CFLAGS) $(OBJS) $(UTIL_OBJ) $(INST_OBJ) $(ALGO_OBJ) $(LIBFT) $(VERI_OBJ) -o $(NAME)
	@echo "$@ : $(BLUE)[READY]$(NC)"
	@echo "\n$(BLUE)================= [ START ] =================$(NC)\n"
	@./push_swap 1 3 2

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
