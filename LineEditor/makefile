CFLAGS = -Wall -Wextra -std=c99

LineEditor.exe: LineEditor.o main.o
	gcc $(CFLAGS) -o LineEditor.exe LineEditor.o main.o

LineEditor.o: LineEditor.c LineEditor.h
	gcc $(CFLAGS) -c LineEditor.c

main.o: main.c LineEditor.h
	gcc $(CFLAGS) -c main.c

clean:
	rm -f *.o *.exe