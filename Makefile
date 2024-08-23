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
	@./push_swap 344 300 48 128 67 411 97 285 9 410 247 125 141 214 186 427 10 134 348 39 280 106 488 115 170 216 15 313 226 144 224 380 93 422 489 46 363 202 246 42 383 70 308 421 201 16 473 314 148 477 337 232 387 487 215 366 117 168 368 341 230 113 360 11 424 25 87 36 222 326 100 485 303 413 263 449 342 484 311 395 153 288 69 40 34 111 240 447 456 292 27 197 407 60 133 343 442 269 441 470 30 279 235 464 318 431 91 373 476 350 254 433 103 317 19 499 275 307 203 391 172 438 142 376 492 248 191 249 402 179 365 102 495 189 479 359 393 145 490 164 370 54 459 271 361 177 267 171 23 257 417 486 298 369 436 219 152 328 101 353 385 68 327 147 3 412 28 207 71 114 500 304 420 204 425 221 384 494 315 389 239 310 406 220 178 175 276 188 77 167 394 159 108 5 432 457 22 367 335 81 260 166 258 99 455 236 287 253 90 212 334 92 471 284 180 264 6 119 237 190 14 440 150 187 156 20 409 7 469 57 446 474 377 281 183 76 362 155 378 336 428 84 453 181 18 184 47 375 43 270 278 371 192 321 206 462 339 195 79 465 491 283 354 408 351 227 146 31 358 443 396 423 223 218 13 397 331 66 460 74 209 268 26 136 82 390 286 33 498 105 86 169 63 329 112 94 435 332 309 200 251 127 110 157 8 266 41 296 386 165 452 404 211 301 379 323 80 399 478 481 445 252 297 381 56 32 205 185 73 126 88 65 176 154 17 475 325 149 55 419 324 294 233 357 83 444 50 448 282 208 231 193 372 52 316 338 241 116 198 415 122 107 330 137 299 160 51 162 12 138 319 340 104 89 78 439 293 161 242 44 312 228 143 429 255 467 405 130 217 305 355 121 289 496 482 333 466 261 120 95 352 250 58 434 173 140 468 2 194 35 302 129 374 497 290 401 349 1 96 229 291 62 463 139 174 243 262 320 403 4 493 277 273 123 483 274 225 437 426 454 182 98 85 135 400 49 451 306 256 151 59 24 38 461 458 163 132 244 245 64 414 158 61 53 382 364 29 210 272 346 21 37 398 45 75 450 480 295 213 347 199 109 356 265 416 124 196 118 392 430 238 345 72 472 322
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
