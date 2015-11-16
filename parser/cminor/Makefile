all: cminor
target = cminor

cminor: main.o decl.o param_list.o stmt.o expr.o type.o scanner.o parser.tab.o token.o symbol.o scope.o hash_table.o
	gcc main.o decl.o param_list.o stmt.o expr.o type.o scanner.o parser.tab.o token.o symbol.o scope.o hash_table.o -o $(target)

%.o: %.c *.h parser.tab.h
	gcc -c $< -o $@

scanner.c: scanner.l parser.tab.h
	flex -o scanner.c scanner.l

parser.tab.c parser.tab.h: parser.bison
	yacc -d -bparser -v parser.bison

# clean causes all intermediate files to be deleted.

clean:
	rm -f parser.tab.* parser.output scanner.c *.o calc $(target)
