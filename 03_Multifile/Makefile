GENERATES = prog prog-a prog-so README
TRASH = *.a *.o *.so *.txt

all:	README prog prog-a prog-so

prog:	prog.o const.o fun.o

prog-a:	prog.o liboutput_static.a
		cc -L. $< -loutput_static -o $@

prog-so:	prog.o liboutput.so
		cc -L. $< -loutput -o $@

README:	prog
		./$< 2> $@

liboutput_static.a:	const.o fun.o
		ar -rcs $@ $^

liboutput.so:	const.o fun.o
		cc -shared $^ -o $@

fun.o:	outlib.h

test:	prog prog-a prog-so
		./prog > file1.txt
		./prog-a > file2.txt
		$ LD_LIBRARY_PATH=`pwd` ./prog-so > file3.txt
		cmp file1.txt file2.txt
		cmp file1.txt file3.txt

		./prog one > file1.txt
		./prog-a one > file2.txt
		$ LD_LIBRARY_PATH=`pwd` ./prog-so one > file3.txt
		cmp file1.txt file2.txt
		cmp file1.txt file3.txt

		./prog one two three > file1.txt
		./prog-a one two three > file2.txt
		$ LD_LIBRARY_PATH=`pwd` ./prog-so one two three > file3.txt
		cmp file1.txt file2.txt
		cmp file1.txt file3.txt

clean:
		rm -f $(TRASH)

distclean:	clean
		rm -f $(GENERATES)
