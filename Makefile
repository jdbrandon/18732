CC=gcc
CFLAGS=
TARGS= client1 client2 client3 ascii2hex
all: $(TARGS)
client1: client1.o
	$(CC) -o client1 client1.c
client2: client2.o
	$(CC) -o client2 client2.c
client3: client3.o
	$(CC) -o client3 client3.c
ascii2hex: ascii2hex.o
	$(CC) -o ascii2hex ascii2hex.c
clean:
	rm *.o $(TARGS)
