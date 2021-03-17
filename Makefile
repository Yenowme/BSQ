CFLAGS = -Wall -Wextra -Werror

SRCDIR = srcs
INCDIR = includes
TARGET = BSQ
SRCS = $(SRCDIR)/main.c $(SRCDIR)/read.c $(SRCDIR)/stdread.c $(SRCDIR)/valid.c $(SRCDIR)/string.c $(SRCDIR)/find_bsq.c $(SRCDIR)/util.c  $(SRCDIR)/util_2.c

OBJS = $(SRCS:.c=.o)

all: $(TARGET)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@ -I $(INCDIR)

$(TARGET): $(OBJS)
	gcc $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

lldb:
	gcc -g $(SRCS) -I $(INCDIR)

re: fclean all
