CC = cc
CFLAGS = -Wall -Werror -Wextra -g
NAME = Minitalk

LIBFT = Library/libft/libft.a
LIB = Library/libft

SRC = Mandatory/

SRC_BONUS = bonus/

OBJDIR = obj

OBJ = $(addprefix $(OBJDIR)/,$(SRC:.c=.o))
OBJ_BONUS = $(addprefix $(OBJDIR)/,$(SRC_BONUS:.c=.o))

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "✔ GOOD $(NAME)"

bonus: $(OBJ_BONUS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) -o $(NAME)
	@echo "✔ GOOD $(NAME)"

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(LIBFT):
	@$(MAKE) -C $(LIB) -s

$(MLX):
	@$(MAKE) -C $(MLXDIR) -s

clean:
	@rm -rf $(OBJDIR)
	@$(MAKE) -C $(LIB) clean
	@echo "Cleaned objects"

fclean: clean
	@rm -f $(NAME) $(BONUS)
	@$(MAKE) -C $(LIB) fclean
	@echo "Full clean done"

re: fclean all

.PHONY: all bonus clean fclean re
