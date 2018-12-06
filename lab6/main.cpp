#include "stack.hpp"
#include "rectangle.hpp"
#include "trapeze.hpp"
#include "rhombus.hpp"

//allocator_block.cpp	std::cout << "Память инициализирована" << std::endl;
int main()
{
    Stack <Figure> stack;
	
	std::cout << "Введите номер фигуры:" << std::endl;
	std::cout << "1 - Прямоугольник" << std::endl;
	std::cout << "2 - Трапеция" << std::endl;
	std::cout << "3 - Ромб" << std::endl;
	
	int n;
	while(std::cin >> n)
	{
		switch(n)
		{
			case 1:
			{
				Rectangle *rect(new Rectangle);
				std::cin >> *rect;
				std::shared_ptr <Figure> fig(rect);
				stack.push(std::move(fig));
				break;
			}
			case 2:
			{
				Trapeze *trap(new Trapeze);
				std::cin >> *trap;
				std::shared_ptr <Figure> fig(trap);
				stack.push(std::move(fig));
				break;
			}
			case 3:
			{
				Rhombus *rhomb(new Rhombus);
				std::cin >> *rhomb;
				std::shared_ptr <Figure> fig(rhomb);
				stack.push(std::move(fig));
				break;
			}
			default:
			{
				std::cout << "Неверный номер фигуры" << std::endl;
				break;
			}
		}
		std::cout << std::endl;
	}

	std::cout << "Стек:" << std::endl;
	for(auto i: stack) std::cout << *i << std::endl;
	std::cout << std::endl;

	while(!stack.empty())
		stack.pop();
}
