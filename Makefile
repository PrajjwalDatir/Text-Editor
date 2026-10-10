CC ?= cc
CFLAGS ?= -Wall -Wextra -O2
LDFLAGS ?= -lncurses

SRCS = stack.c line.c events.c undo.c stdedit.c editor.c
OBJS = $(SRCS:.c=.o)
TARGET = text_editor

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET) a.out edit stack line events undo stdedit editor *.o

.PHONY: all clean
