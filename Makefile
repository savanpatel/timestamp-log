default: all

all: clean make-timestamp

clean:
	rm -rf timestamp

make-timestamp:
	gcc timestamp.c -o timestamp
