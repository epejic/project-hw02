all: exe/test01.elf exe/test02.elf exe/test03.elf exe/test04.elf exe/test05.elf exe/test06.elf exe/test07.elf exe/test08.elf exe/test_dft.elf exe/test_idft.elf


exe/%.elf: src/%.o src/io.o src/cmplx.o
	gcc $^ -o $@ -lm

%.o: %.c
	gcc -c $< -o $@ -I inc/

clean:
	 src/*.o

