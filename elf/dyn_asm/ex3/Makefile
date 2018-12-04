bin/main: obj/main.o bin/lib.so
	ld -o bin/main obj/main.o bin/lib.so --dynamic-linker=/lib64/ld-linux-x86-64.so.2

bin/lib.so: obj/lib.o
	mkdir -p bin
	ld -o bin/lib.so -shared obj/lib.o

obj/lib.o: lib.asm
	mkdir -p obj
	nasm -felf64 -o obj/lib.o lib.asm

obj/main.o: main.asm
	mkdir -p obj
	nasm -felf64 -o obj/main.o main.asm

clean:
	rm -rf obj bin

.PHONY: clean

