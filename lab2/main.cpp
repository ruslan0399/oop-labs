#include "rstack.hpp"

int main()
{
    RStack stack;
	Rectangle rect;

	while(std::cin >> rect)
		stack.push(std::move(rect));

	std::cout << std::endl << stack << std::endl;

	while(!stack.empty())
		std::cout << stack.pop() << std::endl;
}
