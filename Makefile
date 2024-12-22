CC = gcc
CFLAGS = -Wall -g

all: calculator addition subtraction multiplication division saver

calculator: calculator.c
	$(CC) $(CFLAGS) -o calculator calculator.c

addition: addition.c
	$(CC) $(CFLAGS) -o addition addition.c

subtraction: subtraction.c
	$(CC) $(CFLAGS) -o subtraction subtraction.c

multiplication: multiplication.c
	$(CC) $(CFLAGS) -o multiplication multiplication.c

division: division.c
	$(CC) $(CFLAGS) -o division division.c

saver: saver.c
	$(CC) $(CFLAGS) -o saver saver.c

clean:
	rm -f calculator addition subtraction multiplication division saver results.txt
