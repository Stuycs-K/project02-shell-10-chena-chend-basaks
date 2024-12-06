.PHONY: compile clean

compile: functions.o main.o 
	@gcc -o shell functions.o main.o
main.o: main.c functions.h
	@gcc -c main.c
functions.o: functions.c functions.h
	@gcc -c functions.c
clean:
	@rm -f *.o shell
