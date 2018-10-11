#include "rectangle.hpp"
#include "trapeze.hpp"
#include "rhombus.hpp"

int main()
{
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
				Figure *rect = new Rectangle(std::cin);
				rect->Print();
				std::cout << "Площадь прямоуглольника: " << rect->Square() << std::endl;
				delete rect;
				break;
			}
			case 2:
			{
				Figure *trap = new Trapeze(std::cin);
				trap->Print();
				std::cout << "Площадь трапеции: " << trap->Square() << std::endl;
				delete trap;
				break;
			}
			case 3:
			{
				Figure *rhomb = new Rhombus(std::cin);
				rhomb->Print();
				std::cout << "Площадь ромба: " << rhomb->Square() << std::endl;
				delete rhomb;
				break;
			}
			default:
			{
				std::cout << "Неверный номер фигуры" << std::endl;
				break;
			}
		}
	}
}
