CC=clang
LDFLAGS= -I/usr/local/lib:/usr/lib
TEST_CFLAGS= -lcheck
TARGET_OBJS=bin/build/**/*.o
TEST_TARGET_OBJS=bin/build/list/*.o

all: 
	mkdir -p bin/build/list
	$(CC) -c src/list/list.c $(LDFLAGS) -o bin/build/list/list.o

clean:
	rm -rf bin/*

test:
	$(CC) tests/list/list_test.c $(LDFLAGS) $(TEST_CFLAGS) $(TEST_TARGET_OBJS) -o bin/list_test

	./bin/list_test

install:
	ar -cvq bin/libkld.a bin/build/**/*.o
	sudo cp bin/libkld.a /usr/lib
