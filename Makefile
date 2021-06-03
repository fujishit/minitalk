SERVER = server
CLIENT = client
NAME = $(SERVER) $(CLIENT)
LIB_DIR = mylibft/
LIBFT = libft.a

# Config
# ****************************************************************************

CC = gcc
CFLAGS = $(INCLUDE) #-Wall -Werror -Wextra
INCLUDE = -I includes -I $(LIB_DIR)includes/
DEBUG = -g -fsanitize=address
LIBFLAGS = -L $(LIB_DIR) -lft
# Source files
# ****************************************************************************

SERVER_DIR =		server/
SERVER_FILES	=	main.c
SERVER_SRCS = $(addprefix $(SERVER_DIR), $(SERVER_FILES))

CLIENT_DIR =		client/
CLIENT_FILES =		main.c \
					error.c
CLIENT_SRCS = $(addprefix $(CLIENT_DIR), $(CLIENT_FILES))

SRC_FILES =			$(SERVER_SRCS) \
					$(CLIENT_SRCS)

# addprefix
SRC_DIR = srcs/

OBJ_DIR = objs/
OBJS = $(SRC_FILES:%.c=$(OBJ_DIR)%.o)
CLIENT_OBJS = $(CLIENT_FILES:%.c=$(OBJ_DIR)CLIENT/%.o)
SERVER_OBJS = $(SERVER_FILES:%.c=$(OBJ_DIR)SERVER/%.o)

# Recipe
# ****************************************************************************

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIB_DIR)
	$(CC) $(CFLAGS) $(SERVER_OBJS) $(LIBFLAGS) -o server
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIBFLAGS) -o client

$(OBJS): $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)$(SERVER_DIR)
	mkdir -p $(OBJ_DIR)$(CLIENT_DIR)

clean:
	make clean -C $(LIB_DIR)
	rm -rf $(OBJ_DIR)
	rm -fr *.dSYM

fclean:
	make fclean -C $(LIB_DIR)
	rm -rf $(NAME) $(OBJ_DIR)
	rm -fr *.dSYM

re: fclean all
.PHONY: all clean fclean re
