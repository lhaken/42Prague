NAME = minitalk
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: server client

server:
	$(CC) $(CFLAGS) server.c -o server

client:
	$(CC) $(CFLAGS) client.c -o client

clean:
	rm -f server client

fclean: clean

re: fclean all
