NAME = minitalk
SERVER_NAME = server
CLIENT_NAME = client

CFLAGS = -Wall -Werror -Wextra 

# FLAGS = -Wall -Wextra -Werror -I
#$(PRINTF)/headers -L$(PRINTF) -lftprintf

LIBFT_DIR = ./libft
LIBFT = ./libft/libft.a

SERVER_C = server.c
CLIENT_C = client.c

all: $(NAME)

$(NAME): $(LIBFT) $(SERVER_NAME) $(CLIENT_NAME)
	@echo "Server and Client are ready"

$(SERVER_NAME): $(SERVER_C) $(LIBFT)
	cc $(CFLAGS) -o $@ $(SERVER_C) -L$(LIBFT_DIR) -lft

$(CLIENT_NAME): $(CLIENT_C) $(LIBFT)
	cc $(CFLAGS) -o $@ $(CLIENT_C) -L$(LIBFT_DIR) -lft

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	@make clean -s -C $(LIBFT_DIR)
	@rm -f $(SERVER_O) $(CLIENT_O)
	
fclean: clean
	@make fclean -s -C $(LIBFT_DIR)
	@rm -f $(SERVER_NAME) $(CLIENT_NAME)
	@echo "Server and Client Have Been Cleaned Successfully"

re: fclean all

