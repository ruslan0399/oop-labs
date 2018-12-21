#include "stack.hpp"
#include "queue.hpp"
#include "rectangle.hpp"
#include "trapeze.hpp"
#include "rhombus.hpp"
#include "remove_criteria_all.hpp"
#include "remove_criteria_by_value.hpp"

int main()
{
    Stack <Queue <Figure>, Figure> stack;
	
	std::cout << "Введите номер фигуры:" << std::endl;
	std::cout << "1 - Прямоугольник" << std::endl;
	std::cout << "2 - Трапеция" << std::endl;
	std::cout << "3 - Ромб" << std::endl;
	
	int n;
	while(std::cin >> n && n != 0)
	{
		switch(n)
		{
			case 1:
			{
				Rectangle *rect(new Rectangle);
				std::cin >> *rect;
				stack.insert_subitem(rect);
				break;
			}
			case 2:
			{
				Trapeze *trap(new Trapeze);
				std::cin >> *trap;
				stack.insert_subitem(trap);
				break;
			}
			case 3:
			{
				Rhombus *rhomb(new Rhombus);
				std::cin >> *rhomb;
				stack.insert_subitem(rhomb);
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
	for(auto i: stack)
	{
		std::cout << "Очередь:" << std::endl;
		for(auto j: *i)
			std::cout << *j << std::endl;
		std::cout << std::endl;
	}

	std::cout << "Введите площадь фигуры для удаления:" << std::endl;
	double square;
	std::cin >> square;
	RemoveCriteriaByValue<Figure> criteria(square);
	stack.remove_subitem(&criteria);
	std::cout << std::endl;

	std::cout << "Стек:" << std::endl;
	for(auto i: stack)
	{
		if(i->empty()) continue;
		std::cout << "Очередь:" << std::endl;
		for(auto j: *i)
			std::cout << *j << std::endl;
		std::cout << std::endl;
	}

	while(!stack.empty())
		stack.pop();
}
