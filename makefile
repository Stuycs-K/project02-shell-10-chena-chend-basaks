.PHONY: compile clean

compile: main.o
	@gcc -o shell main.o
main.o:
	@gcc -c main.c
clean:
	@rm -f *.o shell
