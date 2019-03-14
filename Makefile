.POSIX:

CFLAGS=-D_XOPEN_SOURCE=700 -g

all: yacc liby.a

yacc: yacc.c

liby.a: liby.a(liby.o)

clean:
	rm -f yacc *.o *.a
