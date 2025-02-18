CFLAGS = -Wall -Wextra -std=c99

Huffman.exe: Huffman.o main.o
	gcc $(CFLAGS) -o Huffman.exe Huffman.o main.o

Huffman.o: Huffman.c Huffman.h
	gcc $(CFLAGS) -c Huffman.c

main.o: main.c Huffman.h
	gcc $(CFLAGS) -c main.c

clean:
	rm -f *.o *.exe