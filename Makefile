NAME 		= push_swap

CC 			= gcc

CFLAGS 		= -Wall -Wextra -Werror#-fsanitize=address -g -ggdb3  #-Werror#TODO add flags

SRCS		= $(shell find "." -maxdepth 1 -name '*.c' ! -name "*_bonus.c")

OBJS 		= $(SRCS:%.c=%.o)

FT_PRINTF 	= -lftprintf -L ft_printf

LIBFT		= -llibft -L libft

%.c:
	@$(CC) $(CFLAGS)

all: ftprintf libft $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(FT_PRINTF) $(LIBFT) -o $(NAME)
	@echo -e "$(GREEN)✅$(NAME) created!$(DEFAULT) 😊🥑"

ftprintf:
	@cd ft_printf && make

libft:
	@cd libft && make


clean:
	@rm -f ./*.o
	@echo -e "$(YELLOW)🧨 Object files deleted!$(DEFAULT)"

fclean: clean
	@cd ./ft_printf && make fclean
	@rm -f $(NAME)
	@echo -e "$(RED)💣 All deleted!$(DEFAULT)"

re: fclean all

.PHONY: all clean fclean re ftprintf

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m
