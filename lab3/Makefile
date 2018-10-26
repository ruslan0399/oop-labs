all: prog

prog: main.o stack.o stack_item.o rectangle.o trapeze.o rhombus.o
	clang++ main.o stack.o stack_item.o rectangle.o trapeze.o rhombus.o -o prog
main.o: main.cpp stack.hpp rectangle.hpp
	clang++ -c main.cpp
stack.o: stack.cpp stack.hpp stack_item.hpp
	clang++ -c stack.cpp
stack_item.o: stack_item.cpp stack_item.hpp figure.hpp
	clang++ -c stack_item.cpp
rectangle.o: rectangle.cpp rectangle.hpp figure.hpp 
	clang++ -c rectangle.cpp
trapeze.o: trapeze.cpp trapeze.hpp figure.hpp 
	clang++ -c trapeze.cpp
rhombus.o: rhombus.cpp rhombus.hpp figure.hpp 
	clang++ -c rhombus.cpp
clean:
	rm -f *.o prog
