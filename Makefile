SRCS= 	ft_itoa_base.c ft_printf.c ft_uitoa_base.c ft_utils.c

INCLUDES= ft_printf.h
NAME= libftprintf.a
AR= ar -rcs
CC= cc
OBJ_DIR= objs
OBJS= $(SRCS:.c=.o)
OBJS := $(addprefix $(OBJ_DIR)/, $(OBJS))
RM= rm -f
FLAGS= -Wall -Werror -Wextra

$(OBJ_DIR)/%.o : %.c $(INCLUDES) Makefile
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@ -I $(INCLUDES)

all: $(NAME) Makefile

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)
	$(RM) $(BONUS_OBJS)
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
