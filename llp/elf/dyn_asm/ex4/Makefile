bin/main: obj/main.o bin/lib.so
	gcc -v -o bin/main obj/main.o bin/lib.so

bin/lib.so: obj/lib.o
	mkdir -p bin
	gcc -v -o bin/lib.so -shared obj/lib.o

obj/lib.o: lib.asm
	mkdir -p obj
	nasm -felf64 -o obj/lib.o lib.asm

obj/main.o: main.c
	mkdir -p obj
	gcc -v -o obj/main.o -std=c99 -pedantic-errors -Wall -Werror -c main.c

clean:
	rm -rf obj bin

.PHONY: clean

