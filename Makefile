CC ?= gcc
CFLAGS := -g3 -std=c17 -Wall -Werror -Wpedantic

.PHONY: build

build:
	stat build &> /dev/null || mkdir build
	$(CC) $(CFLAGS) src/day1.c -o build/day1


