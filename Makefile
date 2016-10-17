CC=gcc
LD=gcc
LEX=flex
YACC=bison
EXE=vsl
CFLAGS=-Wall -Werror -Iinc -std=c99 -Wno-unused-function
LDFLAGS=
YFLAGS=-yv
LFLAGS=
OBJFILES=obj/lexer.o obj/y.tab.o obj/ast.o obj/utils.o

vsl: lexer parser $(OBJFILES)
	gcc -o $(EXE) $(OBJFILES) $(LDFLAGS)

lexer: src/lexer.l
	$(LEX) -osrc/lexer.yy.c $< $(LFLAGS)

parser: src/parser.y
	$(YACC) --defines=src/y.tab.h -osrc/y.tab.c $< $(YFLAGS)

obj/%.o: src/%.c
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean
clean:
	rm src/*.yy.*
	rm src/*.tab.*
	rm src/y.output
	rm obj/*
	rm $(EXE)
