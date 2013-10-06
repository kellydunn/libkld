CC=clang
LDFLAGS= -I/usr/local/lib:/usr/lib
TEST_CFLAGS= -lcheck
TARGET_OBJS=bin/build/**/*.o
TEST_TARGET_OBJS=bin/build/list/*.o bin/build/vector/*.o bin/build/matrix/*.o bin/build/graph/*.o bin/build/tree/*.o bin/build/common/*.o

all: 
	mkdir -p bin/build/common bin/build/list bin/build/vector bin/build/matrix bin/build/graph bin/build/tree
	$(CC) -c src/common/common.c $(LDFLAGS) -o bin/build/common/common.o		
	$(CC) -c src/list/list.c $(LDFLAGS) -o bin/build/list/list.o	
	$(CC) -c src/vector/vector.c $(LDFLAGS) -o bin/build/vector/vector.o
	$(CC) -c src/matrix/matrix.c $(LDFLAGS) -o bin/build/matrix/matrix.o
	$(CC) -c src/graph/graph.c $(LDFLAGS) -o bin/build/graph/graph.o
	$(CC) -c src/tree/tree.c $(LDFLAGS) -o bin/build/tree/tree.o

clean:
	rm -rf bin
	rm -rf docs

test:
	$(CC) tests/common/common_test.c $(LDFLAGS) $(TEST_CFLAGS) $(TEST_TARGET_OBJS) -o bin/common_test
	$(CC) tests/list/list_test.c $(LDFLAGS) $(TEST_CFLAGS) $(TEST_TARGET_OBJS) -o bin/list_test
	$(CC) tests/vector/vector_test.c $(LDFLAGS) $(TEST_CFLAGS) $(TEST_TARGET_OBJS) -o bin/vector_test
	$(CC) tests/matrix/matrix_test.c $(LDFLAGS) $(TEST_CFLAGS) $(TEST_TARGET_OBJS) -o bin/matrix_test
	$(CC) tests/graph/graph_test.c $(LDFLAGS) $(TEST_CFLAGS) $(TEST_TARGET_OBJS) -o bin/graph_test
	$(CC) tests/tree/tree_test.c $(LDFLAGS) $(TEST_CFLAGS) $(TEST_TARGET_OBJS) -o bin/tree_test

	./bin/common_test
	./bin/list_test
	./bin/vector_test
	./bin/matrix_test
	./bin/graph_test
	./bin/tree_test

install:
	ar -cvq bin/libkld.a bin/build/**/*.o
	sudo cp bin/libkld.a /usr/lib

doc: 
	cldoc generate -- --output ./docs src/**/*
