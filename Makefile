CC = cc
CFLAGS = -Wall -Werror -Wextra -g
NAME_CLIENT = client
NAME_SERVER = server
NAME_CLIENT_bonus = client_bonus
NAME_SERVER_bonus = server_bonus

LIB = Library/libft
LIBFT = $(LIB)/libft.a


all: $(NAME_CLIENT) $(NAME_SERVER)

bonus: $(NAME_CLIENT_bonus) $(NAME_SERVER_bonus)

$(NAME_CLIENT): $(LIBFT)
	@$(CC) $(CFLAGS) Mandatory/client.c -L$(LIB) -lft -o $(NAME_CLIENT)
	@echo "✔ GOOD $(NAME_CLIENT)"

$(NAME_SERVER): $(LIBFT)
	@$(CC) $(CFLAGS) Mandatory/server.c -L$(LIB) -lft -o $(NAME_SERVER)
	@echo "✔ GOOD $(NAME_SERVER)"

$(NAME_CLIENT_bonus): $(LIBFT)
	@$(CC) $(CFLAGS) bonus/client_bonus.c -L$(LIB) -lft -o $(NAME_CLIENT_bonus)
	@echo "✔ GOOD $(NAME_CLIENT_bonus)"

$(NAME_SERVER_bonus): $(LIBFT)
	@$(CC) $(CFLAGS) bonus/server_bonus.c -L$(LIB) -lft -o $(NAME_SERVER_bonus)
	@echo "✔ GOOD $(NAME_SERVER_bonus)"

$(LIBFT):
	@$(MAKE) -C $(LIB) -s

clean:
	@$(MAKE) -C $(LIB) clean
	@echo "Cleaned objects"

fclean: clean
	@rm -f $(NAME_CLIENT) $(NAME_SERVER)
	@rm -f $(NAME_CLIENT_bonus) $(NAME_SERVER_bonus)
	@$(MAKE) -C $(LIB) fclean
	@echo "Full clean done"

re: fclean all

.PHONY: all clean fclean re
