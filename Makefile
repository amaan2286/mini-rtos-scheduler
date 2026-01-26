CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

all: mini_rtos

mini_rtos: src/main.c src/scheduler.c
	$(CC) $(CFLAGS) src/main.c src/scheduler.c -o mini_rtos

clean:
	rm -f mini_rtos
