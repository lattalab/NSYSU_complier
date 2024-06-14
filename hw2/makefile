all:	clean y.tab.c lex.yy.c
	gcc lex.yy.c y.tab.c -lfl -o a.out

y.tab.c:
	bison -y -d -v B103040045.y

lex.yy.c:
	flex B103040045.l

clean:
	rm -f a.out lex.yy.c y.tab.c y.tab.h y.output


