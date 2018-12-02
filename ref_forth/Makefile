ASM    = nasm
FLAGS  = -felf64
LINKER = ld

bin/main: obj/main.o obj/util.o
	mkdir -p bin
	$(LINKER) -o $@ $^

obj/main.o: src/main.asm src/macro.inc src/words.inc src/util.inc
	mkdir -p obj
	$(ASM) $(FLAGS) -o $@ $<

obj/util.o: src/util.asm src/util.inc
	mkdir -p obj
	$(ASM) $(FLAGS) -o $@ $<

clean:
	rm -rf bin obj

.PHONY: clean

