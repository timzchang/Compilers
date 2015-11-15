CC=gcc

all: cminor

cminor: main.c token.c lex.yy.c scanner.l
	$(CC)  lex.yy.c token.c  main.c -o cminor


lex.yy.c: scanner.l
	flex --noyywrap scanner.l

.PHONY: clean

clean:
	rm lex.yy.c a.out cminor 
