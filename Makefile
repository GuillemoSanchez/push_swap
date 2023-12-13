NAME = push_swap

# ------- COLORS -------
NC				=	\033[0m
RED				=	\033[0;31m
GREEN			=	\033[0;32m
LRED			=	\033[1;31m
LGREEN			=	\033[1;32m
YELLOW			=	\033[1;33m
LBLUE			=	\033[1;34m
TITLE			=	\033[38;5;33m

BIN = bin
DIR_SRC = src
INCLUDE = -I inc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
CC = gcc $(CFLAGS) $(INCLUDE)

# <------ LIBFT ------>
LIBFT_DIR = libft
LIBFT_PATH = $(LIBFT_DIR)/libft.a
LIBFT_MAKE = Makefile
LFLAGS:= -L $(LIBFT_DIR) -lft

SRC = 	ft_push_swap.c \
		ft_parse.c \
		ft_free.c

OBJS = $(SRC:%.c=$(BIN)/%.o)

# <------ RULES/TRIGGER ------>
all: $(NAME)

$(NAME) : $(LIBFT_PATH) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(NAME)
	@echo "   $(LGREEN) - $(NAME) compiled 🙂 [OK]${NC}\n"

$(BIN)/%.o : $(DIR_SRC)/%.c
	@mkdir -p $(dir $@)
	@$(CC) -c $< -o $@

$(LIBFT_PATH) :
	@cd $(LIBFT_DIR) && make
	@echo "   $(LGREEN) - LIBFT compiled 🙂 [OK]${NC}\n"

clean:
	@make -C $(LIBFT_DIR) -f $(LIBFT_MAKE) fclean
	rm -rf $(BIN)

fclean: clean
	rm -rf $(OBJS) $(NAME)

re : fclean all

.PHONY: all re clean fclean