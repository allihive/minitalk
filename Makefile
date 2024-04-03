SERVER = server
CLIENT = client

CFLAGS = -Wall -Werror -Wextra
CC = cc
FLAGS = -Wall -Wextra -Werror -I$(PRINTF)/headers -L$(PRINTF) -lftprintf

PRINTF = ft_printf

all:
	@make -s -C $(PRINTF)
	@cc $(FLAGS) server.c -o $(SERVER)
	@cc $(FLAGS) client.c -o $(CLIENT)
	@echo "Server And Client Are Ready!"

clean:
	@make clean -s -C $(PRINTF)

fclean: clean
	@make fclean -s -C $(PRINTF)
	@rm -f $(SERVER) $(CLIENT)
	@echo "Server and Client Have Been Cleaned Successfully"

re: fclean all
