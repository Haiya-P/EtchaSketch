INCLUDE := -I ~/include
LDFLAGS := -L ~/lib -lsense -lm

all: compile 

clean:
	rm -rf *.o
	rm -rf sketch

main.o: main.c project.h
	cc -c main.c $(INCLUDE)

input.o: input.c project.h
	cc -c input.c $(INCLUDE)

output.o: output.c project.h
	cc -c output.c $(INCLUDE)

compile: main.o input.o output.o
	cc -o sketch main.o input.o output.o $(LDFLAGS)

run:
	./sketch
