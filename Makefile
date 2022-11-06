NAME 		= push_swap

CC 			= gcc

CFLAGS 		= -Wall -Wextra -Werror#-fsanitize=address -g -ggdb3  #-Werror#TODO add flags

LIBFT 		= -lft -L libft

FT_PRINTF 	= -lftprintf -L ft_printf

SRCS		= $(shell find "." -maxdepth 1 -name '*.c')

OBJS 		= $(SRCS:%.c=%.o)

%.c:
	@$(CC) $(CFLAGS)

all: lib ftprintf $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(MLX) $(LIBFT) $(FT_PRINTF) -o $(NAME)
	@echo -e "$(GREEN)✅$(NAME) created!$(DEFAULT) 😊🥑"

ftprintf:
	@cd ft_printf && make

lib:
	@cd libft && make

clean:
	@rm -f ./*.o
	@echo -e "$(YELLOW)🧨 Object files deleted!$(DEFAULT)"

fclean: clean
	@cd ./libft && make fclean
	@cd ./ft_printf && make fclean
	@rm -f $(NAME)
	@echo -e "$(RED)💣 All deleted!$(DEFAULT)"

re: fclean all

.PHONY: all clean fclean re lib ftprintf

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m
