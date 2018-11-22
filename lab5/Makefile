CCXX = clang++
CFLAGSXX = -c -Wall -std=c++11

all: prog

prog: main.o rectangle.o trapeze.o rhombus.o
	$(CCXX) main.o rectangle.o trapeze.o rhombus.o -o prog
main.o: main.cpp stack.hpp stack.cpp stack_item.hpp stack_item.cpp rectangle.hpp trapeze.hpp rhombus.hpp figure.hpp
	$(CCXX) $(CFLAGSXX) main.cpp
rectangle.o: rectangle.cpp rectangle.hpp figure.hpp 
	$(CCXX) $(CFLAGSXX) rectangle.cpp
trapeze.o: trapeze.cpp trapeze.hpp figure.hpp 
	$(CCXX) $(CFLAGSXX) trapeze.cpp
rhombus.o: rhombus.cpp rhombus.hpp figure.hpp 
	$(CCXX) $(CFLAGSXX) rhombus.cpp
clean:
	rm -f *.o prog
