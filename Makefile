CC=gcc
LDFLAGS= -I/usr/local/lib:/usr/lib
TEST_CFLAGS= -lcheck
TARGET_OBJS=bin/build/**/*.o
TEST_TARGET_OBJS=bin/build/**/*.o

all: 
	mkdir -p bin/build/list
	$(CC) -c src/list/list.c $(LDFLAGS) $(CFLAGS) -o bin/build/list/list.o
clean:
	rm -rf bin/*
install:
	ar -cvq bin/libkld.a bin/build/**/*.o
	sudo cp bin/libkld.a /usr/lib
