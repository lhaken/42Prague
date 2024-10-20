NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = .
OPSDIR = ./ops
UTLDIR = ./utils

HEADERS = $(SRCDIR)/push_swap.h $(OPSDIR)/operations.h $(UTLDIR)/utils.h

SRC = $(SRCDIR)/main.c $(OPSDIR)/push.c $(OPSDIR)/reverse_rotate.c $(OPSDIR)/rotate.c $(OPSDIR)/write_op.c $(OPSDIR)/swap.c $(UTLDIR)/errors.c $(UTLDIR)/lib1.c $(UTLDIR)/lib2.c $(UTLDIR)/struct_management.c $(UTLDIR)/utils1.c $(UTLDIR)/utils2.c $(UTLDIR)/utils3.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
