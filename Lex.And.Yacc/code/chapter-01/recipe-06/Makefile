# Makefile

LEX = flex
RMR = rm -rf
RM = rm -f
CC = gcc

VPATH = 
CFLAGS = -Wall -g -DDEBUG 
INCLUDE = 
LDFLAGS = -lfl
LDPATH = 

PROGS = ch1-06

.PHONY: all
all: $(PROGS)
	@echo "build OK!"

.PHONY: clean
clean:
	$(RM) $(PROGS) *.o lex.yy.* *.tab.*
	@echo "clean OK!"

$(PROGS): ch1-06.l ch1-06.y
	flex ch1-06.l
	bison -d ch1-06.y
	gcc -c -g lex.yy.c ch1-06.tab.c
	gcc -o ch1-06 lex.yy.o ch1-06.tab.o -lfl

