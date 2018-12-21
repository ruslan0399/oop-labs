CCXX = clang++
CFLAGSXX = -c -Wall -std=c++11

all: prog

prog: rectangle.o trapeze.o rhombus.o allocation_block.o main.o
	$(CCXX) -lpthread rectangle.o trapeze.o rhombus.o allocation_block.o main.o -o prog
main.o: main.cpp stack.hpp stack.cpp stack_item.hpp stack_item.cpp queue.hpp queue.cpp queue_item.hpp queue_item.cpp rectangle.hpp trapeze.hpp rhombus.hpp figure.hpp
	$(CCXX) $(CFLAGSXX) main.cpp
allocation_block.o: allocation_block.hpp allocation_block.cpp queue.hpp queue.cpp queue_item.hpp queue_item.cpp 
	$(CCXX) $(CFLAGSXX) allocation_block.cpp
rectangle.o: rectangle.cpp rectangle.hpp figure.hpp 
	$(CCXX) $(CFLAGSXX) rectangle.cpp
trapeze.o: trapeze.cpp trapeze.hpp figure.hpp 
	$(CCXX) $(CFLAGSXX) trapeze.cpp
rhombus.o: rhombus.cpp rhombus.hpp figure.hpp 
	$(CCXX) $(CFLAGSXX) rhombus.cpp
clean:
	rm -f *.o prog
