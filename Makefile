CC=gcc
CFLAGS= -Wall -Wextra -Werror 
OBJS= main.c ordenacao.c 
DEPS= ordenacao.h 

all: $(DEPS)
	$(CC) $(CFLAGS) $(OBJS) -o ordenador

run: 
	./ordenador