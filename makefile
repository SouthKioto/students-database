CC       := gcc
CFLAGS   := -std=c17 -Wall -Wextra -Werror -pedantic -D_FORTIFY_SOURCE=2 -O1
CPPFLAGS := -Iinclude -MMD -MP
LDFLAGS  :=
LDLIBS   :=

SRC      := src
OBJ      := bin/obj
TARGET   := main

SRCS     := main.c $(wildcard $(SRC)/*.c)
OBJS     := $(SRCS:%.c=$(OBJ)/%.o)
DEPS     := $(OBJS:.o=.d)

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@ $(LDLIBS)

$(OBJ)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	$(RM) -r bin $(TARGET)

-include $(DEPS)
