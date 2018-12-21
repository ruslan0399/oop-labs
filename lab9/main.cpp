#include "stack.hpp"
#include "queue.hpp"
#include "rectangle.hpp"
#include "trapeze.hpp"
#include "rhombus.hpp"
#include <random>
#include <future>
#include <functional>

int main()
{
    Stack <Figure> stack;
	typedef std::function<void(void)> command;
	Queue <command> queue;
	
	command cmd_insert = [&]()
	{
		std::cout << "Комманда: добавление фигур" << std::endl;

		std::default_random_engine gen;
		std::uniform_int_distribution<int> dist_n(1, 3);
		std::uniform_int_distribution<int> dist_s(1, 1000);

		for(int i = 0; i < 10; ++i)
		{
			switch(dist_n(gen))
			{
				case 1:
				{
					stack.push(std::shared_ptr<Figure>(new Rectangle(dist_s(gen), dist_s(gen))));
					break;
				}
				case 2:
				{
					stack.push(std::shared_ptr<Figure>(new Trapeze(dist_s(gen), dist_s(gen), dist_s(gen))));
					break;
				}
				case 3:
				{
					stack.push(std::shared_ptr<Figure>(new Rhombus(dist_s(gen), dist_s(gen))));
					break;
				}
			}
		}
		std::cout << std::endl;
	};

	command cmd_reverse = [&]()
	{
		std::cout << "Комманда: реверс стека" << std::endl;

		Stack <Figure> tmp;
		while(!stack.empty()) tmp.push(stack.pop_last());
		while(!tmp.empty()) stack.push(tmp.pop());
		std::cout << std::endl;
	};

	command cmd_print = [&]()
	{
		std::cout << "Комманда: печать стека" << std::endl;
		std::cout << "Стек:" << std::endl;
		for(auto i: stack) std::cout << *i << std::endl;
		std::cout << std::endl;
	};

	std::cout << "Введите номер комманды:" << std::endl;
	std::cout << "1 - Добавление 10 фигур" << std::endl;
	std::cout << "2 - Реверс стека" << std::endl;
	std::cout << "3 - Печать стека" << std::endl;
	
	int n;
	while(std::cin >> n)
	{
		switch(n)
		{
			case 1:
			{
				queue.push(std::shared_ptr<command>(&cmd_insert, [](command*) {}));
				break;
			}
			case 2:
			{
				queue.push(std::shared_ptr<command>(&cmd_reverse, [](command*) {}));
				break;
			}
			case 3:
			{
				queue.push(std::shared_ptr<command>(&cmd_print, [](command*) {}));
				break;
			}
			default:
			{
				std::cout << "Неверный номер комманды" << std::endl;
				break;
			}
		}
	}

	while(!queue.empty())
	{
		std::shared_ptr<command> cmd = queue.pop();
		std::future<void> ft = std::async(*cmd);
		ft.get();
	}

	while(!stack.empty())
		stack.pop();
}
