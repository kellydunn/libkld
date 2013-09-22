CC=clang
LDFLAGS= -I/usr/local/lib:/usr/lib
TEST_CFLAGS= -lcheck
TARGET_OBJS=bin/build/**/*.o
TEST_TARGET_OBJS=bin/build/list/*.o bin/build/vector/*.o bin/build/matrix/*.o

all: 
	mkdir -p bin/build/list bin/build/vector bin/build/matrix
	$(CC) -c src/list/list.c $(LDFLAGS) -o bin/build/list/list.o	
	$(CC) -c src/vector/vector.c $(LDFLAGS) -o bin/build/vector/vector.o
	$(CC) -c src/matrix/matrix.c $(LDFLAGS) -o bin/build/matrix/matrix.o

clean:
	rm -rf bin
	rm -rf docs

test:
	$(CC) tests/list/list_test.c $(LDFLAGS) $(TEST_CFLAGS) $(TEST_TARGET_OBJS) -o bin/list_test
	$(CC) tests/vector/vector_test.c $(LDFLAGS) $(TEST_CFLAGS) $(TEST_TARGET_OBJS) -o bin/vector_test
	$(CC) tests/matrix/matrix_test.c $(LDFLAGS) $(TEST_CFLAGS) $(TEST_TARGET_OBJS) -o bin/matrix_test

	./bin/list_test
	./bin/vector_test
	./bin/matrix_test

install:
	ar -cvq bin/libkld.a bin/build/**/*.o
	sudo cp bin/libkld.a /usr/lib

doc: 
	cldoc generate -- --output ./docs src/**/*
