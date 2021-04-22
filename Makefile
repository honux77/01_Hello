hello.nes: crt0.o hello.o
	ld65 -C nrom_32k_vert.cfg -o hello.nes crt0.o hello.o nes.lib -Ln labels.txt
hello.s: hello.c
	cc65 -Oirs hello.c --add-source
crt0.o: crt0.s
	ca65 crt0.s
hello.o: hello.s
	ca65 hello.s -g
clean:
	rm -rf *.o hello.s
