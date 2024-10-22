NAME_C = client

NAME_S = server

LIBFT = libft/libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = server.c 

SRCC = client.c 

OBJS = $(SRCS:.c=.o)

OBJC = $(SRCC:.c=.o)

all: $(NAME_C) $(NAME_S) $(LIBFT)

$(NAME_C): $(OBJC)
	cd libft && make
	$(CC) $(CFLAGS)  $(OBJC) -o $(NAME_C) $(LIBFT)

$(NAME_S): $(OBJS)
	cd libft && make
	$(CC) $(CFLAGS)  $(OBJS) -o $(NAME_S) $(LIBFT)

clean:
	cd libft && make clean
	rm -f  $(OBJS) $(OBJC)

fclean: clean
	cd libft && make fclean
	rm -f $(NAME_C) $(NAME_S) $(OBJS) $(OBJC)

re: fclean all