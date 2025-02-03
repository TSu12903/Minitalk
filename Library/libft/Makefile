# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcybak <tcybak@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 10:12:04 by tcybak            #+#    #+#              #
#    Updated: 2025/01/14 17:08:12 by tcybak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AR = ar rcs
CC = cc 
CFLAGS = -Wall -Werror -Wextra
NAME= libft.a
SRC= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c\
ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c\
ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c\
ft_substr.c ft_toupper.c ft_tolower.c ft_printf.c check_p.c check_u_i.c check_x_X.c check_u.c\
check_s.c untils.c ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c\
ft_lstdelone_bonus.c ft_lstadd_back_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c\
get_next_line.c ft_atol.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -c $(SRC) $(CFLAGS)
	@$(AR) $(NAME) $(OBJ)
	
clean:
	@rm -f $(OBJ)
fclean: clean
	@rm -f $(NAME)
re: fclean all

.PHONY : all clean fclean re
