#include "stack.hpp"
#include "rectangle.hpp"
#include "trapeze.hpp"
#include "rhombus.hpp"

int main()
{
    Stack stack;
	
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
				std::shared_ptr <Rectangle> rect(new Rectangle);
				std::cin >> *rect;
				stack.push(rect, n);
				break;
			}
			case 2:
			{
				std::shared_ptr <Trapeze> trap(new Trapeze);
				std::cin >> *trap;
				stack.push(trap, n);
				break;
			}
			case 3:
			{
				std::shared_ptr <Rhombus> rhomb(new Rhombus);
				std::cin >> *rhomb;
				stack.push(rhomb, n);
				break;
			}
			default:
			{
				std::cout << "Неверный номер фигуры" << std::endl;
				break;
			}
		}
	}

	std::cout << std::endl << stack << std::endl;

	while(!stack.empty())
		stack.pop();
}
