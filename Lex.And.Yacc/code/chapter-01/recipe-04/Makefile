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

PROGS = ch1-04

.PHONY: all
all: $(PROGS)
	@echo "build OK!"

.PHONY: clean
clean:
	$(RM) $(PROGS) *.o *.l.c
	@echo "clean OK!"

%.l.c:%.l
	$(LEX) -o $@ $<

$(PROGS):%:%.l.c
	$(CC) -o $@ $^ $(LDFLAGS) $(LDPATH)

