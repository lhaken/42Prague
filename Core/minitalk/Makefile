# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhaken <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 11:47:26 by lhaken            #+#    #+#              #
#    Updated: 2024/04/22 11:47:28 by lhaken           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
