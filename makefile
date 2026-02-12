CC := clang
CFLAGS := -std=c99 -Wall -Wextra
DEBUG := -g -fsanitize=address

TARGET := main

build: bin/$(TARGET)

bin/%: src/core/%.c
	$(CC) $(CFLAGS) $(DEBUG) -o $@ $<
