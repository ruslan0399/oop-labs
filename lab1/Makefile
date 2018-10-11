all: prog

prog: main.o rectangle.o trapeze.o rhombus.o
	clang++ main.o rectangle.o trapeze.o rhombus.o -o prog
main.o: main.cpp rectangle.hpp trapeze.hpp rhombus.hpp figure.hpp
	clang++ -c main.cpp
rectangle.o: rectangle.cpp rectangle.hpp figure.hpp 
	clang++ -c rectangle.cpp
trapeze.o: trapeze.cpp trapeze.hpp figure.hpp
	clang++ -c trapeze.cpp
rhombus.o: rhombus.cpp rhombus.hpp figure.hpp
	clang++ -c rhombus.cpp
clean:
	rm -f *.o prog
