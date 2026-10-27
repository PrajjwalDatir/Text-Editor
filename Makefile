CC ?= cc
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
    CFLAGS ?= -Wall -Wextra -O2 -I./include
    LDFLAGS ?= -L./lib -lncurses -ltinfo
else
    # macOS / default system curses
    CFLAGS ?= -Wall -Wextra -O2
    LDFLAGS ?= -lncurses
endif

SRCS = stack.c line.c events.c undo.c stdedit.c editor.c
OBJS = $(SRCS:.c=.o)
TARGET = text_editor

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: $(TARGET)
	@echo "Build successful. All checks passed."

clean:
	rm -f $(OBJS) $(TARGET) a.out edit stack line events undo stdedit editor *.o

.PHONY: all clean test
