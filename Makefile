CPPFLAGS=-std=c++2a -fconcepts -Wall -Wextra -Werror -O2 -ggdb3

main: main.o
	g++ -o main main.o

main.o: main.cpp *.h
	g++-8 $(CPPFLAGS) -c main.cpp

.PHONY: clean
clean:
	rm -f main.o main
