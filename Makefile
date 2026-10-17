EXECUTABLE = network.out

CC = gcc
LDFLAGS = -lm
CFLAGS = -Wall -Wextra -Werror -Iinclude -O3
DEBUGCFLAGS = -Wall -Wextra -Iinclude -O0 -g3 -fsanitize=address,undefined

SOURCES = $(wildcard src/*.c)
OBJECTS = $(patsubst src/%.c, build/obj/%.o, $(SOURCES))
DEPENDENCIES = $(patsubst src/%.c,build/dependencies/%.d,$(SOURCES))


all : build/bin/$(EXECUTABLE)

debug : CFLAGS = $(DEBUGCFLAGS)
debug : LDFLAGS = -fsanitize=address,undefined -lm
debug : all



build :
		mkdir -p build/bin build/obj build/dependencies

build/bin/$(EXECUTABLE) : $(OBJECTS) | build
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

build/obj/%.o : src/%.c | build
	$(CC) $(CFLAGS) -MMD -MF build/dependencies/$*.d -c $< -o $@

clean:
	rm -rf build/

run:
	@./build/bin/$(EXECUTABLE)

rebuild: clean all

.PHONY: all build clean run debug rebuild

-include $(DEPENDENCIES)
