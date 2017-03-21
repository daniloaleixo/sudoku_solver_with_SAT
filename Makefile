CC = gcc
CFLAGS = -Wall -ansi -g
LFLAGS = -lm
OUT = sudoku
IN = Sudoku.c

all: $(OUT)

clean: 
	rm -f sudoku.o $(OUT)

$(OUT): sudoku.o
	$(CC) sudoku.o $(CFLAGS) -o $(OUT)


sudoku.o: $(IN)
	$(CC) $(IN) $(CFLAGS) $(LFLAGS) -c -o sudoku.o
