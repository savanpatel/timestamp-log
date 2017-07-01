all: clean build-tests

default: all

clean:
	rm -rf optparser_test

build-tests:
	gcc -o optparser_test optparser_test.c

test: build-tests
	./optparser_test
