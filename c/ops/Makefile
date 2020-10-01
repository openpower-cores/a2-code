.RECIPEPREFIX = !
CC = gcc
CFLAGS = -std=gnu99 -mno-vsx -nostdlib
DEPS = ops.h ./a2lib/a2lib.h ./printf/printf.h

SRC = ops.c ./a2lib/a2lib.c ./printf/printf.c

ops: $(SRC) $(DEPS)
!  $(CC) $(CFLAGS) -I./a2lib -I./printf -o ops $(SRC) --entry main

