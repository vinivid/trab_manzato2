CC=gcc
CFLAGS= -Wall -Wextra -Werror -g -fsanitize=address 
OBJS= main.c ordenacao.c 
DEPS= ordenacao.h 

all: $(DEPS)
	$(CC) $(CFLAGS) $(OBJS) -o koala

run: 
	./koala