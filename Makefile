CC = cc
CFLAGS = -Wall -Werror -Wextra -g
NAME_CLIENT = client
NAME_SERVER = server

LIB = Library/libft
LIBFT = $(LIB)/libft.a


all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(LIBFT)
	@$(CC) $(CFLAGS) Mandatory/client.c -L$(LIB) -lft -o $(NAME_CLIENT)
	@echo "✔ GOOD $(NAME_CLIENT)"

$(NAME_SERVER): $(LIBFT)
	@$(CC) $(CFLAGS) Mandatory/serveur.c -L$(LIB) -lft -o $(NAME_SERVER)
	@echo "✔ GOOD $(NAME_SERVER)"

$(LIBFT):
	@$(MAKE) -C $(LIB) -s

clean:
	@$(MAKE) -C $(LIB) clean
	@echo "Cleaned objects"

fclean: clean
	@rm -f $(NAME_CLIENT) $(NAME_SERVER)
	@$(MAKE) -C $(LIB) fclean
	@echo "Full clean done"

re: fclean all

.PHONY: all clean fclean re
