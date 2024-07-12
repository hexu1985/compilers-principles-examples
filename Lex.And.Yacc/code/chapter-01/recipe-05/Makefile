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

PROGS = ch1-05

.PHONY: all
all: $(PROGS)
	@echo "build OK!"

.PHONY: clean
clean:
	$(RM) $(PROGS) *.o lex.yy.* *.tab.*
	@echo "clean OK!"

$(PROGS): ch1-05.l ch1-05.y
	flex ch1-05.l
	bison -d ch1-05.y
	gcc -c -g lex.yy.c ch1-05.tab.c
	gcc -o ch1-05 lex.yy.o ch1-05.tab.o -lfl

