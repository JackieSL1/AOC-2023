CC=gcc
CFLAGS=-g -Wall
FILES=trebuchet_1 trebuchet_2

all: $(FILES)

%: %.c
	$(CC) $(CFLAGS) $< -o  $@
clean:
	rm $(FILES)

