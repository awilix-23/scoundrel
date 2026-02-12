CC := clang
CFLAGS := -std=c99 -Wall -Wextra -Isrc
DEBUG := -g -fsanitize=address

CORE_SRCS := $(wildcard src/core/*.c)
CORE_OBJS := $(patsubst src/core/%.c, build/core/%.o, $(CORE_SRCS))

# SDL_SRCS := $(wildcard src/sdl/*.c)
# SDL_OBJS := $(patsubst src/sdl/%.c, build/sdl/%.o, $(SDL_SRCS))

TARGET := main
################################################################################
debug: CFLAGS += $(DEBUG)
debug: all

all: $(addprefix bin/, $(TARGET))

bin/%: src/%.c $(CORE_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

build_dir:
	mkdir -p build/core build/sdl

build/core/%.o: src/core/%.c | build_dir
	$(CC) $(CFLAGS) -c $< -o $@

# build/sdl/%.o: src/sdl/%.c | build_dir
# 	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build

.PHONY: debug all clean
