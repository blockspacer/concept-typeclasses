CPPFLAGS=-std=c++2a -fconcepts -Wall -Wextra -Werror -O2 -ggdb3

main: main.cpp
	g++-8 $(CPPFLAGS) -o main main.cpp

.PHONY: clean
clean:
	:
