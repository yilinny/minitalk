S_NAME = server
C_NAME = client
FLAGS = -Wall -Werror -Wextra
S_FILES = server.c 
C_FILES = client.c

.PHONY: clean fclean re

all: $(S_NAME) $(C_NAME)

$(S_NAME) :$(S_FILES)
	cc -$(FLAGS) $(S_FILES) -o $(S_NAME)

$(C_NAME) :$(C_FILES)
	cc -$(FLAGS) $(C_FILES) -o $(S_NAME)

fclean: clean 
	rm -f $(S_NAME) $(C_NAME)

clean:
	rm -f $(S_NAME) $(C_NAME)

re: fclean all