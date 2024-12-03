.PHONY: compile clean

compile: main.o functions.o
	@gcc -o shell main.o functions.o
main.o: main.c
	@gcc -c main.c
functions.o: functions.c
	@gcc -c functions.c
clean:
	@rm -f *.o shell
