all: cminor
target = cminor

cminor: main.o decl.o param_list.o stmt.o expr.o type.o scanner.o parser.tab.o token.o symbol.o scope.o hash_table.o register.o
	gcc -g -O0 -gdwarf-2  main.o decl.o param_list.o stmt.o expr.o type.o scanner.o parser.tab.o token.o symbol.o scope.o hash_table.o register.o -o $(target)

%.o: %.c *.h parser.tab.h
	gcc -c -g -O0 -gdwarf-2 $< -o $@

scanner.c: scanner.l parser.tab.h
	flex -o scanner.c scanner.l

parser.tab.c parser.tab.h: parser.bison
	yacc -d -bparser -v parser.bison

# clean causes all intermediate files to be deleted.

clean:
	rm -f parser.tab.* parser.output scanner.c *.o calc $(target)
