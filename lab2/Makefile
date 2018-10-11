all: prog

prog: main.o rstack.o rstack_item.o rectangle.o
	clang++ main.o rstack.o rstack_item.o rectangle.o -o prog
main.o: main.cpp rstack.hpp rstack_item.hpp rectangle.hpp figure.hpp
	clang++ -c main.cpp
rstack.o: rstack.cpp rstack.hpp rstack_item.hpp rectangle.hpp figure.hpp
	clang++ -c rstack.cpp
rstack_item.o: rstack_item.cpp rstack_item.hpp rectangle.hpp figure.hpp
	clang++ -c rstack_item.cpp
rectangle.o: rectangle.cpp rectangle.hpp figure.hpp 
	clang++ -c rectangle.cpp
clean:
	rm -f *.o prog
