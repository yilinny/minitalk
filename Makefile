CC = cc
CFLAGS = -Wall -Wextra -Werror

S_NAME = server
C_NAME = client
S_BONUS_NAME = server_bonus
C_BONUS_NAME = client_bonus

S_SRC = server.c
C_SRC = client.c
S_BONUS_SRC = server_bonus.c
C_BONUS_SRC = client_bonus.c

S_OBJ = $(S_SRC:.c=.o)
C_OBJ = $(C_SRC:.c=.o)
S_BONUS_OBJ = $(S_BONUS_SRC:.c=.o)
C_BONUS_OBJ = $(C_BONUS_SRC:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

HDR = minitalk.h
HDR_BONUS = minitalk_bonus.h

.PHONY: all bonus clean fclean re

all: $(S_NAME) $(C_NAME)

bonus: $(S_BONUS_NAME) $(C_BONUS_NAME)

$(S_NAME): $(S_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(S_OBJ) $(LIBFT) -o $@

$(C_NAME): $(C_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(C_OBJ) $(LIBFT) -o $@

$(S_BONUS_NAME): $(S_BONUS_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(S_BONUS_OBJ) $(LIBFT) -o $@

$(C_BONUS_NAME): $(C_BONUS_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(C_BONUS_OBJ) $(LIBFT) -o $@

%.o: %.c $(HDR) $(HDR_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(S_OBJ) $(C_OBJ) $(S_BONUS_OBJ) $(C_BONUS_OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(S_NAME) $(C_NAME) $(S_BONUS_NAME) $(C_BONUS_NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all
